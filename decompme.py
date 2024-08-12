# decompme.py
# uploads a "scratch" to https://decomp.me for help matching

import subprocess
import pathlib
import os
import sys
import hashlib
import nso
from capstone import *
from capstone.arm64 import *
import urllib.request
import urllib.parse
from typing import Dict
import json
import helpers

INCLUDE_DIRS = [
    "include",
    "lib/ActionLibrary/include",
    "lib/agl/include",
    "lib/eui/include",
    "lib/nn/include",
    "lib/sead/include"
]

LIBRARIES = ["ActionLibrary", "agl", "eui", "nn", "sead"]

incdirs = " ".join([f'-I {dir}' for dir in INCLUDE_DIRS])
PREPROC_CMD = f"-C -E {incdirs}"
COMPILER_CMD = f"-x c++ -O3 -fno-omit-frame-pointer -mno-implicit-float -fno-cxx-exceptions -fno-strict-aliasing -std=gnu++14 -fno-common -fno-short-enums -ffunction-sections -fdata-sections -fPIC -mcpu=cortex-a57+fp+simd+crypto+crc -g -Wall -c"

if len(sys.argv) < 2:
    print("decompme.py -- Generates a decomp.me scratch based on a given symbol.")
    print("decompme.py [symbol] {-test}")
    sys.exit(1)

sym = sys.argv[1]
isTest = False

if "-test" in sys.argv:
    isTest = True

path = helpers.getModule("map", sym)

if path == "":
    for lib in LIBRARIES:
        path = helpers.getModule(f"lib/{lib}/map", sym)

        if path != "":
            break

if path == "":
    print("Unable to find symbol.")
    sys.exit(1)

source_path = path.replace("build", "source")
source_path = source_path.replace(".o", ".cpp")
preproc_cmd = [helpers.COMPILER_PATH, "-E"] + incdirs.split() + [source_path]
procOut = subprocess.check_output(preproc_cmd).decode("utf-8").replace("\r", "")

procOut_Clean = ""

for line in procOut.split("\n"):
    if line.startswith("#"):
        continue

    procOut_Clean += f"{line}\n"

functionSize, functionAddr = helpers.getFunctionSizeAndAddr(sym)
funcData = helpers.getFunctionData(functionAddr, functionSize)
capstone_inst = Cs(CS_ARCH_ARM64, CS_MODE_ARM + CS_MODE_LITTLE_ENDIAN)
capstone_inst.detail = True
capstone_inst.imm_unsigned = False

if funcData == b'':
    print("Failed to fetch function data.")
    sys.exit(1)

instrs = list(capstone_inst.disasm(funcData, 0))
instrs_text = ""
instrs_text += f".global {sym}\n"
instrs_text += f"{sym}:\n"

for instr in instrs:
    instr_line = ("{}\t{}\n".format(instr.mnemonic, instr.op_str))
    if instr.id == ARM64_INS_ADRP:
        instr_line = instr_line.replace("#", "")
    instrs_text += instr_line

api_base = "https://decomp.me"

if not isTest:
    print("Uploading...")

    try:
        post_data = urllib.parse.urlencode(
            {
                "name": sym,
                "target_asm": instrs_text,
                "context": procOut_Clean,
                "source_code": "",
                "compiler": "clang-8.0.0",
                "compiler_flags": COMPILER_CMD,
                "diff_label": sym
            }
        ).encode("ascii")

        with urllib.request.urlopen(f"{api_base}/api/scratch", post_data) as f:
            resp = f.read()
            json_data: Dict[str, str] = json.loads(resp)

            if "slug" in json_data:
                slug = json_data["slug"]
                token = json_data.get("claim_token")
                if token:
                    print(f"https://decomp.me/scratch/{slug}/claim?token={token}")
                else:
                    print(f"https://decomp.me/scratch/{slug}")
            else:
                error = json_data.get("error", resp)
                print(f"Server error: {error}")
    except Exception as e:
        print(e)