---
layout: page
toc: false
title: "C Programming Part 2: Variables"
---


## Topics
* Declaring, Initializing, and Assigning Variables
* `int`, `char` `float` and `double` types
* `<stdint.h>` types
* Literals
* Magic numbers: `const` and `#define`
* `static` and `extern` modifiers
* `enum` type

## Class Slides
* [Slides]({% link media/c/C_part2.pdf %})

## Resources
* <https://en.wikibooks.org/wiki/C_Programming/Variables>
* <https://en.wikibooks.org/wiki/C_Programming/Advanced_data_types#Enumerations>

## Study Questions
1. What are **variables**?
1. What is a variable's *type* and *size*?
1. What does it mean that C is **typed**?
1. Does an assignment statement return a value?
1. What characters can you use in your variable names?
1. How do you use hex literals in C?
1. What is the `char` datatype used for?
1. Can you use the `char` datatype to store integers?
1. (T/F) Floating point types can represent any fractional value.
1. What is the value of `sizeof(char)`? `sizeof(int)`? `sizeof(int32_t)`?
1. (T/F) A `long int` is always larger than an `int`?
1. What does the `const` qualifier do?
1. What does `#define` do?
1. Should you end `#define` directives with a semicolon?
1. What happens if you put `static` in front of:
   * A function?
   * A global variable?
   * A local variable?
1. What is `extern` used for?  Does it allocate memory for variables?
1. What is the `enum` type used for? What value does it start at? Can you override it?


1. What does the following code print?
    ```c
    #include <stdio.h>

    #define PLUS1 x+1
    int main() {
      int x = 10;
      int y = 5 * PLUS1;
      printf("%d\n", y);
    }
    ```

1. What is the name of the mystery function shown below (it is a standard library function):
    ```c
    int mystery(char s[]) {
        int i = 0;
        while (s[i] != '\0')
            ++i;
        return i;
    }
    ```

1. What does the code below print out?
    ```c
    #include <stdio.h>

    int main() {
        enum {hello=3, goodbye} myEnum = goodbye;
        printf("%d\n", myEnum);
    }
    ```

1. (T or F) In the program above, myEnum is an automatic (local) variable.


1. What does the following program print out? 
    ```c
    #include <stdio.h>

    int main() {
        printf("%d\n", '1');
    }
    ```

1. What does the following program print out? 
    ```c
    #include <stdio.h>

    int main() {
        printf("%d\n", "13");
    }
    ```

