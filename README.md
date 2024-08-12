# 3dcomp
<img src="https://github.com/shibbo/3dcomp/blob/main/img/logo.png" width="300">
<img src="https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/shibbo/3dcomp/main/data/decompiled.json" />
<a href="https://discord.gg/QnZ4cKkZm3">
<img src="https://img.shields.io/discord/1133588984883318884?logo=discord"
    alt="chat on our Discord"></a>

A decompilation effort for Super Mario 3D World + Bowser's Fury

## Build Instructions
1. Obtain a clean copy of a `main` from Super Mario 3D World + Bowser's Fury Kiosk Demo and rename it to `fury.nso`, and place it on the root.
2. Run `setup.py` to download and install all of the dependencies. These dependencies are `capstone`, `elftools`, `lz4`, `ninja`, and `colorama`. It will also download a zipped file that contains the compiler. It will also check to see if your NSO is the correct one.
3. Run `build.py`, then use `check.py` to verify matching status.

## Contributions

Want to contribute, or learn how to contribute? Try joining our Discord server (link is at the top), and looking into [on contribution guide](docs/CONTRIBUTING.md)! We will be glad to answer any questions for people who wish to contribute. All pull requests and issues are welcome.