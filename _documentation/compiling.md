---
layout: page
toc: false
title: "Compiling and Running"
number: 2
indent: 1
---


In this course we will be using the GCC compiler to compile your C code into executable programs that you can run on the ARM processor on the Zybo board, or on the emulator on your local computer.

Typically when building C software we use a [Makefile](https://en.wikipedia.org/wiki/Makefile) to build the program.  
Without a Makefile we would have to manually compile each of our C files, and link each C file together to create programs.  Whenever a file changes, we would need to remember to recompile that file, as well as recompile any files that use it.  A Makefile automates that process for us, and running the ''make'' program will detect which files have changed and need to be recompiled and linked into programs.

Unfortunately, Makefiles can quickly become very complicated, even for fairly simple tasks.  They are often cryptic and difficult to understand.  Instead of creating Makefiles manually, we will be using a build system called [CMake](https://cmake.org), that will automatically create Makefiles for us.  Thus, the normal build process for the class will involve creating and updating your CMake configuration files, named *CMakeLists.txt*, running `cmake` to create a *Makefile*, and then running `make` to compile all of your source code.

## The CMake Project File 

We have given you a [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/blob/main/CMakeLists.txt) file that sets up the lab files to compile with CMake.  This file, which is described later, will be used to compile all of the labs in the course, and you will need to update it as you work through the labs.  It doesn't need to be modified for Lab 1.

## Compiling Your Code 
You can always follow the same steps to compile your labs.  Running this build process will always compile all of your lab programs.
  * Open the terminal
  * Navigate to the *build* directory.  (If you previously deleted this folder, you will need to recreate it using `mkdir build`.)

        cd build

  * Run CMake, and point it to the directory where the primary [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/blob/main/CMakeLists.txt) file is located.  CMake will read this file and create a *Makefile* that can be used to compile your programs. 
  *(Remember that `..` means the parent directory in Linux).*

        cmake ..
  

  * Run the `make` command which will read in the *Makefile* and use its contents to invoke the compiler and build your software.

        make
  
  

**Now that you've done these steps once, <ins>in the future you only ever need to run `make`</ins>.  Once CMake has been run once and has set up the Makefile system, you can just re-run make for any future changes. Even if you change the CMake files, the system is set up so that the generated Makefile will detect these updates, and automatically call CMake to update itself.  The only time you will need to re-run `cmake` is if you delete the files in your build directory**.


## Emulator vs Board 

You have the option of running your software programs using the emulator, or using the Zybo boards in the lab.  Because the processor on the Zybo board is very different than the processor in your computer, the programs have to be compiled differently depending on where you want to run them.  To keep your build files organized and separate, use the *build_emu* directory when building for the emulator.

**To compile for the board**: run:

    cd build
    cmake ..
    make

**To compile for the emulator**: run:

    cd build_emu
    cmake .. -DEMU=1
    make

After compiling lab1, you should have an executable program located at *build/lab1/lab1.elf*. 

## Running Programs
### Zybo Board 
To run Lab 1 on the board (assuming you are in the *build* directory):

    ../run_elf_on_board.py lab1/lab1.elf


### Emulator 
To run Lab 1 in the emulator (assuming you are in the *build_emu* directory):

    ./lab1/lab1.elf
  

<!-- **IMPORTANT**: If you switch between the emulator and the board, you should delete all of the files in the build directory, then re-run the cmake/make steps above. -->


