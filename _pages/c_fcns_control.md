---
layout: page
toc: false
title: "C Programming Part 5: Functions and Control"
---

## Topics
* Functions
* Control flow (`if`, `switch`, `for`, `while`, `do`)
* `break` & `continue`
* Boolean expressions

## Class Slides
* TBD

## Resources
* <https://en.wikibooks.org/wiki/C_Programming/Procedures_and_functions>
    * *Note:* You can ignore the last section on "Variable-length argument lists".

* <https://en.wikibooks.org/wiki/C_Programming/Program_flow_control>

## Study Questions
1. What is a function?  Does it have a memory address?  What is stored at that address?
1. What makes up the *type* of a function?
1. What is a *static* function?
1. What happens when a function is called before its declaration? Does the compiler generate an error?  Will your code work correctly? (<https://www.geeksforgeeks.org/g-fact-95/>)
1. In C, what values represent *false*, and what values represent *true*?
1. Are these two if statements equivalent?
    ```c
    if (x) {
        ...
    }

    if (x == 1) {
        ...
    }
    ```

1. Are these two if statements equivalent?
    ```c
    if (x) {
        ...
    }

    if (x != 0) {
        ...
    }
    ```

1. Does C have a boolean data type?  What does *\<stdbool.h\>* provide?
1. What is a *conditional expression*?  What is the value of `-1 ? 1 : 0`?
1. What happens if the omit the *break* statement in a switch case?
1. What does *break* do?  If you have a *break* statement in an inner loop, will it break out of the outer loop?
1. What does *continue* do? How is it different than break?
1. Are the three parts of a *for* loop required or optional?

1. What does this code do?  What happens if you remove the `#include <stdlib.h>` line?  Does it still compile? Does it give the same behavior? Why?
    ```c
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
      char str1[] = "1.5";
      char str2[] = "2.0";

      double d1 = atof(str1);
      double d2 = atof(str2);

      printf("Sum of values: %f\n", d1 + d2);
      return 0;
    }
    ```

1. (T or F) This code will terminate after 5 iterations.
    ```c
    #include <stdio.h>

    int main() {
    int val = 5;
    while (val)
    printf("%d\n", val);
    val--;
    }
    ```

1. How many times will this program  print out the statement "did nothing"?
    ```c
    #include <stdio.h>
    int main() {
      int i = 10, j;
      if (i >= 0) // Do nothing if i < 0.
        for (j = 0; j < i; j++)
          if (j == 10) {
            printf("%d\n", j);
            return i;
          } else
            printf("did nothing.\n");
    }
    ```

1. What will the following program will print out:
    ```c
    #include <stdio.h>
    int main() {
      int x = 10;
      if (x > 0)
        printf("1\n");
      else if (x > 1)
        printf("2\n");
      else if (x > 2)
        printf("3\n");
      else
        printf("4\n");
    }
    ```

1. How many times will this program will print out "1"?
    ```c
    #include <stdio.h>

    int main() {
      int i = 2;
      switch (i) {
      case 1:
        printf("1\n");
        break;
      case 2:
        printf("1\n");
      case 3:
        printf("1\n");
        break;
      case 4:
        printf("1\n");
        break;
      }
    }
    ```

1. (T or F) The functions p1 and p2 have the same behavior.
    ```c
    #include <stdio.h>
    void p1() {
      int x;
      x = 0;
      while (x < 5) {
        printf("looped\n");
        x++;
      }
    }

    void p2() {
      int x;
      for (x = 0; x < 5; x++)
        printf("looped\n");
    }

    int main() {
      p1();
      p2();
    }
    ```


1. What is the last thing this program will print?:
    ```c
    #include <stdio.h>
    int main() {
      int x = 0;
      for (;;) {
        printf("%d\n", x++);
        if (x > 2)
          break;
      }
    }
    ```

1. How many times will this program print hi!?
    ```c
    #include <stdio.h>
    int main() {
      int i = 0;
      do
        printf("hi!\n");
      while (i);
    }
    ```

1. How many times will this program print "hi!"?
    ```c
    #include <stdio.h>
    int main() {
      while (1) {
        printf("hi!\n");
        break;
      }
    }
    ```

1. How many times will this program print "hi!"?
    ```c
    #include <stdio.h>
    int main() {
      while (1) {
        printf("hi!\n");
        continue;
      }
    }
    ```

1. How many times will this program print "hi!"?
    ```c
    #include <stdio.h>
    int main() {
      int i;
      for (i = 0; i < 10; i++) {
        if (i % 2)
          continue;
        printf("hi!\n");
      }
    }
    ```

1. How many times will this program print "hi!"?
    ```c
    #include <stdio.h>
    int main() {
      int i;
      for (i = 0; i < 10; i++) {
        if (i % 2)
          break;
        printf("hi!\n");
      }
    }
    ```
