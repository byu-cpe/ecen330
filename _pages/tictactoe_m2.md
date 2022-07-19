---
layout: page
toc: false
title: "Tic Tac Toe, Milestone 2: ticTacToeDisplay"
---


<iframe width="560" height="315" allow="fullscreen" src="https://www.youtube.com/embed/b_2iwT8TDYc"> </iframe>

Watch the video above to see how your tic-tac-toe board should appear. Your board should look similar. Note a couple of things:
  - The board is comprised of four lines; two horizontal lines and two vertical lines. They are drawn at thirds of the screen (*display_width()/3*, *2*(display_width()/3)*, *display_height()/3*, *2*(display_height()/3)*).
  - The "O" is drawn using display_drawCircle().
  - The "X" is drawn using two display_drawLine()s.
  - As always, you must only update the part of the board that is changing. This is pretty easy with Tic-Tac-Toe because there is no need to erase anything (until you clear the screen prior to starting a new game). The board squares are always empty until you draw either an "X" or a "O".



## Requirements 
  * You are provided [ticTacToeDisplay.h]({{site.github.fileurl}}/lab7_tictactoe/ticTacToeDisplay.h). You will need to create *ticTacToeDisplay.c*, and implement the functions advertised in *ticTacToeDisplay.h*.
  - As described in the associated comments *ticTacToeDisplay_runTest()* does the following when invoked:
    - As you tap the screen in the empty areas between the lines, it will draw either an "X" or a "O" depending upon the position of SW0 (down is "X", up is "O").
    - If you press BTN0, it will clear the screen and redraw the lines.
    - If you press BTN1, the test will terminate and print a message to that effect.
  - Suggestions for *ticTacToeDisplay_runTest()*:
    - While you could implement this behavior with a state machine, since this is test code, it's not required. You will probably find it easier to just use a loop with delay statements.
    - Even though a state machine is not required, you still need to interact with the touch screen correctly:
      * First, wait for a touch using *display_isTouched()*.
      * Next, call *display_clearOldTouchData()*.
      * Then wait for at least 50ms for the analog-to-digital converters to settle (you can use the `utils_msDelay()` function).
      * Call *display_getTouchedPoint(int16_t *x, int16_t *y, uint8_t *z)* to get the touched coordinates.    
    - You don't need to check if the square is unoccupied for this milestone. In other words, you can force an "X" and an "O" to occupy the same space and they can be drawn on top of each other. This is OK only for this milestone.
  
## Notes 
  - Tic-Tac-Toe board rows are horizontal and columns are vertical.
  - Both row and column must be between 0 and 2.
  - row = 0 is the top of the board, row = 2 is the bottom of the board.
  - column = 0 is the far-left of the board, column = 2 is the far-right of the board.
  


