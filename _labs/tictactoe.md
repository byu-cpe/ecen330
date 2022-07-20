---
layout: lab
toc: true
title: "Lab 7: Tic Tac Toe"
short_title: Tic Tac Toe
number: 7
order: 7
---


## Overview 

For this lab you will implement a program that can play an **unbeatable** game of Tic-Tac-Toe. This project will consist of two individual milestones that will be graded separately (algorithm and control). 
That way you can get partial credit if you don't complete the entire lab. 
**A word of warning: some of you may find this lab very challenging.** 
You will implement the algorithm for the computer player using a recursive minimax search. 
The algorithm is not that complex but recursive algorithms can be a challenge to debug so start early to give yourself extra time. If you are a little squeamish about recursion, make sure to start early.

<img src="{% link media/lab5/tictactoe.jpg %}" width="400" alt="Tic tac toe board on LCD">


You will implement and test the Display and Algorithm milestones separately. The Control milestone will bring everything together to implement the entire game.

### Objectives 
  - Implement a recursive algorithm and use it to create an unbeatable game of tic-tac-toe.
  - Practice developing and debugging your own state machines.
  - Practice structs, arrays and more complex C code.

## Preliminary 

1. **Program Organization:** The program is divided into three main parts or packages: 
  - *minimax*: provides the algorithm that you will need to create your unbeatable game.  You will implement this in Milestone 1.
  - *ticTacToeDisplay*: provides the functions to draw the board and players "X" and "O".  This module is provided to you.
  - *ticTacToeControl*: provides the top-level control of the game, invoking minimax and the display functions as necessary. You will implement this as Milestone 2.

2. **Compiling:** You will need to write your own *CMakeLists.txt* file to compile the programs:
  * [main_m1.c]({{site.github.fileurl}}/lab7_tictactoe/main_m1.c) can be compiled to create the Milestone 1 test executable.
  * [main_m2.c]({{site.github.fileurl}}/lab7_tictactoe/main_m2.c) can be compiled to create the Milestone 2 test executable.
  * You can look at the Lab 3 *CMakeLists.txt* file for an example of compiling one executable for each milestone.

## Implementation 
See Milestone pages:
  * [Milestone 1: minimax]({% link _labs/tictactoe_m1.md %})
  * [Milestone 2: Control]({% link _labs/tictactoe_m3.md %})


### Files
  - **Submitted files:** *lab7_tictactoe/minimax.c*, *lab7_tictactoe/testBoards.c* and *lab7_tictactoe/ticTacToeControl.c*
  - Do not modify any other files are create any other new files.

## Submission & Pass Off
Follow the [instructions on submitting source code]({% link _documentation/submission.md %}) to submit your code.

### Grade Breakdown 
  * Milestone 1 (algorithm): 40%
    * -10% overall, if you don't create and print the output of the 10 extra test boards.
  * Milestone 2 (control): 40%
    * -10% overall, if you miss more than 1 interrupt
    * -15% overall, if your game is not unbeatable
    * -10% overall, if you are unable to make your game play at the same speed as the video
  * Code Quality (adhering to the coding standard): 20%

