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
  * Overview



1. [Part 1: Overview]({% link _pages/c_part1.md %})
  * <https://en.wikibooks.org/wiki/C_Programming/Intro_exercise>
  * <https://en.wikibooks.org/wiki/C_Programming/Preliminaries>
  * <https://en.wikibooks.org/wiki/C_Programming/Structure_and_style>

2. [Part 2: Variables]({% link _pages/c_part2.md %})
  * <https://en.wikibooks.org/wiki/C_Programming/Variables>

* [K & R Chapter 4]({% link _pages/kr_ch4.md %})
  * Functions, scope, 


3. Printf
  * https://en.wikibooks.org/wiki/C_Programming/Simple_input_and_output
* [K & R Chapter 7]({% link _pages/kr_ch7.md %})
  * I/O

4. Operators https://en.wikibooks.org/wiki/C_Programming/Operators_and_type_casting
* [K & R Chapter 2]({% link _pages/kr_ch2.md %})
  * Types and operators

5. Arrays/Strings https://en.wikibooks.org/wiki/C_Programming/Arrays_and_strings

6. Control Flow: https://en.wikibooks.org/wiki/C_Programming/Program_flow_control
* [K & R Chapter 3]({% link _pages/kr_ch3.md %})
  * Control flow

7. Structs/Enums: https://en.wikibooks.org/wiki/C_Programming/Advanced_data_types
* [K & R Chapter 6]({% link _pages/kr_ch6.md %})
  * Structures

8. Pointers: https://en.wikibooks.org/wiki/C_Programming/Pointers_and_arrays
* [K & R Chapter 5]({% link _pages/kr_ch5.md %})
  * Pointers




