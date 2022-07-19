---
layout: page
toc: false
title: "Understanding the CMakeLists.txt Files"
short_title: "CMake"
number: 3
indent: 1
---

## Top-Level CMake File
When you run `cmake ..`, you are instructing the CMake tool to go up one level (from *\<your_repo\>/build* to *\<your_repo\>/*) and look for a *CMakeLists.txt* file.  Look over the top-level [CMakeLists.txt]({{iste.github.fileurl}}/CMakeLists.txt) file.

You don't need to understand everything in this file, but it's worth noting a few important parts:
  * The `include_directories` command add a directory for the compiler to search in for your header (.h) files.  All of the necessary paths are already included; you don't need to add any more.
  * The  `add_subdirectory` commands instructs CMake to go into a subdirectory and look for another `CMakeLists.txt` to run.  You will see this command added for the *lab1* folder, which instructs CMake to process the Lab 1 [CMakeLists.txt]({{iste.github.fileurl}}/lab1_helloworld/CMakeLists.txt) file.
For labs after Lab 1, you will need to add additional statements here.

## Creating Executables using CMakeLists.txt Files 
Look at the *lab1* [CMakeLists.txt]({{iste.github.fileurl}}/lab1_helloworld/CMakeLists.txt) file.  You will see the following:
  * *Line1*: The `add_executable` command is used to indicate that you want to create a new program executable.  The first argument is the executable name (lab1.elf), the rest of the arguments are the list of source files that need to be compiled for this program.  For lab1, we only have one source file, *main.c*. 
  * *Line2*: The `target_link_libraries` command is used to indicate that an executable uses code in a library and needs to link to it when built.  The first argument is the name of the executable (which we created on the previous line), the rest of the arguments are library names.  In this case, a variable is listed, `${330_LIBS}`, which is initialized in the top-level CMake to an appropriate set of libraries depending on if you are using the emulator or the physical board.  In later labs you will create your own libraries, and then you will need to add more items to this list.
  * *Line3*: Even though the software you write in this class will all be in C, some of the supporting libraries are actually compiled using C++, and the `set_target_properties(lab1.elf PROPERTIES LINKER_LANGUAGE CXX)` line instructs CMake of this so that it can build the executable correctly.

**In later labs you can create a new *CMakeLists.txt* file that is almost identical to this one.**  You will only need to update the lists of source files and libraries, and of course the name of the executable.

## Creating Libraries using CMakeLists.txt Files 
The [CMakeLists.txt]({{iste.github.fileurl}}/drivers/CMakeLists.txt) file in the *drivers* directory is used to create libraries instead of executables (ie., the code doesn't have a *main*, just functions that are called by other programs).
  * *Line 1:* The `add_library` command creates a new library.  The first argument is the name for your library, and the remaining arguments are all of the source files that should be compiled together to create the library.  
  * *Line 2:* Like described above, the `target_link_libraries` command instructs CMake that this library depends on other libraries.  Because the buttons and switches code calls the LED functions, it needs to link to the provided 330 libraries specified by the `${330_LIBS}` variable.


