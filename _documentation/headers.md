---
layout: page
toc: false
title: "Header Files"
number: 3
---

In several cases you are instructed to include **header** files in your code, such as *leds.h*, *display.h*, *xparameters.h*, *xil_io.h*, *buttons.h*, *switches.h*, and more.

<ins>These header files are already in your code repository in the appropriate locations.</ins>  **You shouldn't ever create these files or move them to different locations in your code repository.**

If you want access the functions or *#define*s within these header files, simply include them in your .c file like so:

    #include "xil_io.h"
    #include "xparameters.h"
    #include "display.h"
    #include "leds.h"

When you *#include* a header file at the top of your .c file, it is the same as copying all the contents of the header file to that position in your .c file.  All of the function declarations and *#define*s can now be referenced in your C code.

## Include Paths 

You may notice that in *lab1/main.c* you were able to put `#include "display.h"` in your code and it compiled fine, even though the *display.h* file is not located in your *lab1* folder, but rather is located in the *include* folder.

You may have been tempted to change the statement in your code to `#include "../include/display.h"`. **You don't need to do this**.  Your include statements don't need to be relative paths to the header files.

Why?

We have already configured CMake to instruct it which folders in our code repository it should search for in order to find our header files.  This is referred to as an *Include Path*.

If you look at the top-level [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/blob/master/CMakeLists.txt) file, you will see lines like so:

    include_directories(include)
    include_directories(drivers)

which instruct CMake that we want to include header files directly from these directories.  If you look around in the *CMakeLists.txt* file you will see other paths that are included as well.




