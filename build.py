# build.py
# the main build script for building each library

import subprocess
import sys
import os
import pathlib
import shutil
from ninja_syntax import Writer

nonmatching_str = ""

if "-non-matching" in sys.argv:
    nonmatching_str = "-DNON_MATCHING"
    print("Non-functions matches will be compiled")

INCLUDE_DIRS = ["include", "lib\\ActionLibrary\\include", "lib\\agl\\include", "lib\\eui\\incldue", "lib\\nn\\include", "lib\\sead\\include", "compiler\\nx\\aarch64\\include", "compiler\\nx\\aarch64\\include\\c++" ]
LIBRARIES = [ "Game", "ActionLibrary", "agl", "eui", "nn", "sead"]

incdirs = ""
for dir in INCLUDE_DIRS:
    incdirs += f'-I {dir} '

COMPILER_CMD = f"-x c++ -O3 -fno-omit-frame-pointer -mno-implicit-float -fno-cxx-exceptions -fno-strict-aliasing -std=gnu++14 -fno-common -fno-short-enums -fdata-sections -fPIC -mcpu=cortex-a57+fp+simd+crypto+crc -g -Wall {nonmatching_str} {incdirs} -c "
COMPILER_PATH = pathlib.Path("compiler\\nx\\aarch64\\bin\\clang++")
OBJDUMP_PATH = pathlib.Path("compiler\\nx\\aarch64\\bin\\llvm-objdump")

def genNinja(tasks):
    with open('build.ninja', 'w') as ninja_file:
        ninja_writer = Writer(ninja_file)
        ninja_writer.rule("compile", command=f'{COMPILER_PATH} {COMPILER_CMD} $in -o $out',description=f'Compiling $in')

        for task in tasks:
            source_path, build_path = task
            ninja_writer.build(outputs=[build_path], rule="compile", inputs=[source_path])

def compileLibrary(name, path):
    compile_tasks = list()

    if name == "Game":
        path = "source"

    # let's do our source files first which we use ninja for
    for root, dirs, files in os.walk(path):
        for file in files:
            if file.endswith(".cpp"):
                source_path = os.path.join(root, file)
                build_path = source_path.replace("source", "build", 1).replace(".cpp", ".o")

                os.makedirs(os.path.dirname(build_path), exist_ok=True)
                compile_tasks.append((source_path, build_path))

    genNinja(compile_tasks)
    subprocess.run(['ninja', '-f', 'build.ninja'], check=True)
    generateMaps(path)

def generateMaps(path):
    objdump_tasks = list()

    # now for our map files which we don't need ninja for
    for root, dirs, files in os.walk(path):
        for file in files:
            if file.endswith(".cpp"):
                source_path = os.path.join(root, file)
                build_path = source_path.replace("source", "build", 1).replace(".cpp", ".o")
                map_path = build_path.replace("build", "map", 1).replace(".o", ".map")
                os.makedirs(os.path.dirname(map_path), exist_ok=True)
                objdump_tasks.append((source_path, build_path, map_path))

    for task in objdump_tasks:
        source_path, build_path, map_path = task 

        mapFileOutput = subprocess.check_output([OBJDUMP_PATH, build_path, "-t"]).decode("utf-8").replace("\r", "")
        lines = mapFileOutput.split("\n")
    
        newOutput = []

        for line in lines:
            if line == '':
                continue

            if line.startswith("build") or line.startswith("SYMBOL TABLE"):
                continue

            more_split = line.split(" ")
            
            # if global, it is most likely a symbol
            if more_split[1] == "g":
                # symbol is always the last entry
                sym = more_split[(len(more_split) - 1)]
                newOutput.append(f"{sym}\n")

        with open(map_path, "w") as w:
            w.writelines(newOutput)

for lib in LIBRARIES:
    compileLibrary(lib, f"lib\\{lib}\\source")
