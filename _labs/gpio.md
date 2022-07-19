---
layout: lab
toc: true
title: "Lab 2: GPIO Driver for the Switches and Buttons"
short_title: GPIO Driver
number: 2
order: 2
---

## Overview 
In this lab you will write a driver for the GPIO (general purpose input/output) hardware.  GPIO hardware allows the processor to interact with the input and output pins on the chip.  For this lab, the pins we are interested in are those connected to the slide switches and push buttons.  Once you have written your driver, you will be able to easily read button and switch values, and you will build a small test application to verify that your driver is working correct.
 
<!-- One you have completed the driver software, you will create test programs to verify that your driver code works correctly. -->

<iframe width="560" height="315" allow="fullscreen" src="https://www.youtube.com/embed/PaIXUnRUg-4"> </iframe>

<iframe width="560" height="315" allow="fullscreen" src="https://www.youtube.com/embed/QYQlwwn_CJs"> </iframe>


### Objectives 
  - Gain experience writing driver code that interacts with hardware.
  - Gain experience with commercial documentation.
  <!-- - Understand how the GPIO IP block functions and write low-level code to communicate with it (instead of using the functions provided by *xgpio.h*). -->
  <!-- - Learn how to write low-level software to interface with buttons and switches. -->
  <!-- - Write reusable code that you may use in later labs. -->
  - Write test code that demonstrates the correctness of your driver.
  - Practice applying the class coding standard.
  <!-- - Gain additional practice with the graphic library and the LCD. -->

## Preliminary 

1. Read about the [Programming Stack]({% link _documentation/devices.md %}#programming-stack).

1. When using programmable processors such as microprocessors, etc., we access low-level hardware via registers. See the [GPIO and Registers page]({% link _documentation/gpio.md %}) to understand how you will access the GPIO hardware.

1. **Terminology**. Learn about some new terminology (reviewed in class):
  * [memory map](https://en.wikipedia.org/wiki/Memory_map)
  * [address bus](https://en.wikipedia.org/wiki/Address_bus)
  * data bus
  * IP
  * Register

1. **Review header files**. The [buttons.h](https://github.com/byu-cpe/ecen330_student/blob/main/drivers/buttons.h) and [switches.h](https://github.com/byu-cpe/ecen330_student/blob/main/drivers/switches.h) files which are provided in your repository.  These header files define the interface to your driver.

1. **Including header files**. Review the page about [header files]({% link _documentation/headers.md %}). 

1. **Compiling**.  In this lab you will first write driver code, and then write a test application.  
    * Read the page about [CMake files]({% link _documentation/cmake.md %}).
    * The *driver* code will be re-used in later labs, so it will be compiled into a *library* that can be used by multiple applications. This library, called *buttons_switches*, will be located in the [drivers](https://github.com/byu-cpe/ecen330_student/tree/main/drivers) directory.  You are already given a [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/blob/main/drivers/CMakeLists.txt) file in this directory that will compile your *buttons.c* and *switches.c* code into the ''buttons_switches'' library.

    * The *application* code will be a simple test program to ensure your drivers are working correctly.  The test application will be placed in your [lab2](https://github.com/byu-cpe/ecen330_student/tree/main/lab2_gpio) directory, where you have already been provided a [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/blob/main/lab2_gpio/CMakeLists.txt) that will compile the Lab 2 executable.  You will see that it is almost the same as Lab 1 file, except that line 2 also includes the *buttons_switches* library.

    * The only changes you need to make for this lab is to instruct the top-level [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/blob/main/CMakeLists.txt) file to enter both of these directories and process those CMakeLists.txt files.  Add  `add_subdirectory(lab2_gpio)` and `add_subdirectory(drivers)` statements to the top-level CMakeLists.txt, after the `add_subdirectory(lab1_helloworld)` statement.


## Implementation 

### Requirements 

1. **Switches driver**.  Write a driver for the slide switches.  This driver will be located in *drivers/switches.c* and will implement the functions in [switches.h](https://github.com/byu-cpe/ecen330_student/blob/main/drivers/switches.h).  

1. **Buttons driver**. Write a driver for the push buttons.  This driver will be located in *drivers/buttons.c* and will implement the functions in [buttons.h](https://github.com/byu-cpe/ecen330_student/blob/main/drivers/buttons.h).

1. **Test applications**.  Create test functions for your two drivers.  The provided [main.c](https://github.com/byu-cpe/ecen330_student/blob/main/lab2_gpio/main.c) calls the `gpioTest_buttons()` and `gpioTest_switches()` functions.  Write both of these functions in `gpioTest.c`. 
  * **Switches test:** 
        * The switch test program is shown in a video above.  It turns on LEDs corresponding to the switches that are in the UP position.  
        * The test will end once all four switches are UP.
  * **Buttons test:**
        * The button test program is also shown in a video above. It will draw colored squares to the LCD dependent on which button is pressed. 
        * The test will end when all four buttons are pressed simultaneously.  (On the emulator, you can press multiple buttons at once using the SHIFT key.)
        * You must only draw the rectangle once for each button press and erase it once for each button release. It is okay if there is some button bouncing but continuously drawing or erasing rectangle in a loop is not allowed.

### Files
* Place your driver code in *buttons.c* and *switches.c*, located in the [drivers]() directory.
* Place your test application code in *gpioTest.c* in the [lab2_gpio]() directory. 
* Do not modify *main.c* and do not modify any *header files*.  You can write additional helper functions beyond those defined in the *.h* file, but the helper functions should be declared and defined in your *.c* files (remember to declare them static). 

### Other Notes
  - Remember to follow the [coding standard]({% link _other/coding_standard.md %}).
  - You are provided a driver to control the LEDs. See [leds.h](https://github.com/byu-cpe/ecen330_student/blob/main/include/leds.h).  Include this header using `#include "leds.h"`. 
  - You should write helper functions for accessing device registers.  For example, *buttons.c* and *switches.c* could both contain:
      ```
      uint32_t readRegister(uint32_t offset);
      void writeRegister(uint32_t offset, uint32_t value);
      ```

##  Submission

For each lab, you will follow the [instructions on submitting source code]({% link _documentation/submission.md %}) to submit your code.

### Grade Breakdown 
  * 70% Pass off. If your code works well and shows no bugs, you should get the full 70%.
  * 30% Code quality and adherence to the coding standard. You are allowed 10 freebies for this lab.


