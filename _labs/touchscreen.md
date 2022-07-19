---
layout: lab
toc: true
title: "Lab 5: Touchscreen Driver"
short_title: Touchscreen Driver
number: 5
order: 5
---

## Overview
In this lab you will create a driver for the touchscreen.  The driver will be used to determine the location of where a user touches on the touchscreen and whether they are holding down on the touchscreen, or have released their finger. 

The driver for the touchscreen is a bit different than what you have done in the previous labs where you wrote *low-level drivers* that interfaced directly with hardware.  The touchscreen already comes with a [driver that interfaces with the hardware]({{site.github.fileurl}}/include/display.h#L149-L153), which effectively abstracts away the hardware registers.  However, these driver functions still require you to follow specific timing requirements (eg. after detecting a touch you have to wait 50ms before reading the touched location).  To make it easier to use the touchscreen in later labs, we will write a higher layer driver that will abstract these timing details away, and make it simpler for user code to use the touchscreen.  This approach of having multiple layers of abstraction is commonly done with device drivers.

To handle these timing requirements, you will implement your touchscreen driver as a **State Machine**, which will be ticked concurrently with other state machines in later labs.

You are given a test application shown below that will verify that your driver is working correctly (*the yellow circles in the GIF below show when the mouse button is clicked and are not actually drawn in the test application*).

<img src="{% link media/lab5/touchscreen.gif %}" width="500" alt="Touchscreen test application demo">

### Objectives
* Gain experience writing a *high-level device driver* that requires meeting specific device timing requirements.
* Gain experience writing a state machine.


## Preliminary

1. **Hardware**. Read about the [touchscreen]({% link _documentation/touchscreen.md %}).

1. **Driver Interface**. Read through the interface for your driver, provided in [touchscreen.h]({{site.github.fileurl}}/drivers/touchscreen.h).

1. **State Machine Class Notes**.  We will discuss the touchscreen driver state machine in class using [these slides]({% link media/touchscreen/touchscreen.pdf %}).

1. **Building the code:** 
    * **Driver:** 
        * This driver will be written in *drivers/touchscreen.c*, which you must create yourself.  Uncomment the two lines in the *drivers* [CMakeLists.txt]({{site.github.fileurl}}/drivers/CMakeLists.txt) file so that the *touchscreen* library is built.  

    * **Application Code:**
        * You are provided with the test application.  Just update the top-level [CMakeLists.txt]({{site.github.fileurl}}/CMakeLists.txt) and add a `add_subdirectory(lab5_touchscreen)` statement.

## Implementation

### Requirements

1. Write a driver that uses a state machine to implement the functions defined in [touchscreen.h]({{site.github.fileurl}}/drivers/touchscreen.h).  See comments in this file for details on the behavior of each function.

1. Your state machine must include debug functionality to print out each state as it is entered, as discussed in [coding strategy/standard for state machines]({% link _other/coding_state_machines.md %}).  This must be enabled in your submitted code.

### Files
  - **Submitted files:** *drivers/touchscreen.c*
  - Do not change or create any other files.

## Submission
Follow the [instructions on submitting source code]({% link _documentation/submission.md %}) to submit your code.

### Grade Breakdown 
  * 80%: Driver and test application functionality.
    * -20% overall if your code does not print the debug state messages when run. 
  * 20%: Coding standard