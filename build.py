# build.py
# the main build script for building each library

import glob
import hashlib
import subprocess
import sys
import os
import pathlib
from ninja_syntax import Writer
import helpers

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
    "lib/nvn/include",
    "compiler/nx/aarch64/include",
    "compiler/nx/aarch64/include/c++",
]

LIBRARIES = ["Game", "ActionLibrary", "agl", "eui", "nn", "sead"]

incdirs = " ".join([f'-I {dir}' for dir in INCLUDE_DIRS])

COMPILER_CMD = f"-x c++ -O3 -fno-omit-frame-pointer -mno-implicit-float -fno-cxx-exceptions -fno-strict-aliasing -std=gnu++14 -fno-common -fno-short-enums -ffunction-sections -fdata-sections -fPIC -mcpu=cortex-a57+fp+simd+crypto+crc -g -Wall -Wno-invalid-offsetof {nonmatching_str} {incdirs} -c"
OBJDUMP_PATH = pathlib.Path("compilers/800/nx/aarch64/bin/llvm-objdump.exe")

# if we don't have this file, create it
HASHES_BASE_PATH = pathlib.Path("data\\hashes.txt")
CHANGED_PATH = pathlib.Path("data\\changed.txt")

if not os.path.exists(CHANGED_PATH):
    open(CHANGED_PATH, 'a').close()

# our hashes that we are starting out with
start_hashes = {}

if os.path.exists(HASHES_BASE_PATH):
    with open(HASHES_BASE_PATH, "r") as f:
        lines = f.readlines()

        for line in lines:
            line = line.strip("\n")
            spl = line.split("=")
            obj = spl[0]
            hash = spl[1]
            start_hashes[obj] = hash

isNotWindows = os.name != 'nt'

def genNinja(compile_tasks):
    with open('build.ninja', 'w') as ninja_file:
        ninja_writer = Writer(ninja_file)

        # Define a single compile rule with a placeholder for the compiler path
        ninja_writer.rule("compile", command='$compiler_path ' + COMPILER_CMD + ' $in -o $out', description='Compiling $in')

        for source_path, build_path in compile_tasks:
            # Get the appropriate compiler path for the current file
            compiler_path = helpers.getCompilerPath(os.path.basename(source_path))
            
            # Build the file with the correct compiler path
            ninja_writer.build(outputs=[build_path], rule="compile", inputs=[source_path], variables={'compiler_path': compiler_path})

def compileLibraries(libraries):
    compile_tasks = []

    for name in libraries:
        path = "source" if name == "Game" else f"lib/{name}/source"

        # let's do our source files first which we use ninja for
        for root, dirs, files in os.walk(path):
            for file in files:
                if file.endswith(".cpp") or file.endswith(".c"):
                    source_path = os.path.join(root, file)
                    if file.endswith(".cpp"):
                        build_path = source_path.replace("source", "build", 1).replace(".cpp", ".o")
                    elif file.endswith(".c"):
                        build_path = source_path.replace("source", "build", 1).replace(".c", ".o")

                    os.makedirs(os.path.dirname(build_path), exist_ok=True)
                    compile_tasks.append((source_path, build_path))

    genNinja(compile_tasks)
    subprocess.run(['ninja', '-f', 'build.ninja'], check=True)

    for name in libraries:
        path = "source" if name == "Game" else f"lib/{name}/source"
        generateMaps(path)

def generateMaps(path):
    objdump_tasks = list()

    # now for our map files which we don't need ninja for
    for root, dirs, files in os.walk(path):
        for file in files:
            if file.endswith(".cpp") or file.endswith(".c"):
                source_path = os.path.join(root, file)
                if file.endswith(".cpp"):
                    build_path = source_path.replace("source", "build", 1).replace(".cpp", ".o")
                elif file.endswith(".c"):
                    build_path = source_path.replace("source", "build", 1).replace(".c", ".o")

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
            # gw includes weak globals
            if more_split[1] == "g" or more_split[1] == "gw":
                # symbol is always the last entry
                sym = more_split[(len(more_split) - 1)]
                newOutput.append(f"{sym}\n")

        with open(map_path, "w") as w:
            w.writelines(newOutput)

compileLibraries(LIBRARIES)

obj_hashes = {}
changed_objs = []

for lib in LIBRARIES:
    objs = []

    if lib == "Game":
        objs = glob.glob(os.path.join("build", "**", "*.o"), recursive=True)
    else:
        objs = glob.glob(os.path.join("lib", lib, "build", "**", "*.o"), recursive=True)
    
    # generate our hashes
    for obj in objs:
        obj_hashes[obj] = hashlib.md5(open(obj,'rb').read()).hexdigest()

# now we determine what objects were changed based on comparing the two MD5 hashes
for obj in obj_hashes:
    if obj in start_hashes:
        if start_hashes[obj] != obj_hashes[obj]:
            changed_objs.append(obj)
    # this means that the object isn't in the starting hashes
    else:
        changed_objs.append(obj)

# do we have changed objs?
# if we do, then we write those changed objects to our text file
# if not, we clear the file
if len(changed_objs) > 0:
    with open(CHANGED_PATH, "w") as w:
        for obj in changed_objs:
            w.write(f"{obj}\n")
else:
    open(CHANGED_PATH, 'w').close()

# write our new hashes
with open(HASHES_BASE_PATH, "w") as w:
    for obj in obj_hashes:
        w.write(f"{obj}={obj_hashes[obj]}\n")