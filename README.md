# Find the Path Puzzle

Welcome to the **Find the Path Puzzle** project. The goal of the project is to implement a solver for the puzzle mini-game explained in the challenge description.

## Prerequisites

* C++ compiler supporting C++17 standard
* CMake 3.18 or newer

## Building the Project

The project uses CMake build system. You can build it in pretty much the same way as any other CMake-based project. Just open the project folder in any modern IDE supporting CMake, such as Visual Studio 2019+, CLion or Qt Creator. Then build the project following the official IDE documentation.

**IMPORTANT: DO NOT create your own projects in Visual Studio, CLion, Qt Creator or any other IDE. Always use only the provided CMake project. Otherwise, we might not be able to properly build and grade your code after submission.**

## Running the Project

In order to help you test your work, we have provided a source code of simple command-line application under the `app` folder. You should run it to figure out how to properly implement `PathFinder` class and verify that your implementation works as expected. You are also encouraged to modify the testing code and add your own test cases.

**IMPORTANT: If you want to add your own `.cpp` and `.h` files, put them into `src` or `app` folder. The provided `CMakeLists.txt` looks up for C++ source files only in `src` and `app`.**

## Compatibility Notes

* Please stick to the C++17 standard. Do not use compiler-specific extensions.
* We will use GCC on Linux to compile your code. If possible, try to test the code under MinGW or GCC before submission.
* We provide a special header file `Common.h` to avoid typical incompatibilities between different C++ compilers. If you create your own `.h` files, make sure to add `#include "Common.h"` to each of them.
