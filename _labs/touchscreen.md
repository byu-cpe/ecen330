---
layout: lab
toc: true
title: "Lab 5: Touchscreen Driver"
short_title: Touchscreen Driver
number: 5
---

## Overview
In this lab you will create a driver for the touchscreen.  The driver will be used to determine the location of where a user touches on the touchscreen and whether they are holding down on the touchscreen, or have released their finger. 

The driver for the touchscreen is a bit different than what you have done in the previous labs where you wrote *low-level drivers* that interfaced directly with hardware.  The touchscreen already comes with a [driver that interfaces with the hardware](https://github.com/byu-cpe/ecen330_student/blob/main/include/display.h#L149-L153), which effectively abstracts away the hardware registers.  However, these driver functions still require you to follow specific timing requirements (eg. after detecting a touch you have to wait 50ms before reading the touched location).  To make it easier to use the touchscreen in later labs, we will write a higher layer driver that will abstract these timing details away, and make it simpler for user code to use the touchscreen.  This approach of having multiple layers of abstraction is commonly done with device drivers.

To handle these timing requirements, you will implement your touchscreen driver as a **State Machine**, which will be ticked concurrently with other state machines in later labs.

You are given a test application shown below that will verify that your driver is working correctly (*the yellow circles in the GIF below show when the mouse button is clicked and are not actually drawn in the test application*).

<img src="{% link media/lab5/touchscreen.gif %}" width="500">

### Objectives
* Gain experience writing a *high-level device driver* that requires meeting specific device timing requirements.
* Gain experience writing a state machine.


## Preliminary

1. Read about the [touchscreen low-level driver]({% link _documentation/touchscreen.md %}).

## Implementation

### Requirements

### Files


## Submission