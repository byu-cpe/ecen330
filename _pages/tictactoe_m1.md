---
layout: page
toc: false
title: "Tic Tac Toe, Milestone 1: minimax"
---

In this milestone you will implement the algorithm for the computer player. If you are successful, it will be impossible to beat the computer when you play against it. We will be using an algorithm called minimax (or something close, anyway). The algorithm is often used to create a computer-player in a two-player game such as Tic-Tac-Toe.

  A very good description using minimax to implement a computer-player for Tic-Tac-Toe can be found <https://www.neverstopbuilding.com/minimax>. I also archived it as [PDF]({% link media/lab5/minimax.pdf %}).

I have annotated some of the figures and will discuss these in class.

<img src="{% link media/lab5/tictactoegametreenotes1.jpg %}" width="800" alt="minimax example diagram #1">

---

<img src="{% link media/lab5/tictactoegametreenotes2.jpg %}" width="800" alt="minimax example diagram #2">


## Tic-Tac-Toe Minimax Pseudocode 

Here is some pseudocode that describes the algorithm in more detail. This should be helpful after you have carefully studied how the algorithm works and you start writing 'C' code.

Notes: 
  * For the pseudocode shown below, **choice** is a global variable that will hold the move computed by minimax. Minimax must return at least a score because that is how you build the move-score table recursively. However, minimax must also compute the move because it is associated with the score. So, when doing the max calculation for example, you find the index of the highest score in the list and then save the move associated with that score in **choice**. **choice** will be overwritten many times as minimax executes but that is OK. The only move you care about is the move associated with the max score at the first call of minimax. That will also be the last time that **choice** is written so it will contain the move you care about - the move associated with the highest score (assuming that you are 'X').
  * move can be implemented as a struct containing a row and a column.
  * You can store your moves and scores in two arrays: a moves array and a scores array. Use one index for both.

```c
// current_player_is_x == true means X, current_player_is_x == false means O
int minimax(board, bool current_player_is_x) {
  if (game is over)   // Recursion base case, there has been a win or a draw.
    // If game is over, you need to evaluate board based upon previous player/opponent.
    return score(board, !current_player_is_x);  
  // Otherwise, you need to recurse.
  // This loop will generate all possible boards.
  for all rows {
    for all columns {
      if (board[row][column] == EMPTY_SQUARE) {
        // Assign the square to 'X'or 'O'.
        if (current_player_is_x) 
          board[row][column] = X_SQUARE
        else 
          board[row][column] = O_SQUARE
        score = minimax(board, !current_player_is_x)
        add score to move-score table
        add move to move-score table
        // Undo the change to the board (return the square to empty) prior to next iteration of for-loops.
        board[row][column] = EMPTY_SQUARE
      }
    }
  }
  // Once you get here, you have iterated over empty squares at this level. All of the scores have been computed
  // in the move-score table for boards at this level. 
  // Now you need to return the score depending upon whether you are computing min or max.
  if (current_player_is_x) {
    choice <= get the move with the highest score in the move-score table.
    score <= highest score in the move-score table.
  } else {
    choice <= get the move with the lowest score in the move-score table.
    score <= lowest score in the move-score table. 
  }
  return score;
}
```

## Suggestions 
  - I suggest that you develop your minimax algorithm on a regular computer. minimax doesn't rely on anything provided by the 330 board and you will be able to debug more quickly because you won't need to wait for downloads, etc. Once you get minimax working it is easy to bring it over to the emulator or the board.
  - It is a good idea to have a printBoard routine that prints out a board. This is very useful when debugging.
  - I found it helpful to break down a winning board into row-based wins, column-based wins, and diagonal-based wins.
  - You can add a depth argument to minimax that can be helpful during debugging. You invoke minimax with a depth of 0 and have minimax print the depth variable when invoked and then incrementing the depth variable when recursing.

## Debugging Recursive Minimax 
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

## Requirements 
  - You will write one file: *minimax.c*. *minimax.h* is provided, and must not be changed.
  - You must provide the functions listed below via the .h file. You must use these data-structures, #define, etc., for the listed functions. Please implement helper functions in the .c file (not advertised in the .h file) to make your code modular and easier to read and to debug.
  - You must test your minimax algorithm by writing at least 10 additional test-boards (see provided test code below). The TA will check for this.

[minimax.h]({{iste.github.fileurl}}/lab5_ttt/minimax.h)

## Pass-Off 
To pass the algorithm milestone, you need to demonstrate your minimax program providing the correct answer for several provided boards and **for 10 additional boards** that you must write. After adding your test boards to the provided test code, test your minimax program using the program shown below.

  * [testBoards.c]({{iste.github.fileurl}}/lab5_ttt/testBoards.c)

**Note: if your minimax algorithm passes these tests, you may still have bugs in your code. These tests are not exhaustive. I strongly advise you to test your minimax code much more thoroughly. Otherwise, you will find that you game may not be unbeatable in the final milestone.**
