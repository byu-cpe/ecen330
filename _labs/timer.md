---
layout: lab
toc: true
title: "Lab 3: Interval Timer Driver"
short_title: Timer Driver
number: 3
---
## Overview 

Understanding time is essential in embedded systems. You generally want to know how much time certain code segments require for proper execution. There are lots of ways to infer how long it will take to execute some section of code but generally the most accurate way to determine execution time is to measure it.

You will develop a software driver (including test code) that will communicate with three interval timers that I installed in the hardware configuration that you use for this class. Interval timers are essentially hardware counters that you can easily stop, start, and read. Because they are hardware-based counters, they don't interfere with your program or add to execution time while they are running. Interval timers can be very effective for measuring execution time for any part of your software. Do a nice job on this assignment. You will likely use these timers extensively in the remaining labs in this class and later in ECEn 390 when you implement your laser-tag game.

## Objectives 
  - Gain experience working with commercial documentation.
  - Write low-level code to communicate with the interval-timer hardware.
  - Gain additional practice writing 'C' code.
  - Write reusable code that will function as a tool in later lab assignments.
  - Write test-code that tests your software implementation and that also documents how to use the interval timer driver.
  - Learn how to follow the coding standard to write reusable code.

## Preliminary 

### Timer Hardware

Read over the page on [Timer overview and detailed description of timer operation]({% link _pages/timer.md %}).

<img src="{% link media/lab3/axitimerblockdiagram2.jpg %}" width="600" alt="AXI Timer Block Diagram">

### Building Lab 3 

#### Driver Code 
  * Most of this lab consists of writing a driver for the Interval Timer.  This driver will be written in *intervalTimer.c*, which you must create yourself.  You are provided with the [intervalTimer.h](https://github.com/byu-cpe/ecen330_student/blob/master/my_libs/intervalTimer.h) file, which you must not change.
  * Since the Interval Timer driver will be used in later labs, *intervalTimer.c* should be placed in your *my_libs* folder.
  * Uncomment the line in the *my_libs* [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/blob/master/my_libs/CMakeLists.txt) file so that the *intervalTimer* library is built.  

#### Application Code 
  * The application code, which will test your interval timer driver, is provided to you as [main.c](https://github.com/byu-cpe/ecen330_student/blob/master/lab3/main.c) in the *lab3* directory.  A [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/tree/master/lab3) file is also provided.
  * Like last lab, you will need to update the top-level [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/blob/master/CMakeLists.txt) and add a `add_subdirectory(lab3)` statement.



## Implementation

You will complete this lab off in two milestones:

### Milestone 1 
  * Get the functions *intervalTimer_init()*, *intervalTimer_start()*, *intervalTimer_stop()*, and *intervalTimer_reset()* working for *timer_0* (you can ignore the *timer_1* and *timer_2* for this milestone). 
  * Uncomment the line `#define RUN_PROGRAM MILESTONE_1` in *main.c* to test Milestone 1.


*Note:* When you run Milestone 1, several messages will be printed.  One message will repeat "*timer_0 TCR0 should be changing at this point: 0*".  In the emulator, you may notice this 0 value doesn't change, despite the messages saying it should.  This is normal behavior for the emulator.  Later after "*wait for awhile...*", it will print "*timer_0 TCR0 value after wait:*", and by this point you should definitely see it change from 0 to a large value. 

### Milestone 2 
  * Complete all of the lab requirements for all timers (*timer_0*, *timer_1*, and *timer_2*).
  * Uncomment the line `#define RUN_PROGRAM MILESTONE_2` in *main.c* to test Milestone 2.



## Requirements

  - You must write the *intervalTimer.c* file.
  - You must use [intervalTimer.h](https://github.com/byu-cpe/ecen330_student/blob/master/my_libs/intervalTimer.h) as given. No modifications are necessary or allowed.
  - You must follow the coding standard.
  - You must provide the following functions for the three interval timers (see below).
  - You must use the Xilinx low-level access functions *Xil_In32()* and *Xil_Out32()* to access the registers in the timer hardware. These functions were discussed in a previous lab.
  - You must define *isr_function()* in your code to avoid linking errors. Just use the same empty function from the helloWorld lab.
  - Run the the test code to determine the accuracy of your timer. Compare the time printed by the program to your watch to make sure it is accurate.

The functions that accept a timerNumber argument operate on a single timer. The timer number must be: 0, 1, or 2. Anything else should generate an error message. The *intervalTimer_initAll()*, *intervalTimer_resetAll()*, and *intervalTimer_testAll()* operate on all three timers. *intervalTimer_getTotalDurationInSeconds()* reads the 64-bit value from the timer and returns the number of seconds that have transpired since the counter was last reset and started.

*intervalTimer_test()* needs to see if the timers are working. In my code, I check things by:
  - I reset the counter and see if it is reset by reading it.
  - I start the counter and read it a couple of times to see if it is actually changing value.
  - I stop the counter and read it a couple of times to see that it is not changing.

### main.c 
You are provided with a main.c.  Do not change it, except for uncommenting one of the below lines to run the chosen milestone.

```
////////////////////////////////////////////////////////////////////////////////
// Uncomment one of the following lines to run Milestone 1 or 2      ///////////
////////////////////////////////////////////////////////////////////////////////
// #define RUN_PROGRAM MILESTONE_1
// #define RUN_PROGRAM MILESTONE_2
```

## Submission & Pass Off 
Follow the [instructions on submitting source code]({% link _documentation/submission.md %}) to submit your code.

The TAs will compile your code and run both milestones using the provided [main.c](https://github.com/byu-cpe/ecen330_student/blob/master/lab3/main.c).

### Grade Breakdown 
  * 25%: Milestone 1
  * 45%: Milestone 2
  * 30%: Adherence to the coding standard


## Resources 

  * [Xilinx Timer Documentation]({% link media/lab3/axi_timer_ds764.pdf %})
  * [Timer overview and detailed description of timer operation]({% link _pages/timer.md %})

## Suggestions 
  * The register access functions that you wrote for Lab 2 could be used here with little or no modification.
  * It is considered good practice to wrap the low-level I/O functions (*Xil_In32()*, *Xil_Out32()*) inside a helper function as demonstrated in the code provided for the buttons/switches lab. 
  * It is considered very poor practice to expose these low-level I/O calls throughout your code because your code is less readable, is difficult to port (move to a different system) and is a pain to debug.
  * Don't try to use file-names or directories/folder-names with spaces. The software will let you create them but the Xilinx software cannot handle them.