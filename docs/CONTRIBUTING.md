# Contributing

To contribute, you will need the following tools:

* A disassembler, IDA Pro or Ghidra work very well (you can also use a decompiler, it can make some things easier)
* Python 3.7 and higher


It is recommended that you have knowledge of the following:

* C / C++ (however, C++ is STRONGLY recommended)
* Aarch64 Assembly
* Reverse engineering instructions from Aarch64 to C / C++

Decompilers such as Hex-Rays (included in IDA Pro) are useful as they can make the decompilation easier to write.

Be sure that all of your submitted code follows the guidelines that are listed below. After the code matches, be sure to run `check.py` to check the function that you want to mark. If it matches, it will automatically be marked as decompiled.

If you have any questions or concerns, please join [our Discord server](https://discord.gg/QnZ4cKkZm3)!

### Headers

* Use `#pragma once` at the top of each header file
* Use forward-declared types when possible

### Includes

* Use `#include<>` for system library includes
* Use `#include "..."` for including game headers, and they must be relative to `include`

### Names

* Names for known symbols should match exactly, even including typoes in the symbol
* Member variables must be prefixed with `m`

### Classes

* Functions for classes must be put in this order: constructor, destructor, operators, virtual functions, member functions
    * If the virtual functions are not in the order that they are in the vtable, then the rule above can be ignored as these functions must be placed in order
* When referencing a class member, do not use `this->`, unless it is required for compilation

### Matching
To see how to use the checker scripts, see [the checking guide](CHECKING.md)!

### Pull Requests
Before you make your pull request, ensure the following:

* Your code compiles. We will not accept code that does not compile.
* Your code follows the standards written above.
* You have ran `clang-format` on your code.
* Your code is not copypasted or stolen from other sources (and if you do use code from another repository, please give credit)
* The locations of where you put the include / source files makes sense. If you are unsure, make a note or ask us in the Discord server.