---
layout: lab
toc: true
title: "Lab 5: Tic Tac Toe"
short_title: Tic Tac Toe
number: 5
---

{{ tictactoe.jpg?400 }}

===== Overview =====

For our next lab, we will implement a program that can play an **unbeatable** game of Tic-Tac-Toe. This project will consist of three individual milestones that you will pass off one-by-one (display, algorithm, control). That way you can get partial credit if you don't complete the entire lab. **A word of warning: some of you may find this lab very challenging.** You will implement the algorithm for the computer player using a recursive minimax search. The algorithm is not that complex but recursive algorithms can be a challenge to debug so start early to give yourself extra time. If you are a little squeamish about recursion, make sure to start early.




This lab will consist of three milestones:
  - **Algorithm**. You will write the software that makes it impossible to beat the computer.
  - **Display**. You will write the routines that implement the Tic-Tac-Toe board and the drawing of the X's and the O's.
  - **Control**. You will implement the game control using the state-machine concepts discussed in the class, similar to what you did for the clock lab.

You will implement and test the Display and Algorithm milestones separately. The Control milestone will bring everything together to implement the entire game.

----
===== Objectives =====
  - Practice developing your own state diagrams.
  - More practice implementing synchronous state machines.
  - Practice implementing and debugging your synchronous controller state machine.
  - Gain more experience using the touch-controller and graphics library.
  - Develop your own state-diagram for control and implement it using the synchronous state-machine techniques discussed in class.
  - Implement a recursive mini-max algorithm and use it to create an unbeatable game of tic-tac-toe.

----

===== Preliminary =====

==== Building this Lab ====
All of your code for this lab will written in the ''lab5'' directory.  You will need to create a ''CMakeLists.txt'' file in this directory to build the clock application and link it to any necessary libraries.


----
==== Program Organization ====
The program is divided into three main parts or packages: 
  - minimax: provides the algorithm that you will need to create your unbeatable game.
  - ticTacToeDisplay: provides the functions to draw the board and players "X" and "O".
  - ticTacToeControl: provides the top-level control of the game, invoking minimax and the display functions as necessary.

----

===== Implementation =====
Your program will be implemented in three separate milestones that correspond to the three different packages that you will implement: ticTacToeDisplay, minimax, ticTacToeControl. Each milestone will be checked by the TAs separately and the requirements are stated at the end of the description for each of the milestones below.

Like previous labs, you are provided with a ''main.c'' file that will run the different milestones.  Do not change the file, except to uncomment the appropriate line to run the desired milestone.

<code c>
////////////////////////////////////////////////////////////////////////////////
// Uncomment one of the following lines to run Milestone 1, 2, or 3    /////////
////////////////////////////////////////////////////////////////////////////////
// #define RUN_PROGRAM MILESTONE_1
// #define RUN_PROGRAM MILESTONE_2
// #define RUN_PROGRAM MILESTONE_3
</code>

1. [[Lab 5 Milestone 1| Milestone 1: Minimax Algorithm Details and Pass-Off]]\\
2. [[Lab 5 Milestone 2 | Milestone 2: Minimax Display Details and Pass-Off]]\\
3. [[Lab 5 Milestone 3 | Milestone 3: Minimax Game and Control Details and Pass-Off]]\\

----


===== Submission & Pass Off =====
Follow the [[submitting_source_code|instructions on submitting source code]] to submit your code.

==== Grade Breakdown====  
  * Milestone 1 (algorithm): 25%
    * -10% overall, if you don't create and print the output of the 10 extra test boards.
  * Milestone 2 (display): 10%
  * Milestone 3 (control): 35%
    * -10% overall, if you miss more than 1 interrupt
    * -15% overall, if your game is not unbeatable
    * -10% overall, if you are unable to make your game play at the same speed as the video
    * -10% overall, if your game allows strange game play: overwriting of X's and O's, cheating, playing after the game is over, etc.
  * Code Quality (adhering to the coding standard): 30%

