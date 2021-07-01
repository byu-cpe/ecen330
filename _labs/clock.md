---
layout: lab
toc: true
title: "Lab 4: Clock"
short_title: Clock
number: 4
---

## Overview

In this lab you will implement a clock. Every modern device seems to include a clock, so we want one too. Your clock will look like this:
<iframe width="560" height="315" allow="fullscreen" src="https://www.youtube.com/embed/s8tV_iznYRU"> </iframe>

The middle numerical display shows the time in 12-hour format. The green triangles (arrows) above and below indicate touch regions above and below the clock display that allow you to set the time. The arrows that are above the display will increment the hours, minutes, and seconds of the clock, when touched. The arrows that are below the clock will decrement the hours, minutes, and seconds of the clock when touched. These clock-setting functions also have an auto-update rate that engages after the user presses the arrow for at least 0.5 seconds. Once the auto-update engages, it updates the time at a rate of 10 changes per second. For example, say the user presses the arrow below the minutes field for 0.5 seconds. After the initial 0.5 second delay, the hours will decrement automatically at a rate of 10 decrements per second. You have probably seen similar functionality in the clocks that you have used. 

## Objectives 

  - Implement a synchronous state machine for the first time, and learn how to debug state machines.
  - Use the interval timer package from the previous lab to measure execution time of your *tick* function.
  - Learn how to identify and separate control and display functions.
  - Use interrupts using the *flag method*: waiting for a flag set by the interrupt service routine before calling *clockControl_tick()*.

## Preliminary 

### Building this Lab 
All of your code for this lab will be written in the *lab4* directory.  You will need to create a *CMakeLists.txt* file in this directory to build the clock application and link it to any necessary libraries.  You can mostly copy the *CMakeLists.txt* file from lab 2 or 3; however, you will have more .c files to compile than just *main.c*.

Modify the top-level *CMakeLists.txt* file to include your *lab4* folder.

<!-- The clock application you build in this lab won't be reused in later labs, so you don't need to place any code in *drivers* or create any new libraries. -->

### Display versus Control 

The implementation of the lab will be separated into two major coding sections: display and control. This will provide good practice for just about any embedded-programming project as most embedded projects are usually best broken down this way, both for implementation and for debug/verification. We will follow this general strategy throughout the semester. 

#### Display

The display code is responsible for **storing the current clock value (hours, minutes, seconds), and rendering it on the display**. This includes things like:
  * drawing the triangles that indicate the up/down touch regions that are used to set the current time.
  * drawing the characters that indicate the time.
  * incrementing and decrementing the seconds, minutes, and hours, when instructed to by the control code.
  * updating the time when told that a second has passed.
Note that the display code has no "sense" of time. Its job is to perform computations and to draw things on the LCD but it has no sense of when these things should be done. The control code will tell the display code when it is time to add 1 second to the current time, when to update the screen when auto-update is occurring, etc.

#### Control

The control code is responsible for **knowing when the current time needs to change**.  It does this by handling the up/down touch regions for setting the clock, and using a timer to know when 1 second has elapsed, and the time needs to increment. The control code controls when the display code does things. The control code has no "sense" of how the display is updated, it just controls when these updates occur. It does things like:
  * keep track of when it is time to add 1 second to the current time.
  * when to increment or decrement the display according to the auto-update rate.
  * it times how long the user presses a region on the display so it knows whether to invoke auto-update rate or not.
  * keeps track of the settling time of the Analog-Digitial Converter (ADC) used by the controller chip that reads the resistive overlay on the LCD display.

## Implementation

This lab is comprised of several pieces that are described in further details on these pages:

1. Implementing [clockDisplay.c]({% link _pages/clock_display.md %}).
2. Implementing [clockControl.c]({% link _pages/clock_control.md %}).
3. Working with the [touch screen]({% link _pages/touchscreen.md %}).
4. Making sure your code doesn't miss interrupts (described in Milestone 2 below).


### Requirements 
  - You must create files: *clockDisplay.c* and *clockControl.c*. The *clockDisplay* files contain the code that performs all of the updates to the LCD. The *clockControl* files contain the controlling state machine that performs all timing-related functions. You will implement clock control using a single synchronous state machine as discussed in Chapter 5 of the text.
  - *main.c* is given to you.
  - The contents of the *.h* files are provided. Do not modify the *.h* code. Use it as given.
  - You must use the [coding strategy/standard for state machines]({% link _other/coding_state_machines.md %}), including writing a *debugStatePrint()* function.
  - Ensure that you are not missing interrupts.
  - You must implement the clockDisplay code such that it only draws the characters that need to be changed on the screen. Doing so will eliminate annoying flashing artifacts and make things run more smoothly. You cannot get full credit if the screen flashes or **if the TAs determine (by code inspection) that you are drawing characters continuously even if they have not changed.**

### Milestones 

You will complete this lab in two milestones.  You are provided a [main.c](https://github.com/byu-cpe/ecen330_student/blob/master/lab4/main.c).  Do not change it, except to uncomment one of the below lines to run the chosen milestone:

    ////////////////////////////////////////////////////////////////////////////////
    // Uncomment one of the following lines to run Milestone 1 or 2      ///////////
    ////////////////////////////////////////////////////////////////////////////////
    // #define RUN_PROGRAM MILESTONE_1
    // #define RUN_PROGRAM MILESTONE_2


#### Milestone 1:
  * *clockDisplay.c*: You will completely implement the functionality for the display as described above. The text and arrow sizes must be updated when *CLOCKDISPLAY_TEXT_SIZE* is changed.  You must also implement the clockDisplay_runTest() routine described on the clockDisplay webpage.

#### Milestone 2:
  * *clockControl.c*: You will completely implement this file as described above.  Be sure that your clock works correctly and that the increment/decrement functions work for setting time.
  * As a part of this milestone, you must follow the strategy discussed in [coding strategy/standard for state machines]({% link _other/coding_state_machines.md %})  to print out each state as it is entered.  Be sure that the printed output matches the state-machine behavior from the provided state diagram.
  * Use your intervalTimer from last lab to measure how long your *tick()* function takes in the worst case (when you need to draw all digits).  Make sure it runs in less than the timer period ([config.h](https://github.com/byu-cpe/ecen330_student/blob/master/lab4/config.h) defines `#define CONFIG_TIMER_PERIOD 50.0E-3`).
  * The provided main.c will run for 20 seconds, and then exit, reporting the number of interrupts that occurred and the number of interrupts serviced by your code.  Make sure you don't miss more than 1 interrupt (which may happen at the start of your program, even if your tick is short).  If you are missing interrupts, your *tick()* function probably runs too slow.

## Submission & Pass Off
Follow the [instructions on submitting source code]({% link _documentation/submission.md %}) to submit your code.



### Grade Breakdown 
  * 30%: Milestone 1
  * 40%: Milestone 2
    * -10% overall, if missing debug state printing
    * -10% overall, if the isr invocation count differs from internal interrupt count by more than 1     
    * -10% overall, if the clock is not very responsive, if it seems laggy, or if it flashes the display when updating the time.
  * 30%: Code quality (adherence to coding standard).
 


