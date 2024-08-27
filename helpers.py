import nso
import os
import hashlib
import sys
import pathlib

COMPILER_391_PATH = pathlib.Path("compilers/391/nx/aarch64/bin/clang++.exe")
COMPILER_800_PATH = pathlib.Path("compilers/800/nx/aarch64/bin/clang++.exe")

# it looks like some files use different compilers...so looks like we have to support these exceptions
EXCEPTION_FILES = {
    "NerveAction.cpp": COMPILER_391_PATH
}

def getCompilerPath(filename):
    if filename not in EXCEPTION_FILES:
        return COMPILER_800_PATH

    return EXCEPTION_FILES[filename]

# gets the "module" (object file) that a symbol is contained in from map files
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

# gets bytes from a function with a defined address and size from an NSO file
def getFunctionData(functionAddr, functionSize):
    with open("fury.nso", "rb") as f:
        data = f.read()

        digest = hashlib.sha256(data).hexdigest().upper()
        if digest != "80E48BC7BDF7AAA635E7B48C24F49C6A4D8AC19949FB1B9F66EADF2CFBA3BF85":
            print("fury.nso is not valid")
            sys.exit(1)

        nso_file = nso.NSO(data)

    return nso_file.getFunction(functionAddr, functionSize)

def getFunctionSizeAndAddr(sym):
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

    return functionSize, functionAddr