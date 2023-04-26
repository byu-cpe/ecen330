---
layout: page
toc: false
title: "K&R Study Questions"
indent: 0
number: 1
---


Try to answer questions from the study list as you read each chapter. Some test questions are likely to be derived from these study questions. 


## Running Code
You may find it helpful to compile and run code yourself.  This can be done by:
  * Running on the board (You can modify your lab1 program, or copy your lab1 folder to another directory and use that)
  * Compiling and running in Linux (we have provided a [playground](https://github.com/byu-cpe/ecen330_student/tree/main/playground) directory where you can modify main.c, run `make` to compile, and then run using `./main`.)
  * Manually compile a file using gcc: `gcc studyQuestions.c`, and then run the produced executable: `./a.out`

In some of the provided code files, you will see individual sections of code surrounded by preprocessor macros:
```
#ifdef Q6
...
#endif
```

In this case, you will need to define `Q6` to compile that code.  You can do that using either of these techniques:
  * `gcc -D Q6 ch2_studyQuestions.c`
  * `make CFLAGS=-DQ6`

## Chapters
* [K & R Chapter 1]({% link _pages/kr_ch1.md %})
* [K & R Chapter 2]({% link _pages/kr_ch2.md %})
* [K & R Chapter 3]({% link _pages/kr_ch3.md %})
* [K & R Chapter 4]({% link _pages/kr_ch4.md %})
* [K & R Chapter 5]({% link _pages/kr_ch5.md %})
* [K & R Chapter 6]({% link _pages/kr_ch6.md %})
* [K & R Chapter 7]({% link _pages/kr_ch7.md %})

