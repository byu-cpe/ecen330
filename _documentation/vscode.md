---
layout: page
toc: false
title: "VS Code Tips"
number: 6
---

## Building from Within VS Code 

From within VSCode you can build your code as follows:
  * To run `cmake` you can press F1 and select *Tasks: Run Task*, *cmake*.  
  * To run `make` you can press F1 and select *Tasks: Run Task*, *make*, or *Tasks: Run Build Task*, or *Ctrl+Shift+B* (on Windows).

The tasks have been set up in the [tasks.json](https://github.com/byu-cpe/ecen330_student/blob/master/.vscode/tasks.json) file.  Consider adding a new task to this file that allows you to program *lab1.elf* to the board.


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