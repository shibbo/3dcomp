import glob, math, nso, os, sys
from colorama import Fore, Style
from capstone import *
from capstone.arm64 import *
from elftools.elf.elffile import ELFFile
import time
import helpers

LIBRARIES = ["ActionLibrary", "agl", "eui", "nn", "sead"]

def truncate(number, digits) -> float:
    stepper = 10.0 ** digits
    return math.trunc(stepper * number) / stepper

def genJSON(value, filename, tag_name, color):
    # generate our JSON for the tags on the github page
    json = []
    json.append("{\n")
    json.append("\t\"schemaVersion\": 1,\n")
    json.append(f"\t\"label\": \"{tag_name}\",\n")
    json.append(f"\t\"message\": \"{truncate(value, 4)}%\",\n")
    json.append(f"\t\"color\": \"{color}\"\n")
    json.append("}")

    with open(f"data/{filename}.json", "w") as w:
        w.writelines(json)

def genProgress():
    done_size = 0
    TOTAL_GAME_SIZE = 0xA0F5A0
    total_funcs = 0
    done_funcs = 0

    nm_minor_funcs = 0
    nm_minor_funcs_size = 0
    nm_major_funcs = 0
    nm_major_funcs_size = 0

    with open("data/main.map", "r") as f:
        csvData = f.readlines()

    for c in csvData:
        spl = c.split("=")
        isDone = spl[3].replace("\n", "")
        total_funcs += 1
        
        if isDone == "true":
            funcSize = int(spl[2], 16)
            done_size = done_size + funcSize
            done_funcs += 1
        elif isDone == "minor":
            funcSize = int(spl[2], 16)
            nm_minor_funcs_size = nm_minor_funcs_size + funcSize
            nm_minor_funcs += 1
        elif isDone == "major":
            funcSize = int(spl[2], 16)
            nm_major_funcs_size = nm_major_funcs_size + funcSize
            nm_major_funcs += 1

    prog = (done_size / TOTAL_GAME_SIZE) * 100.0
    prog_minor = (nm_minor_funcs_size / TOTAL_GAME_SIZE) * 100.0
    prog_major = (nm_major_funcs_size / TOTAL_GAME_SIZE) * 100.0
    prog_total = prog + prog_minor + prog_major
    total_size = done_size + nm_minor_funcs_size + nm_major_funcs_size
    func_prog = (done_funcs / total_funcs) * 100.0
    print(f"Functions: {truncate(func_prog, 4)}% [{done_funcs} / {total_funcs}]")
    print(f"{Fore.BLUE}decompiled:{Style.RESET_ALL} {truncate(prog_total, 4)}% [{total_size} / {TOTAL_GAME_SIZE}]")
    print(f"{Fore.GREEN}matching:{Style.RESET_ALL} {truncate(prog, 4)}% [{done_size} / {TOTAL_GAME_SIZE}]")
    print(f"{Fore.YELLOW}non-matching (minor):{Style.RESET_ALL} {truncate(prog_minor, 4)}% [{nm_minor_funcs_size} / {TOTAL_GAME_SIZE}]")
    print(f"{Fore.RED}non-matching (major):{Style.RESET_ALL} {truncate(prog_major, 4)}% [{nm_major_funcs_size} / {TOTAL_GAME_SIZE}]")
    

    print("Generating JSON...")
    genJSON(func_prog, "decompiled", "decompiled", "blue")

objs_to_check = []
funcs_to_check = []

with open("data\\changed.txt", "r") as f:
    lines = f.readlines()

    for line in lines:
        objs_to_check.append(line.strip("\n"))

if len(objs_to_check) == 0:
    print("There are no functions to check.")
    sys.exit(1)

for obj in objs_to_check:
    with open(obj, "rb") as input:
        elf_file = ELFFile(input)
        symtab = elf_file.get_section_by_name('.symtab')

        for symbol in symtab.iter_symbols():
            section = symbol['st_shndx']
            if isinstance(section, int) and symbol.name != '':
                section_name = elf_file.get_section(section).name

                if section_name.startswith('.text'):
                    if not symbol.name.startswith("$"):
                        funcs_to_check.append(symbol.name)

if "-prog" in sys.argv:
    genProgress()
    sys.exit(1)

start = time.time()

printDiff = True
isChanged = False

if "-no-diff" in sys.argv:
    printDiff = False

for sym in funcs_to_check:
    print(f"{Fore.BLUE}{sym}{Style.RESET_ALL} =================================================")
    # first let's see if our symbol even exists somewhere
    path = helpers.getModule("map", sym)

    if path == "":
        for lib in LIBRARIES:
            path = helpers.getModule(f"lib/{lib}/map", sym)

            if path != "":
                break

    if path == "":
        print("Unable to find symbol.")
        continue

    functionSize, functionAddr = helpers.getFunctionSizeAndAddr(sym)
    funcData = helpers.getFunctionData(functionAddr, functionSize)
    capstone_inst = Cs(CS_ARCH_ARM64, CS_MODE_ARM + CS_MODE_LITTLE_ENDIAN)
    capstone_inst.detail = True
    capstone_inst.imm_unsigned = False

    if funcData == b'':
        print("Failed to fetch function data.")
        continue

    error_count = 0
    warning_count = 0

    original_instrs = list(capstone_inst.disasm(funcData, 0))

    with open(path, "rb") as f:
        elf = f

        elf_file = ELFFile(elf)
        symtab = elf_file.get_section_by_name('.symtab')

        if symtab.get_symbol_by_name(sym) is None:
            print("Could not find symbol in object file. This may be caused by the code not being compiled, the function being in the wrong C++ source file or the function signature being wrong.")
            sys.exit(1)

        compiled_symbol = symtab.get_symbol_by_name(sym)[0]
        custom_offset = compiled_symbol["st_value"]
        custom_size = compiled_symbol['st_size']
        text = elf_file.get_section_by_name(f".text.{sym}")

        constructor_swap = False

        if text is None:
            # it is very possible that we are dealing with a C1 / C2 swap...
            # for some reason, llvm-objdump dumps our symbols incorrectly
            # so the changes of the symbol being present in the object and being a ctor makes it possible we are seeing one of these swaps
            print("Possible constructor swap?")
            if "C1E" in sym:
                sym = sym.replace("C1E", "C2E")
                constructor_swap = True
            elif "C2E" in sym:
                sym = sym.replace("C2E", "C1E")
                constructor_swap = True
            
            # now let's try again
            text = elf_file.get_section_by_name(f".text.{sym}")

            if text is None:
                print("Could not find function in text data.")
                sys.exit(1)

        custom_data = text.data()[custom_offset:custom_offset + custom_size]
        custom_instructions = list(capstone_inst.disasm(custom_data, 0))

    orig_length = len(list(original_instrs))
    cust_length = len(list(custom_instructions))

    if orig_length != cust_length:
        print("Functions are different sizes.")
        continue

    instr_equal = True
    regs_equal = True

    # did we have to correct our llvm-objdump? if so, we swap our symbol we are marking here
    if constructor_swap:
        if "C1E" in sym:
            sym = sym.replace("C1E", "C2E")
        elif "C2E" in sym:
            sym = sym.replace("C2E", "C1E")

    for i in range(orig_length):
        curOrigInstr = original_instrs[i]
        curCustInstr = custom_instructions[i]

        orig_operands = curOrigInstr.operands
        cust_operands = curCustInstr.operands

        if str(curOrigInstr) == str(curCustInstr):
            if printDiff == True:
                print(f"{Fore.GREEN}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
            continue

        if curOrigInstr.id != curCustInstr.id:
            print(f"{Fore.RED}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
            instr_equal = False
            continue

        # loop through our operands to figure out what *exactly* doesn't match
        for j in range(len(orig_operands)):
            if orig_operands[j] != cust_operands[j]:
                if curOrigInstr.id == ARM64_INS_ADD:
                    # for the ADD instruction, let's see if our immediate value matches
                    # if it doesn't, then it is very possible it is a part of a address resolved by the linker
                    if orig_operands[2].imm != cust_operands[2].imm:
                        print(f"{Fore.YELLOW}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
                    else:
                        print(f"{Fore.RED}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
                        regs_equal = False
                    break

                if curOrigInstr.id == ARM64_INS_LDR:
                    if len(orig_operands) == 2 and len(cust_operands) == 2:
                        if orig_operands[1].type == CS_OP_MEM and cust_operands[1].type == CS_OP_MEM:
                            if orig_operands[1].mem.base != cust_operands[1].mem.base:
                                print(f"{Fore.RED}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
                            else:
                                print(f"{Fore.GREEN}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
                    break
                if curOrigInstr.id == ARM64_INS_ADRP:
                    print(f"{Fore.YELLOW}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
                # B and BL instructions
                elif curOrigInstr.id == ARM64_INS_B or curOrigInstr.id == ARM64_INS_BL:
                    print(f"{Fore.YELLOW}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
                else:
                    print(f"{Fore.RED}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
                    regs_equal = False
                break

    isAlreadyMarked = False

    with open("data/main.map", "r") as f:
        csvData = f.readlines()

    outCsv = []

    # we have a matching function
    if instr_equal == True and regs_equal == True:
        for c in csvData:
            spl = c.split("=")
            if spl[0] == sym and spl[3] == "false\n":
                outCsv.append(f"{spl[0]}={spl[1]}={spl[2]}=true\n")
            elif spl[0] == sym and spl[3] == "true\n":
                isAlreadyMarked = True
                outCsv.append(c)
            else:
                outCsv.append(c)

        if isAlreadyMarked == True:
            print("Function is already marked as decompiled.")
        else:
            print("Function is matching! Marking as decompiled...")
            isChanged = True
    # we have a nonmatching function
    else:
        for c in csvData:
            spl = c.split("=")
            if spl[0] == sym and spl[3] == "true\n":
                outCsv.append(f"{spl[0]}={spl[1]}={spl[2]}=false\n")
            elif spl[0] == sym and spl[3] == "false\n":
                outCsv.append(c)
            else:
                outCsv.append(c)

        if isAlreadyMarked == True:
            print("Function was marked as decompiled, but does not match. Marking as undecompiled...")
        
        if instr_equal == True and regs_equal == False:
            print("Function has matching instructions, but operands are not equal.")
        elif instr_equal == False and regs_equal == True:
            print("Function has matching operands, but instructions are not equal.")
        elif instr_equal == False and regs_equal == False:
            print("Function does not match in either instructions or operands.")

    with open("data/main.map", "w") as w:
        w.writelines(outCsv)

if isChanged:
    genProgress()

end = time.time()
length = end - start

#print(f"length: {length}")
