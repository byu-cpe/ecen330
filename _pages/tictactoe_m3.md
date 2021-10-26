---
layout: page
toc: false
title: "Tic Tac Toe, Milestone 3: ticTacToeControl"
---
<iframe width="560" height="315" allow="fullscreen" src="https://www.youtube.com/embed/eWaILq-u0jQ"> </iframe>

The description of the control milestone is straightforward. You are to implement the control of the game so it behaves just like tic-tac-toe demo video shown in the video above.

## Requirements

  - Upon completion of a game, pressing BTN0 should start another game.
  - [ticTacToeControl.h](https://github.com/byu-cpe/ecen330_student/blob/master/lab5/ticTacToeControl.h) is provided to you.  It declares two functions, *ticTacToeControl_init()* and *ticTacToeControl_tick()*.  You should not modify this file.
  - You must create a *ticTacToeControl.c* file.
  - Use the same structure for the control as was required for the previous clock lab.  A good way to start would be to copy the state enum declaration from the clock lab and modify it with the state names you will use for this lab.
  - Like the clock lab, the provided *main.c* will run for 20 seconds, and then print the number of interrupts fired and handled.  Once again, make sure you are not missing more than one interrupt. 
  - Just like the clock lab, use your intervalTimer to determine the worst-case execution time for your tick. Worst case occurs when minimax is called with an empty board. This will help you solve the problem of missing interrupts.
  - You must follow the coding standard, including the [Coding Standard for State Machines]({% link _other/coding_state_machines.md %}).