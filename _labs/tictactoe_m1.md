---
layout: page
toc: false
title: "Tic Tac Toe, Milestone 1: minimax"
short_title: "M1: Minimax"
order: 7.1
indent: 1
---

In this milestone you will implement the algorithm for the computer player. If you are successful, it will be impossible to beat the computer when you play against it. We will be using an algorithm called minimax (or something close, anyway). The algorithm is often used to create a computer-player in a two-player game such as Tic-Tac-Toe.

## Preliminary

1. **Class Notes:**:  We will discuss the minimax algorithm in class using [these slides]({% link media/tictactoe/tictactoe.pdf %}).

1. **Review Pseudocode:** Here is some pseudocode that describes the algorithm in more detail. This should be helpful after you have carefully studied how the algorithm works and you start writing 'C' code.
  * *minimax* computes the optimal move (location and score), for a given board:
    * The score is needed at each level of the recursion to fill in the *move*-*score* table, so it the return value of *minimax*.
    * The location is only needed for the first invocation of *minimax*, so it is just stored in global variable, **choice**.  This will be overwritten at each level of the recursion, but when you finally complete the *minimax* function, the last value set in *choice* will be for the board you provided to *minimax*, which is the move location you want.
  * Move can be implemented as a struct containing a row and a column (*tictactoe_location_t*)
  * You can store your *move*-*score* table as two arrays: a moves array and a scores array. Use one index for both.
      
    ```c
    minimax_score_t minimax(board, bool is_Xs_turn) {

      if (game is over)
        // Recursion base case, there has been a win or a draw.
        // Evaluate board based upon prev player's turn.
        return computeBoardScore(board, !is_Xs_turn);

      // Otherwise, you need to recurse.
      // This loop will generate all possible boards and call
      // minimax recursively for every empty square
      for (all rows) {
        for (all columns) {
          if (board[row][column] == EMPTY_SQUARE) {

            // Simulate playing at this location
            board[row][column] = current_player_is_x ? X_SQUARE : O_SQUARE;

            // Recursively call minimax to get the best score, assuming player
            // choses to play at this location.
            score = minimax(board, !is_Xs_turn);

            add score to move - score table;
            add move to move - score table;

            // Undo the change to the board
            board[row][column] = EMPTY_SQUARE;
          }
        }
      }

      // Once you get here, you have iterated over empty squares at this level. All
      // of the scores have been computed in the move-score table for boards at this
      // level. Now you need to return the score depending upon whether you are
      // computing min or max.
      if (is_Xs_turn) {
        choice = get the move with the highest score in the move - score table.;
        score = highest score in the move - score table.;
      } else {
        choice = get the move with the lowest score in the move - score table.;
        score <= lowest score in the move - score table.;
      }
      return score;
    }
    ```

1. **Header files:** 
  * Several helpful data types are provided in [ticTacToe.h]({{site.github.fileurl}}/lab7_tictactoe/ticTacToe.h)
        - Note: Tic-Tac-Toe board rows are horizontal and columns are vertical (row = 0 is the top of the board, row = 2 is the bottom of the board, column = 0 is the far-left of the board, column = 2 is the far-right of the board).
  * Review the provided [minimax.h]({{site.github.fileurl}}/lab7_tictactoe/minimax.h)

1. **Test boards:** [testBoards.h]({{site.github.fileurl}}/lab7_tictactoe/testBoards.h) and [testBoards.c]({{site.github.fileurl}}/lab7_tictactoe/testBoards.c) provides code that creates five test board that you can use to test your minimax algorithm.
 
## Implementation

### Requirements 
  - Implement the functions declared in *minimax.h* in your *minimax.c* file.
  - Update *testBoards.c* by adding at least 10 additional unique test-boards (see provided test code below). 
  - When the *lab7_m1.elf* executable is run, you should see the *Next Move* output for the five provided boards, and your (at least 10) additional boards.


  
## Suggestions 
  - I suggest that you develop your minimax algorithm on a regular computer (or the emulator). minimax doesn't rely on any hardware or drivers for the 330 board and you will be able to debug more quickly because you won't need to wait for downloads, etc. Once you get minimax working it is easy to bring it over to the the board.
  - It is a good idea to have a printBoard routine that prints out a board. This is very useful when debugging.
  - I found it helpful to break down a winning board into row-based wins, column-based wins, and diagonal-based wins.
  - You can add a depth argument to minimax that can be helpful during debugging. You invoke minimax with a depth of 0 and have minimax print the depth variable when invoked and then incrementing the depth variable when recursing.
  - **Even with several test boards, you may still have bugs in your code. I would advise you to create several tests with varied boards.  Otherwise, you will find that your game may not be unbeatable in the next milestone.**


### Debugging Recursive Minimax 
Often the best way to debug recursive programs is to print out an execution trace. Adding a "depth" argument that you increment at each invocation makes it much easier to follow program execution.

A debug dump of my minimax program is shown below. The starting board is the same as the board we used in class and is the same one in the game-trees shown above. I have annotated the dump with the board-numbers used in the example shown above.

```
Invoking minimax @ depth = 0
**Board 1**
0 X
X  
X00
adding player @ (0, 1)

Invoking minimax @ depth = 1
**Board 3**
0XX
X  
X00
adding opponent @ (1, 1)

Invoking minimax @ depth = 2
**Board 5**
0XX
X0 
X00
opponent wins, returning score: -10
adding opponent @ (1, 2)

Invoking minimax @ depth = 2
**Board 6**
0XX
X 0
X00
adding player @ (1, 1)

Invoking minimax @ depth = 3
**Board 9**
0XX
XX0
X00
player wins, returning score: 10
adding player @ (1, 1)

Invoking minimax @ depth = 1
**Board 2**
0 X
XX 
X00
player wins, returning score: 10
adding player @ (1, 2)

Invoking minimax @ depth = 1
**Board 4**
0 X
X X
X00
adding opponent @ (0, 1)

Invoking minimax @ depth = 2
-- Starting board -- **Board 8**
00X
X X
X00
adding player @ (1, 1)

Invoking minimax @ depth = 3
**Board 10**
00X
XXX
X00
player wins, returning score: 10
adding opponent @ (1, 1)

Invoking minimax @ depth = 2
**Board 7**
0 X
X0X
X00
opponent wins, returning score: -10
final score: 10
final choice: (row: 1, column: 1)

```


