---
layout: page
toc: false
title: "Tic Tac Toe, Milestone 2: ticTacToeControl"
short_title: "M2: Control"
order: 7.2
indent: 1
---
The description of the control milestone is straightforward. You are to implement the control of the game so it behaves just like tic-tac-toe demo video shown in the video below.

<iframe width="560" height="315" allow="fullscreen" src="https://www.youtube.com/embed/eWaILq-u0jQ"> </iframe>


## Preliminary

  * You are provided with code to handle drawing the tic-tac-toe graphics:
    * [ticTacToeDisplay.h]({{site.github.fileurl}}/lab7_tictactoe/ticTacToeDisplay.h) and [ticTacToeDisplay.c]({{site.github.fileurl}}/lab7_tictactoe/ticTacToeDisplay.c) 
    * This provides functions to draw the board lines, draw and erase Xs and Os, and to translate a touchscreen point to a board grid location.
 
  * [ticTacToeControl.h]({{site.github.fileurl}}/lab7_tictactoe/ticTacToeControl.h) is provided to you.  It declares two functions, *ticTacToeControl_init()* and *ticTacToeControl_tick()*.  You must create a *ticTacToeControl.c* file to implement this milestone.

## Requirements
  - Implement an unbeatable tic-tac-toe game, as shown in the video above.
  - Upon completion of a game, pressing BTN0 should start another game.
  - While much of the graphics will be done by *ticTacToeDisplay*, some graphics (such as as drawing and erasing the starting instructions) will be done by *ticTacToeControl*. 
  - The provided *main.c* will run for 20 seconds, and then print the number of interrupts fired and handled.  Once again, make sure you are not missing more than one interrupt.

### Other Notes
  * `display_fillScreen` takes a long time to run.  If you call it from within a tick of your state machine, you will likely miss interrupts.  Instead, you can call it once from your init function (since this is run before interrupts start), but after that point, you should erase individual items instead of clearing the screen.
    * After instructions are displayed, erase them instead of filling the screen.
    * At the end of a game, and when staring a new game, erase individual Xs and Os instead of filling the screen.
  * You may want to use your intervalTimer to accurately measure how long operations take (such as calling your minimax on an empty board). This will help you solve the problem of missing interrupts.
  * You must follow the coding standard, including the [Coding Standard for State Machines]({% link _other/coding_state_machines.md %}).  You don't need to include a debug print of your states, but you may find it helpful to do so.