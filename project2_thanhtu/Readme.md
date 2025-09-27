# Project_1


## Overview

The project contains a project C program that reads json file and parses it to extract user information and prints it

## Prerequisites

To build and run this project, you need:

1. C Compiler [MinGW](https://sourceforge.net/projects/mingw/)
2. [CMake](https://cmake.org/download/)
3. Windows operating system (based on the includes used in the code)

## Project Structure

```
project_1_ThanhTu/
├── CMakeLists.txt         # CMake build configuration
├── main.c                 # Main source file
├── README.md              # This file          
└── toolchain_win.cmake    # Windows toolchain configuration
```

## Building the Project

To build the project on Windows:

1. Configure CMake:
```powershell
cd project2_thanhtu
cmake -G "MinGW Makefiles" -DCMAKE_TOOLCHAIN_FILE=../toolchain_win.cmake -B build .
```

2. Build the project:
```powershell
mingw32-make -C build -j20
```

## Running the Program

After building, you can find the executable in the `bin` directory. Run it using:

```powershell
./project2_ThanhTu/bin/main.exe
```

The program will output: "main"

