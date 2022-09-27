---
layout: page
toc: false
title: "K & R Chapter 7 Study Questions"
---


  1. (T or F) The value for EOF is typically -1.
  1. (T or F) Standard output comes from the keyboard.
  1. (T or F) For #include <fileName> searches, the gcc compiler searches for fileName only in the directory where the program is located.
  1. (T or F) caseUpper() is the name of the function that can be used to convert a character to upper case.
  1. (T or F) For printf(), the formatting argument G may generate the same results as the formatting argument f. 
  1. (T or F) `printf("%.*s", 5, "hello there\n");` prints out hello.  
  1. (T or F) `printf("%d\n", 3.0);` prints out 3.0000. 
 
  1. The following program prints out hello there! when executed (T or F).
    ```c
    int main() {
      char array[20];
      sprintf(array, "%s", "hello there!");
    }
```

* (T or F) sscanf() reads characters from standard input.
* What does the following program print when executed and when you type 2 2 2 and press enter (or carriage return).

    ```c
    #include <stdio.h>

    int main() {
      int month, day, year;
      printf("%d\n", scanf("%d %d %d", &month, &day, &year));
    }
    ```

* What does the following program print when executed? Why?
```c
#include <stdio.h>
#include <string.h>
#define LENGTH 100
int main() {
  char string1[LENGTH] = "hello ";
  char string2[LENGTH] = "there";
  strcpy(string1, string2);
  printf("%s\n", string1);
}
```


* What does the following program print when executed? Why?
```c
#include <stdio.h>
#include <string.h>
#define LENGTH 100
int main() {
  char string1[LENGTH] = "hello ";
  char string2[LENGTH] = "there";
  strcat(string1, string2);
  printf("%ld\n", strlen(string1));
}
```

12. What does the program below print out? 
    ```c
    int main() {
        int i=9;
        int j = ((0 > 1) && (i=14));
        printf("%d\n", i);
    }
    ```

13. What does the program below print out? 
    ```c
    int main() {
        int i=9;
        int j = ((0 > 1) || (i=14));
        printf("%d\n", j);
    }
    ```