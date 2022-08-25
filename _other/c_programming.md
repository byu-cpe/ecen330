---
layout: page
toc: false
title: "'C Programming' Study Questions"
indent: 0
number: 1
---


Try to answer questions from the study list as you read each chapter. Some test questions are likely to be derived from these study questions. 


## Running Code
You may find it helpful to compile and run code yourself.  This can be done by:
  * Running on the board (You can modify your lab1 program, or copy your lab1 folder to another directory and use that)
  * Compiling and running in Linux (we have provided a [playground](https://github.com/byu-cpe/ecen330_student/tree/main/playground) directory where you can modify main.c, run `make` to compile, and then run using `./main`.)
  * Manually compile a file using gcc: `gcc studyQuestions.c`, and then run the produced executable: `./a.out`

In some of the provide code files, you will see individual sections of code surrounded by preprocessor macros:
```
#ifdef Q6
...
#endif
```

In this case, you will need to define `Q6` to compile that code.  You can do that using either of these techniques:
* `gcc -D Q6 ch2_studyQuestions.c`p
  * `make CFLAGS=-DQ6`

## C Programming

## Chapters
1. [Part 1: Overview]({% link _pages/c_overview.md %})
1. [Part 2: Variables]({% link _pages/c_variables.md %})
1. [Part 3: Printf and Data Representation]({% link _pages/c_printf.md %})
1. [Part 4: Arrays, Strings, and Structs]({% link _pages/c_arrays_structs.md %})
1. [Part 5: Functions and Control Flow]({% link _pages/c_fcns_control.md %})
1. [Part 6: C Compilation]({% link _pages/c_compilation.md %})
1. [Part 7: Pointers I]({% link _pages/c_pointers_i.md %})
1. [Part 8: Pointers I]({% link _pages/c_pointers_ii.md %})
1. [Part 9: Memory Layout, Stack and Heap]({% link _pages/c_stack_heap.md %})






