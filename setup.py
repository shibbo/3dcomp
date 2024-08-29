import zipfile
import urllib.request
import os
import sys
import subprocess
import hashlib

def install(what):
    subprocess.check_call([sys.executable, '-m', 'pip', 'install', what])

if not os.path.exists("fury.nso"):
    print("fury.nso does not exist. Place a 3DW + BF Kiosk Demo NSO named fury.nso in the root.")
    sys.exit(1)
else:
    print("Found fury.nso...")
    with open("fury.nso", "rb") as f:
        data = f.read()
        digest = hashlib.sha256(data).hexdigest().upper()
        if digest != "80E48BC7BDF7AAA635E7B48C24F49C6A4D8AC19949FB1B9F66EADF2CFBA3BF85":
            print("fury.nso is not valid")
            sys.exit(1)
    print("fury.nso is valid...")

try:
    import capstone
    print("Found capstone, continuing...")
except ModuleNotFoundError:
    print("Module 'capstone' not installed. Installing...")
    install("capstone")

try:
    import elftools
    print("Found elftools, continuing...")
except ModuleNotFoundError:
    print("Module `elftools` not found. Installing...")
    install("pyelftools")

try:
    import ninja
    print("Found ninja, continuing...")
except ModuleNotFoundError:
    print("Module 'ninja' not found. Installing...")
    install("ninja")

try:
    import colorama
    print("Found colorama, continuing...")
except ModuleNotFoundError:
    print("Module 'colorama' not found. Installing...")
    install("colorama")

if not os.path.exists("compilers") or not os.path.exists("tools"):
    print("Compilers folder not found, downloading...")

    with urllib.request.urlopen("https://shibbo.net/3dw/3decomp-tools.zip") as response, open("3decomp-tools.zip", 'wb') as out:
        data = response.read()
        if hashlib.sha256(data).hexdigest().upper() != "3309D88F2D5499BC80BEFFF0D642C472754DB6BF439A8F48996FB98DA24E99EF":
            print("3decomp-compilers.zip corrupt")
            sys.exit(1)
        out.write(data)

    if os.path.exists("3decomp-tools.zip"):
        print("Extracting file...")
        with zipfile.ZipFile("3decomp-tools.zip", "r") as zip:
            zip.extractall()

        os.remove("3decomp-tools.zip")
    else:
        print("3decomp-tools.zip failed to download.")
        sys.exit(1)
else:
    print("Found compiler folder...")

if not os.path.exists("fury.elf"):
    print("Converting NSO to ELF...")
    subprocess.run(["tools/nx2elf.exe", "fury.nso"])
else:
    print("Found fury.elf...")

print("Done.")