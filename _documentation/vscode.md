---
layout: page
toc: false
title: "Coding/Debugging Tips"
number: 6
indent: 1
---

## Warnings

**Your code should compile without warnings**. <ins> Do not waste your time debugging issues with your code if there are warnings when you compile.</ins>  Often fixing the warning will fix your bug.  *Every* warning can be fixed and removed.  If you don't know how to fix your warning, ask on the class message board.



## Debugging from VS Code

If you want to try using the GDB debugger integrated in VSCode (along with the emulator -- this doesn't work on the board), you can follow these steps (note that sometimes it can be challenging using interactive debuggers with code that is driven by interrupts, like most of your labs):

1. Install GDB (This is already done in the VM we gave you):

        sudo apt install gdb

1. You need to configure your compiler to generate "debug symbols".  Add the following line to the top-level CMakeLists.txt at line 10:

        set(CMAKE_BUILD_TYPE Debug)

1. After you do that, it would be best to completely clean and rebuild your code:

        cd ~/ecen330
        rm -rf build_emu
        mkdir build_emu
        cd build_emu
        cmake .. -DEMU=1
        make

1. In VSCode, open the *.vscode/launch.json* file to configure a debug session.  You can edit the existing one, or create new ones.

    * Change this line to give your configuration a helpful name:

          "name": "Lab1",

    * Change the "program" option to the path to your executable.  Such as:

          "program": "${workspaceFolder}/build_emu/lab1/lab1.elf"

1. Go to your *main.c* and add a breakpoint to the start of main.  You can do this by clicking the red dot next to the line number.

1. In the debugger panel, hit the green Play button.  You should now be paused on your code like so:

<img src="{% link media/debugging.png %}" alt="Debugging in VS Code">

## Valgrind
Valgrind is a very useful tool for finding runtime issues with your code.  This includes using uninitialized variables, referencing invalid pointers, and issues with malloc/free.  This is only useable on the emulator, and you should have debug symbols enabled (see step #2 above).

Run valgrind on your program like this:

        valgrind ./lab1/lab1.elf

Look for the first error reported by valgrind and try and locate and fix the issue causing the error.  [This stack overflow post](https://stackoverflow.com/questions/5134891/how-do-i-use-valgrind-to-find-memory-leaks) has lots of tips if you want to read more.

## Building from Within VS Code 

From within VSCode you can build your code as follows:
  * To run `cmake` you can press F1 and select *Tasks: Run Task*, *cmake*.  
  * To run `make` you can press F1 and select *Tasks: Run Task*, *make*, or *Tasks: Run Build Task*, or *Ctrl+Shift+B* (on Windows).

The tasks have been set up in the [tasks.json](https://github.com/byu-cpe/ecen330_student/blob/main/.vscode/tasks.json) file.  Consider adding a new task to this file that allows you to program *lab1.elf* to the board.

