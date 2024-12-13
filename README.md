## NOTES FOR SUBMISSION OF JUSTIN PIERCE
* Many of the predefined header files have members in weird places. This is because I wanted to keep all additional code under the "// You can add your own class members here." comment, where possible, ignoring whether or not the members should be public (it's unclear how strict you will be about these rules regarding modifying of existing classes)

* Output:

> Running example of a simple puzzle with one sequence
Actual solution:   Path({{0, 1}, {3, 1}, {3, 3}})
Expected solution: Path({{0, 1}, {3, 1}, {3, 3}})
Execution time: 481 uS

Running example of a puzzle with two sequences
Actual solution:   Path({{0, 3}, {2, 3}, {2, 0}, {4, 0}, {4, 2}})
Expected solution: Path({{0, 3}, {2, 3}, {2, 0}, {4, 0}, {4, 2}})
Execution time: 393 uS

Running example of a puzzle with one wasted move
Actual solution:   Path({{0, 2}, {2, 2}, {2, 3}, {4, 3}, {4, 0}, {2, 0}})
Expected solution: Path({{0, 2}, {2, 2}, {2, 3}, {4, 3}, {4, 0}, {2, 0}})
Execution time: 4522 uS

Running example of a puzzle with three wasted moves
Actual solution:   Path({{0, 0}, {2, 0}, {2, 3}, {1, 3}, {1, 4}, {2, 4}, {2, 1}})
Expected solution: Path({{0, 0}, {2, 0}, {2, 3}, {1, 3}, {1, 4}, {2, 4}, {2, 1}})
Execution time: 6446 uS

Running example of a puzzle with competing sequences
Actual solution:   Path({{0, 0}, {3, 0}, {3, 1}, {2, 1}})
Expected solution: Path({{0, 0}, {3, 0}, {3, 1}, {2, 1}})
Execution time: 1501 uS

Running example of a puzzle without any solution
Actual exception:   PathNotFoundError
Expected exception: PathNotFoundError

Running example of a puzzle with the shortest competing sequence
Actual solution:   Path({{0, 2}, {3, 2}, {3, 0}})
Expected solution: Path({{0, 2}, {3, 2}, {3, 0}})
Execution time: 1393 uS

Running example of a puzzle with one possible sequence out of three
Actual solution:   Path({{0, 0}, {3, 0}, {3, 4}})
Expected solution: Path({{0, 0}, {3, 0}, {3, 4}})
Execution time: 36854 uS

Running example of a complex puzzle with six sequences
Actual solution:   Path({{0, 8}, {3, 8}, {3, 9}, {9, 9}, {9, 5}, {5, 5}, {5, 4}, {4, 4}, {4, 0}, {2, 0}, {2, 6}, {7, 6}})
Expected solution: Path({{0, 8}, {3, 8}, {3, 9}, {9, 9}, {9, 5}, {5, 5}, {5, 4}, {4, 4}, {4, 0}, {2, 0}, {2, 6}, {7, 6}})
Execution time: 11421107 uS

Running example with partial overlap
Actual solution:   Path({{0, 3}, {2, 3}, {2, 0}, {0, 0}})
Expected solution: Path({{0, 3}, {2, 3}, {2, 0}, {0, 0}})
Execution time: 199 uS

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
