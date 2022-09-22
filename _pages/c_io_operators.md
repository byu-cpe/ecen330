---
layout: page
toc: false
title: "C Programming Part 3: I/O and Operators"
---

## Topics
* printf function and format specifiers
* `sscanf`, and `sprintf`
* Operators

## Class Slides
* [Slides]({% link media/c/C_part3.pdf %})

## Resources
* <https://en.wikibooks.org/wiki/C_Programming/Simple_input_and_output>
* <https://en.wikibooks.org/wiki/C_Programming/Operators_and_type_casting>
* <https://cplusplus.com/reference/cstdio/printf/>
* <https://cplusplus.com/reference/cstdio/sprintf/>

## Study Questions
  1. (T or F) `printf("%c\n", 'a');` will print the character *a*.
  1. (T or F) `printf("%s\n", 'a');` will print the character *a*.
  1. (T or F) `printf("%.*s", 5, "hello there\n");` prints out *hello*.  
  1. (T or F) For printf(), the formatting argument G may generate the same results as the formatting argument f. 

 
1. The following program prints out hello there! when executed (T or F).
    ```c
    int main() {
      char array[20];
      sprintf(array, "%s", "hello there!");
    }
```

1. (T or F) sscanf() reads characters from standard input.
1. What does the following program print when executed and when you type 2 2 2 and press enter (or carriage return).

    ```c
    #include <stdio.h>

    int main() {
      int month, day, year;
      printf("%d\n", scanf("%d %d %d", &month, &day, &year));
    }
    ```

1. What does the following program print when executed? Why?
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


1. What does the following program print when executed? Why?
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

1. What does the program below print out? 
    ```c
    int main() {
        int i=9;
        int j = ((0 > 1) && (i=14));
        printf("%d\n", i);
    }
    ```

1. What does the program below print out? 
    ```c
    int main() {
        int i=9;
        int j = ((0 > 1) || (i=14));
        printf("%d\n", j);
    }
    ```

1. What does the following program print out? 
    ```c 
    #include <stdio.h>

    int main() {
        int i = 0 < 1;
        printf("%d\n", i);
    }
    ```

1. What does the following program print out? 
    ```c
    #include <stdio.h>
    #include <math.h>

    int main() {
        int n = 16;
        printf("%d\n", sqrt(n));
    }
    ```

1. What is the first value printed out by the program shown below? 
    ```c
    #include <stdio.h>

    int main() {
    int j = 4;
        printf("%d\n", j++);
        printf("%d\n", ++j);
    }
    ```

1. What is the second value printed out by the program shown above? 

1. What is the value printed out by the program shown below? 
    ```c
    #include <stdio.h>
    int main() {
        printf("%d\n", 0xf0 | 0xf == 0xff);
    }
    ```

1. What is the value printed out by the program shown below? 
    ```c
    #include <stdio.h>
    int main() {
        printf("%d\n", (0xf0 | 0xf) == 0xff);
    }
    ```

1. What is the value printed out by the program shown below? 
    ```c
    #include <stdio.h>
    int main() {
        int i = 4;
        int x = 1;
        printf("%d\n", x/i);
    }
    ```

1. What is the value printed out by the program shown below? 
    ```c
    #include <stdio.h>
    int main() {
        int i = 4;
        double x = 1;
        printf("%d\n", x/i);
    }
    ```

1. What is the value printed out by the program shown below? 
    ```c
    #include <stdio.h>
    int main() {
        int i = 4;
        double x = 1;
        printf("%f\n", x/i);
    }
    ```

1. Study this program. Try commenting out the `s[j] = '\0';` statement. What happens?
    ```c
    #include <stdio.h>
    // Work an example of this in class (pg. 47)
    void squeeze(char s[], int c) {
        int i, j;
        for (i = j = 0; s[i] != '\0'; i++)
            if (s[i] != c)
            s[j++] = s[i];
        s[j] = '\0';
    }

    int main() {
        char str[20] = "hello there!";
        char c = 'e';
        squeeze(str, c);
        printf("%s\n", str);
    }
    ```

1. What does this code print?
    ```c
    #include <stdio.h>
    #include <ctype.h>

    int main() {
    printf("%d\n", isdigit('9'));
    }

    ```

1. What does this code print?
    ```c
    #include <stdio.h>
    #include <ctype.h>

    int main() {
    printf("%d\n", isdigit("9"));
    }

    ```