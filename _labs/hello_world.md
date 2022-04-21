---
layout: lab
toc: true
title: "Lab 1: Hello World on the 330 Board"
short_title: Hello World
number: 1
---

## Overview
This lab will show you how to compile and run a simple program on the Zybo board (or using the Zybo board emulator).

You will be given a program that prints "Hello World" to the console, as well as on the LCD screen as shown below:

<img src="{% link media/lab1/helloworld.jpg %}" alt="LCD screen showing 'Hello World' text">


You will then modify the program to draw some graphics on the LCD screen as shown here:

<img src="{% link media/lab1/shapes.jpg %}" alt="LCD screen showing arrangement of four shapes">


## Objectives
  - Learn how to compile and run programs on the 330 board/emulator.
  - Introduce the CMake build system, and the Visual Studio Code editor.
  - Become familiar with the graphics routines that are available for use with the LCD display.
  - Learn some of the issues with printf().

## Preliminary


### Computer Setup

Complete [Setup Step #1]({% link _setup/step_1.md %}) and [Setup Step #2]({% link _setup/step_2.md %}), linked to on the left-hand pane.  This will take some time, so start early.

<ins>**Follow all steps carefully.  Make sure everything if working before proceeding.  If you get stuck during a setup step, DO NOT SKIP IT.  Ask for help on Piazza**</ins>.

### Compile and Run the Lab1 Code

Carefully read the entire page on [Compiling Code]({% link _documentation/compiling.md %}).  **Follow the steps to compile the Lab1 code and run it on the board or emulator.**

## Implementation
1. When you provide characters to the *printf* function,  the characters are temporarily stored in a buffer, and then output to the terminal (also called *flushed*) in groups.  Normally the buffer is flushed at every new line character, but also when the program ends.
  * Modify the first *hello world* program and remove the `\n` from the string used in the *printf* function and recompile and execute the program. What happens? Does *hello world!* still appear in the console?
  * Now add a `while (1);` statement after the printf so that your program never ends.  Recompile and execute.  Does *hello world!* still appear in the console?

    *This is just for your own experimentation.  You can remove these changes now.*

2. Read the graphics documentation and then modify *main.c* so that it shows the graphics from the picture above (both triangles are yellow).


##  Submission and Pass Off
For every lab you will follow the same submission instructions, provided at the [Submitting Source Code]({% link _documentation/submission.md %}) page.

### Grade Breakdown
  * 70% Pass off. Your code demonstrates correct functionality.
  * 30% Coding standard. You are allowed 20 freebies for this lab.
    * Read over the [coding standard]({% link _other/coding_standard.md %}), including the section at the bottom that discusses how your code is graded against the coding standard.

<!--  * Pass-off (ie, correct functionality): 100%
  * Coding standard: 0%
    * You will still receive a coding standard grade out of 30 points, so that you can get feedback on your adherence to the coding standard; however, it won't affect your grade.-->


## Resources

  - [ZYBO Board Documentation]({% link media/lab1/zybo_rm_b_v6.pdf %}) The ZYBO board is commercially available from digilentinc.com.
  - [VS Code Tips]({% link _documentation/vscode.md %})
  - [Graphics Library Documentation]({% link media/lab1/adafruit-gfx-graphics-library.pdf %})
    * This is a description of the graphics software that is available for use with the 330 board. I ported over this software from Adafruit (they sell the LCD panel that is mounted on the 330 board).
    * If you add the prefix "display_" to the function names described in this document, most (not quite all) of the functions are available for use with the ZYBO board, e.g., `drawLine()` becomes `display_drawLine()`.
    * Take a look at [include/display.h](https://github.com/byu-cpe/ecen330_student/blob/master/include/display.h). Also, note that *DISPLAY_WIDTH* and *DISPLAY_HEIGHT* are defined in display.h to be the correct values for height and width of the display. *display.h* is also listed in the source-code section for your convenience.


## Suggestions
  - Carefully read **every word** of the lab description. These lab descriptions have been refined over many years based upon student feedback. In most cases, the answers to your questions are usually present in the lab description. It is good practice to become very skilled at reading documentation as you will find that there are no TAs in industry. In general, students who read the lab description very carefully **before coding anything** complete the lab much more quickly than those who tend to scan the description and jump directly to coding. That said, if something is still unclear after you carefully read the lab description, let me know and I will try to fix it. I value student feedback.
  - I strongly advise against a "trial and error" approach when writing the code to draw the lines, circles and triangles. It takes up to a minute each time you build your code and download to the board and this adds up quickly, time-wise. A better approach is to draw a picture of the display and to determine the actual coordinates before writing any code.
  - The sizes of the triangles and circles don't need to match my picture exactly, but they should be reasonably close.
  - If you are having problems programming the board, ensure that the programming jumper is set correctly. I went through all of the boards in the shop and I think that I set all of them, but double-check this if you are having problems programming the board. The jumper needs to placed over the rightmost two pins as shown in the picture below.
  - The main.c file contains a function called isr_function(). You will not use this function for this lab, but it must be defined or you will get a linker error. You will do more with this function in later labs.

<img src="{% link media/lab1/jumper_setting.jpg %}" alt="Jumper settings for Zybo board">

