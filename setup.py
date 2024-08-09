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

if not os.path.exists("compiler"):
    print("Compilers folder not found, downloading...")

    with urllib.request.urlopen("https://shibbo.net/3dw/3decomp-compilers.zip") as response, open("3decomp-compilers.zip", 'wb') as out:
        data = response.read()
        if hashlib.sha256(data).hexdigest().upper() != "DE253BC9846FD8097875A51CF7BA6DD2FD20EA482A988BD6EE6EA11D5A3E674E":
            print("3decomp-compilers.zip corrupt")
            sys.exit(1)
        out.write(data)

    if os.path.exists("3decomp-compilers.zip"):
        print("Extracting file...")
        with zipfile.ZipFile("3decomp-compilers.zip", "r") as zip:
            zip.extractall()

        os.remove("3decomp-compilers.zip")
    else:
        print("3decomp-compilers.zip failed to download.")
        sys.exit(1)
else:
    print("Found compiler folder...")

print("Done.")