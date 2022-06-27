---
layout: lab
toc: true
title: "Lab 3: Interval Timer Driver"
short_title: Timer Driver
number: 3
---
## Overview 

Measuring time and controlling period events are essential tasks in embedded systems.  This typically requires the use of hardware timer.  In this lab you will write a driver to control three identical hardware-based interval timers that are present on the hardware system.

Interval timers are essentially hardware counters that you can easily stop, start, and read.  The interval timers we will use in this lab have additional configuration features that allow them to count up or down, load values, run endlessly, and generate interrupts.  Because they are hardware-based counters, they don't interfere with your program or add to execution time while they are running.  Interval timers can be very effective for measuring execution time for any part of your software. 
 
Do a nice job on this assignment. You will likely use these timers extensively in the remaining labs in this class and later in ECEn 390 when you implement your laser-tag game. 

### Objectives 
  * Experience interacting with a commercial hardware timer, with multiple control and data registers.
  * More experience working with commercial documentation.
  * Practice writing high-quality 'C' code, following the coding standard.

## Preliminary 

1. **Timer hardware:** Read over the page on [Timer hardware]({% link _documentation/timer.md %}).

1. **Building the code:** This lab you will only write driver code.  The test application code is provided to you.
    * **Driver:** 
        * This driver will be written in *intervalTimer.c*, which you must create yourself.  
        * Since the Interval Timer driver will be used in later labs, *intervalTimer.c* should be placed in your *drivers* folder.
        * Uncomment the two lines in the *drivers* [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/blob/master/drivers/CMakeLists.txt) file so that the *intervalTimer* library is built.  

    * **Application Code:**
        * The application code, which will test your interval timer driver, is provided to you as [main.c](https://github.com/byu-cpe/ecen330_student/blob/master/lab3/main.c) in the *lab3* directory.  
        * A [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/tree/master/lab3) file is also provided.
        * Like last lab, you will need to update the top-level [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/blob/master/CMakeLists.txt) and add a `add_subdirectory(lab3)` statement.



## Implementation

You will complete this lab off in two milestones:

### Milestone 1 Requirements 

Implement the following features for *timer_0* (you can ignore the *timer_1* and *timer_2* for this milestone). You can uncomment the line `#define RUN_PROGRAM MILESTONE_1` in *main.c* to test Milestone 1, which will test the features in this order:

  1. Implement the **count up** feature of the timer:
      * *intervalTimer_initCountUp()* and *intervalTimer_load()*
      * *intervalTimer_start()* and *intervalTimer_stop()*
  1. Implement the ability to get the count up value in seconds:
      * *intervalTimer_getTotalDurationInSeconds*
  1. Implement the **count down** feature of the timer:
      * *intervalTimer_initCountDown()*
  

*Note:* When you run Milestone 1, several messages will be printed.  One message will repeat "*timer_0 TCR0 should be changing at this point: 0*".  In the emulator, you may notice this 0 value doesn't change, despite the messages saying it should.  This is normal behavior for the emulator.  Later after "*wait for awhile...*", it will print "*timer_0 TCR0 value after wait:*", and by this point you should definitely see it change from 0 to a large value. 

### Milestone 2 
  * Complete all of the lab requirements for all timers (*timer_0*, *timer_1*, and *timer_2*).
  * Uncomment the line `#define RUN_PROGRAM MILESTONE_2` in *main.c* to test Milestone 2.



## Requirements

  - You must write the *intervalTimer.c* file.
  - You must use [intervalTimer.h](https://github.com/byu-cpe/ecen330_student/blob/master/drivers/intervalTimer.h) as given. No modifications are necessary or allowed.
  - You must follow the coding standard.
  - You must provide the following functions for the three interval timers (see below).
  - You must use the Xilinx low-level access functions *Xil_In32()* and *Xil_Out32()* to access the registers in the timer hardware. These functions were discussed in a previous lab.
  - Run the the test code to determine the accuracy of your timer. Compare the time printed by the program to your watch to make sure it is accurate.

The functions that accept a timerNumber argument operate on a single timer. The timer number must be: 0, 1, or 2. Anything else should generate an error message. The *intervalTimer_initAll()*, *intervalTimer_resetAll()*, and *intervalTimer_testAll()* operate on all three timers. *intervalTimer_getTotalDurationInSeconds()* reads the 64-bit value from the timer and returns the number of seconds that have transpired since the counter was last reset and started.

Implementing *intervalTimer_test()* and *intervalTimer_testAll()* is optional.  You can use them to write your own test code separate from the code provided in main.  I check things by:
  - I reset the counter and see if it is reset by reading it.
  - I start the counter and read it a couple of times to see if it is actually changing value.
  - I stop the counter and read it a couple of times to see that it is not changing.

### Files

You are provided with the [intervalTimer.h](https://github.com/byu-cpe/ecen330_student/blob/master/drivers/intervalTimer.h) file, which you must not change.

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

## Suggestions 
  * The register access functions that you wrote for Lab 2 could be used here with little or no modification.
  * It is considered good practice to wrap the low-level I/O functions (*Xil_In32()*, *Xil_Out32()*) inside a helper function as demonstrated in the code provided for the buttons/switches lab. 
  * It is considered very poor practice to expose these low-level I/O calls throughout your code because your code is less readable, is difficult to port (move to a different system) and is a pain to debug.
  * Don't try to use file-names or directories/folder-names with spaces. The software will let you create them but the Xilinx software cannot handle them.