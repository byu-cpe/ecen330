---
layout: lab
toc: true
title: "Lab 3: Interval Timer Driver"
short_title: Timer Driver
number: 3
order: 3
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
        * Uncomment the two lines in the *drivers* [CMakeLists.txt]({{site.github.fileurl}}/drivers/CMakeLists.txt) file so that the *intervalTimer* library is built.  

    * **Application Code:**
        * The application code, which will test your interval timer driver, is provided to you as [main.c]({{site.github.fileurl}}/lab3_timer/main.c) in the *lab3* directory.  
        * A [CMakeLists.txt]({{site.github.fileurl}}/lab3_timer/CMakeLists.txt) file is also provided.
        * Like last lab, you will need to update the top-level [CMakeLists.txt](https://github.com/byu-cpe/ecen330_student/blob/master/CMakeLists.txt) and add a `add_subdirectory(lab3_timer)` statement.



## Implementation



### Requirements 

You will complete this lab off in two milestones:

#### Milestone 1

Implement the following features for *timer_0* (you can ignore the *timer_1* and *timer_2* for this milestone). You can uncomment the line `#define RUN_PROGRAM MILESTONE_1` in *main.c* to test Milestone 1, which will test the features in this order:

  1. Implement the **count up** feature of the timer:
      * *intervalTimer_initCountUp()* and *intervalTimer_load()*
      * *intervalTimer_start()* and *intervalTimer_stop()*
  1. Implement the ability to get the count up value in seconds:
      * *intervalTimer_getTotalDurationInSeconds*
  1. Implement the **count down** feature of the timer:
      * *intervalTimer_initCountDown()*
  
*Note:* When you run Milestone 1, several messages will be printed.  One message will repeat "*timer_0 TCR0 should be changing at this point: 0*".  In the emulator, you may notice this 0 value doesn't change, despite the messages saying it should.  This is normal behavior for the emulator.  Later after "*wait for awhile...*", it will print "*timer_0 TCR0 value after wait:*", and by this point you should definitely see it change from 0 to a large value. 

#### Milestone 2 
  1. Implement the functions to enable and disable interrupt output, and to acknowledge an interrupt:
      * *intervalTimer_enableInterrupt* and *intervalTimer_disableInterrupt*
      * *intervalTimer_ackInterrupt*

  1. Make sure all of your functions now work for all three timers.  

You can uncomment the line `#define RUN_PROGRAM MILESTONE_2` in *main.c* to test Milestone 2.


### Files
  - **Submitted files:** *drivers/intervalTimer.c*.
  - You are provided [intervalTimer.h]({{site.github.fileurl}}/drivers/intervalTimer.h). This file is not submitted, so you should not change it.
  - You are provided with *main.c*.  This file is not submitted, so you can change it for your own testing purposes, but you will be graded with the original file.

### Other Notes
  - Remember to follow the coding standard.
  - Make sure to use the Xilinx low-level access functions *Xil_In32()* and *Xil_Out32()* to access the registers in the timer hardware. These functions were discussed in a previous lab.
  - Like last lab, you should write helper functions for accessing device registers.  For example, you could use the following:
      ```
      readRegister(uint8_t timerNumber, uint32_t offset);
      writeRegister(uint8_t timerNumber, uint32_t offset, uint32_t value);
      ```

## Submission
Follow the [instructions on submitting source code]({% link _documentation/submission.md %}) to submit your code.

### Grade Breakdown 
  * 35%: Milestone 1
  * 35%: Milestone 2
  * 30%: Adherence to the coding standard
