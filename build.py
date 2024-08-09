# build.py
# the main build script for building each library

import subprocess
import sys
import os
import pathlib
from ninja_syntax import Writer

nonmatching_str = ""
clean = False

if "-non-matching" in sys.argv:
    nonmatching_str = "-DNON_MATCHING"
    print("Non-functions matches will be compiled")

if "-clean" in sys.argv:
    subprocess.call("ninja -t clean", shell=True)

INCLUDE_DIRS = [
    "include",
    "lib/ActionLibrary/include",
    "lib/agl/include",
    "lib/eui/include",
    "lib/nn/include",
    "lib/sead/include",
    "compiler/nx/aarch64/include",
    "compiler/nx/aarch64/include/c++",
]
LIBRARIES = ["Game", "ActionLibrary", "agl", "eui", "nn", "sead"]

incdirs = " ".join([f'-I {dir}' for dir in INCLUDE_DIRS])

COMPILER_CMD = f"-x c++ -O3 -fno-omit-frame-pointer -mno-implicit-float -fno-cxx-exceptions -fno-strict-aliasing -std=gnu++14 -fno-common -fno-short-enums -ffunction-sections -fdata-sections -fPIC -mcpu=cortex-a57+fp+simd+crypto+crc -g -Wall {nonmatching_str} {incdirs} -c"
COMPILER_PATH = pathlib.Path("compiler/nx/aarch64/bin/clang++.exe")
OBJDUMP_PATH = pathlib.Path("compiler/nx/aarch64/bin/llvm-objdump.exe")

isNotWindows = os.name != 'nt'

def genNinja(compile_tasks):
    with open('build.ninja', 'w') as ninja_file:
        ninja_writer = Writer(ninja_file)

        cmd = f'{COMPILER_PATH} {COMPILER_CMD} $in -o $out'
        if isNotWindows:
            cmd = f'wine {cmd}'
        ninja_writer.rule("compile", command=cmd, description='Compiling $in')

        for source_path, build_path in compile_tasks:
            ninja_writer.build(outputs=[build_path], rule="compile", inputs=[source_path])

def compileLibraries(libraries):
    compile_tasks = []

    for name in libraries:
        path = "source" if name == "Game" else f"lib/{name}/source"

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
    generateMaps()

def generateMaps():
    objdump_tasks = []

     # now for our map files which we don't need ninja for
    for root, dirs, files in os.walk("build"):
        for file in files:
            if file.endswith(".o"):
                build_path = os.path.join(root, file)
                map_path = build_path.replace("build", "map", 1).replace(".o", ".map")
                objdump_tasks.append((build_path, map_path))

    for build_path, map_path in objdump_tasks:
        cmd = [OBJDUMP_PATH, build_path, "-t"]
        if isNotWindows:
            cmd = ["wine"] + cmd

        mapFileOutput = subprocess.check_output(cmd).decode("utf-8").replace("\r", "")
        lines = mapFileOutput.split("\n")

        newOutput = []

        for line in lines:
            if line == '' or line.startswith("build") or line.startswith("SYMBOL TABLE"):
                continue

            more_split = line.split(" ")

            # if global, it is most likely a symbol
            # gw includes weak globals
            if more_split[1] in ["g", "gw"]:
                sym = more_split[-1]
                newOutput.append(f"{sym}\n")

        os.makedirs(os.path.dirname(map_path), exist_ok=True)
        with open(map_path, "w") as w:
            w.writelines(newOutput)

compileLibraries(LIBRARIES)