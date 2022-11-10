---
layout: page
toc: false
title: "C Programming Part 6: Compilation"
---

## Topics
* Preprocessor
* Compiling
* Linking
* GCC
* Declaration vs definition

## Class Slides
- [Slides]({% link media/c/C_part6.pdf %})

## Resources
- [main.c used in class]({% link media/c/main.c %})
- <https://stackoverflow.com/a/1410632/609215>

## Study Questions
1. What is the role of the preprocessor?
1. (T/F) When you include `#include <stdio.h>` in your code, the definition (function body) for the *printf* function is included in your code.
1. (T/F) When you compile two files using `gcc file1.c file2.c`, the compiler will analyze both files together to make sure you are using functions and variables from different files correctly.
1. Why does the C language use header files?
1. Why should you put function prototypes for your helper functions at the top of your .c files?
1. (T/F) Global variables should be defined in header files.
1. If you are compiling your code, and see the error: "undefined reference to 'foo'", what does this mean?
1. If you are compiling your code, and see the error: "multiple definition of 'current_state'", what does this mean?

1. (T/F) Will this code compile?
    ```c
    #include <stdio.h>

    int x;
    int x;

    int main() {
        printf("%d\n", x);
        return 0;
    }
    ```
1. (T/F) Will this code compile?
    ```c
    #include <stdio.h>

    int x;
    int x = 3;

    int main() {
        printf("%d\n", x);
        return 0;
    }
    ```
1. (T/F) Will this code compile?
    ```c
    #include <stdio.h>

    int x = 3;
    int x = 3;

    int main() {
        printf("%d\n", x);
        return 0;
    }
    ```
1. The following files are compiled and linked using the command `gcc main.c foo.c`.  Does this result in a compiler error? Linker error?
    * main.c:
        ```c
        #include <stdio.h>

        int main() {
            int sum = add(3);
            printf("sum: %d\n", sum);
        }
        ```
    * foo.c
        ```c
        int add(int a, int b) {
            return a + b;
        }  
        ```

1. The following files are compiled and linked using the command `gcc main.c foo.c`.  Does this result in a compiler error? Linker error?
    * main.c:
        ```c
        #include <stdio.h>

        int x = 3;

        int main() {
            printf("x: %d\n", increment(x));
        }
        ```
    * foo.c
        ```c
        int x = 4;

        int increment(int x) {
            return x+1;
        } 
        ```

