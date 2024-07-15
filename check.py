import glob, math, nso, os, sys
from colorama import Fore, Style
from capstone import *
from capstone.arm64 import *
from elftools.elf.elffile import ELFFile

LIBRARIES = ["ActionLibrary", "agl", "eui", "nn", "sead"]

def truncate(number, digits) -> float:
    stepper = 10.0 ** digits
    return math.trunc(stepper * number) / stepper

def genProgress():
    done_size = 0
    TOTAL_GAME_SIZE = 0xA0F5A0
    total_funcs = 0
    done_funcs = 0

    with open("data/main.map", "r") as f:
        csvData = f.readlines()

    for c in csvData:
        spl = c.split("=")
        isDone = spl[3].replace("\n", "")
        total_funcs += 1
        
        if isDone == "true":
            funcSize = int(spl[2])
            done_size = done_size + funcSize
            done_funcs += 1

    prog = (done_size / TOTAL_GAME_SIZE) * 100.0
    func_prog = (done_funcs / total_funcs)
    print("Progress:")
    print(f"{truncate(prog, 4)}% [{done_size} / {TOTAL_GAME_SIZE}]")
    print("Functions:")
    print(f"{truncate(func_prog, 4)}% [{done_funcs} / {total_funcs}]")

    print("Generating JSON...")

    # generate our JSON for the tags on the github page
    json = []
    json.append("{\n")
    json.append("\t\"schemaVersion\": 1,\n")
    json.append("\t\"label\": \"decompiled\",\n")
    json.append(f"\t\"message\": \"{truncate(prog, 4)}%\",\n")
    json.append("\t\"color\": \"blue\"\n")
    json.append("}")

    with open("data/percent.json", "w") as w:
        w.writelines(json)

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
        addr = spl[1]
        addr = int(addr[10:], 16)
        size = int(spl[2], 16)

        if sym == name:
            functionSize = size
            functionAddr = addr
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
            if curOrigInstr.id == ARM64_INS_ADRP or curOrigInstr.id == ARM64_INS_ADD or curOrigInstr.id == ARM64_INS_LDR:
                print(f"{Fore.YELLOW}{str(curOrigInstr):<80}{curCustInstr}{Style.RESET_ALL}")
            # B and BL instructions
            elif curOrigInstr.id == ARM64_INS_B or curOrigInstr.id == ARM64_INS_BL:
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
        if spl[0] == sym and spl[3] == "false\n":
            outCsv.append(f"{spl[0]}={spl[1]}={spl[2]}=true\n")
        elif spl[0] == sym and spl[3] == "true\n":
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
        genProgress()

elif instr_equal == True and regs_equal == False:
    print("Function has matching instructions, but operands are not equal.")
elif instr_equal == False and regs_equal == True:
    print("Function has matching operands, but instructions are not equal.")
elif instr_equal == False and regs_equal == False:
    print("Function does not match in either instructions or operands.")