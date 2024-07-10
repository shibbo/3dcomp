import glob, nso, os, sys
from colorama import Fore, Style
from capstone import *
from elftools.elf.elffile import ELFFile

LIBRARIES = ["ActionLibrary", "agl", "eui", "nn", "sead"]

def getModule(map, sym):
    for root, dirs, files in os.walk(map):
        for file in files:
            if file.endswith(".map"):
                map_path = os.path.join(root, file)
                with open(map_path, "r") as f:
                    lines = f.readlines()

                for line in lines:
                    fmt = line.replace("\n", "")
                    if fmt == sym:
                        # we found where our symbol lives!
                        # we just grab the source module
                        object_path = map_path.replace("map", "build", 1)
                        object_path = object_path.replace(".map", ".o")
                        return object_path
    return ""

if len(sys.argv) < 2:
    print("python check.py [-no-diff] <mangled symbol>")
    sys.exit(1)

printDiff = True

if "-no-diff" in sys.argv:
    sym = sys.argv[2]
    printDiff = False
else:
    sym = sys.argv[1]

sym = "_ZN2al19CameraPoserParallel25checkEnableCameraApproachEv"

# first let's see if our symbol even exists somewhere
path = getModule("map", sym)

if path == "":
    for lib in LIBRARIES:
        path = getModule(f"lib\\{lib}\\map", sym)

        if path != "":
            break

if path == "":
    print("Unable to find symbol.")
    sys.exit(1)

functionSize = 0
functionAddr = 0

with open("data/main.map", "r") as f:
    lines = f.readlines()

    for line in lines:
        spl = line.split("=")
        name = spl[0]
        addr = int(spl[1], 16)
        size = int(spl[2].replace("\n", ""), 16)

        if sym == name:
            functionSize = size
            # this is to adjust from the address in the NSO to the local address in the text section
            functionAddr = addr - 0x0000007100000000
            break

with open("fury.nso", "rb") as f:
    nso_file = nso.NSO(f.read())

funcData = nso_file.getFunction(functionAddr, functionSize)
capstone_inst = Cs(CS_ARCH_ARM64, CS_MODE_ARM + CS_MODE_LITTLE_ENDIAN)
capstone_inst.detail = True
capstone_inst.imm_unsigned = False

if funcData == b'':
    print("Failed to fetch function data.")
    sys.exit(1)

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
    text = elf_file.get_section_by_name('.text')
    custom_data = text.data()[custom_offset:custom_offset + custom_size]
    custom_instructions = list(capstone_inst.disasm(custom_data, 0))

orig_length = len(list(original_instrs))
cust_length = len(list(custom_instructions))

instr_equal = True
regs_equal = True

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

    for j in range(len(orig_operands)):
        if orig_operands[j].reg != cust_operands[j]:
            # ADRP and ADD can give of wrong operands because of us not linking, same with LDR
            if curOrigInstr.id == 9 or curOrigInstr.id == 6 or curOrigInstr.id == 162:
                print(f"{Fore.YELLOW}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
            # B and BL instructions
            elif curOrigInstr.id == 21 or curOrigInstr.id == 16:
                print(f"{Fore.YELLOW}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
            else:
                print(f"{Fore.RED}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
                regs_equal = False
            break

isAlreadyMarked = False

if instr_equal == True and regs_equal == True:

    with open("data/main.map", "r") as f:
        csvData = f.readlines()

    outCsv = []

    for c in csvData:
        spl = c.split("=")
    
        if spl[1] == sym and spl[3] == "false\n":
            outCsv.append(f"{spl[0]},{spl[1]},{spl[2]},true\n")
        elif spl[1] == sym and spl[3] == "true\n":
            isAlreadyMarked = True
            outCsv.append(c)
        else:
            outCsv.append(c)

    with open("data/main.map", "w") as w:
        w.writelines(outCsv)

    if isAlreadyMarked == True:
        print("Function is already marked as decompiled.")
    else:
        print("Function is matching! Marking as decompiled...")

elif instr_equal == True and regs_equal == False:
    print("Function has matching instructions, but operands are not equal.")
elif instr_equal == False and regs_equal == True:
    print("Function has matching operands, but instructions are not equal.")
elif instr_equal == False and regs_equal == False:
    print("Function does not match in either instructions or operands.")