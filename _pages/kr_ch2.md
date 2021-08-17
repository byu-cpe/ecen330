---
layout: page
toc: false
title: "K & R Chapter 2 Study Questions"
---

This chapter discusses types, operators and expressions. For each question, make sure that you understand what is happening and the focus or concept associated with the question. The file that we used in class is available at the bottom of this page.

1. (T or F) The compiler will generate an error if an identifier starts with "_".

2. (T or F) Variables named myVariable and MyVariable are the same variable.

3. (T or F) A *short* may be the same length as an *int*.

4. (T or F) A *short* may contain fewer bits than an *int*.

5. What is the maximum value for a short for the ARM processor used in this class? (refer to pg. 257 of text, you will need to write a small program to run on the board to determine this value).

6. What is the minimum value for a short for the ARM processor used in this class? (see note above). 

7. What is the maximum value for uint16_t?(see table at [[https://en.wikibooks.org/wiki/C_Programming/C_Reference/stdint.h]]). 

8. (T or F) `'\a'` is a string literal.

9. Write the name of the mystery function shown below (it is a standard library function):
    ```c
    int mystery(char s[]) {
        int i = 0;
        while (s[i] != '\0')
            ++i;
        return i;
    }
    ```

10. What does the code below print out?
    ```c
    #include <stdio.h>
    #include <limits.h>

    int main() {
        enum {hello=3, goodbye} myEnum = goodbye;
        printf("%d\n", myEnum);
    }
    ```

11. (T or F) In the program above, myEnum is an automatic variable.

12. What does the program below print out? 
    ```c
    int main() {
        int i=9;
        int j = ((0 > 1) && (i=14));
        printf("%d\n\r", i);
    }
    ```

13. What does the program below print out? 
    ```c
    int main() {
        int i=9;
        int j = ((0 > 1) || (i=14));
        printf("%d\n\r", j);
    }
    ```


13. What does the following program print out when run on the board? What does it print out on your Linux machine?
    ```c
    #include <stdio.h>

    int main() {
        char val1 = -128;
        int val2 = val1;
        printf("%d\n\r", val2);
    }
```

14. What does the following program print out when run on the board? 
    ```c 
    #include <stdio.h>

    int main() {
        int i = 0 < 1;
        printf("%d\n\r", i);
    }
    ```

15. What does the following program print out when run on the board? 
    ```c
    #include <stdio.h>
    #include <ctype.h>

    int main() {
        printf("%d\n\r", isdigit('1'));
    }
    ```

16. What does the following program print out when run on the board? 
    ```c
    #include <stdio.h>
    #include <math.h>

    int main() {
        int n = 16;
        printf("%d\n\r", sqrt(n));
    }
    ```

17. What is the first value printed out by the program shown below? 
    ```c
    #include <stdio.h>

    int main() {
    int j = 4;
        printf("%d\n\r", j++);
        printf("%d\n\r", ++j);
    }
    ```

18. What is the second value printed out by the program shown above? 

19. What is the value printed out by the program shown below? 
    ```c
    #include <stdio.h>
    int main() {
        printf("%d\n\r", 0xf0 | 0xf == 0xff);
    }
    ```

20. What is the value printed out by the program shown below? 
    ```c
    #include <stdio.h>
    int main() {
        printf("%d\n\r", (0xf0 | 0xf) == 0xff);
    }
    ```

21. What is the value printed out by the program shown below? 
    ```c
    #include <stdio.h>
    int main() {
        int i = 4;
        int x = 1;
        printf("%d\n\r", x/i);
    }
    ```

22. What is the value printed out by the program shown below? 
    ```c
    #include <stdio.h>
    int main() {
        int i = 4;
        double x = 1;
        printf("%d\n\r", x/i);
    }
    ```

23. What is the value printed out by the program shown below? 
    ```c
    #include <stdio.h>
    int main() {
        int i = 4;
        double x = 1;
        printf("%f\n\r", x/i);
    }
    ```

24. Study this program. Try commenting out the `s[j] = '\0';` statement. What happens?
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
        printf("%s\n\r", str);
    }
    ```

25. Can you predict what this code will print? Or, is it possible for different compilers to generate different results? Carefully read Pg. 53 of K&R before attempting to answer this question.
    ```c
    #include <stdio.h>
    #include <stdint.h>
    uint16_t mysteryFunction(uint16_t a, uint16_t b) {
    return a * b;
    }

    int main() {
    uint16_t x = 14;
    uint16_t y = 0;
    y = mysteryFunction(++x, x++);
    printf("%d\n\r", y);
    }
    ```

26. Can you predict what this code will print? Or, is it possible for different compilers to generate different results?
    ```c
    #include <stdio.h>
    #include <ctype.h>

    int main() {
    printf("%d\n\r", isdigit('9'));
    }

    ```

```c

#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef Q5

// Maximum value for a short.
int main() {
  printf("max value for a short:%d\n", SHRT_MAX);
  printf("min value for a short:%d\n", SHRT_MIN);
}
#endif

#ifdef Q10
#include <stdio.h>
int main() {
  enum myEnum {hello=3, goodbye=3} theEnum=goodbye, yourEnum;
  theEnum = goodbye;
  yourEnum = hello;
  printf("%d\n", theEnum);
  /* enum myEnum switchVar; */
  /* switch(switchVar) { */
  /* case hello: */
  /*   break; */
  /* case goodbye: */
  /*   break; */
  /* } */
}
#endif

#ifdef Q12A
// Can't short-circuit && when first term evaluates to 1.
int main() {
  int i=9;
  int j = ((0 > 1) && (i=14));
  printf("%d\n\r", i);
}
#endif

#ifdef Q12B
// Can't short-circuit || when first term evaluates to 0.
int main() {
  int i=9;
  int j = ((0 > 1) || (i=14));
  printf("%d\n\r", i);
}
#endif


#ifdef Q13
// casting between char and int is implementation dependent for negative char values.
// Result is negative on the Mac, positive on the Xilinx SDK.
int main() {
  char val1 = -128;
  int val2 = val1;
  printf("%d\n\r", val2);
}
#endif

#ifdef Q14
// Relational expressions return either 0 or 1.
// if, while, etc., need only return a non-zero value or 0.
int main() {
  int i = 0 < 1;
  printf("%d\n\r", i);
}
#endif

#ifdef Q15
// Prints out 1 but need only print out a non-zero value.
int main() {
  printf("%d\n\r", isdigit('1'));
}
#endif

#ifdef Q16
#include <math.h>
#include <stdio.h>
// The problem is that printf is expecting an integer value, sqrt() returns a double.
// Remember that arguments are cast-ed at the time the argument values are provided to the function.
// printf() doesn't cast it's arguments.
int main() {
  int n = 16;
  printf("%d\n\r", sqrt(n));  // double sqrt(double arg);
}
#endif

#ifdef Q17
// Covers 17, 18 from the study questions.
// first printf prints the value of j and then increments it (4).
// second printf increments the value of j and then prints it (6).
int main() {
  int j = 4;
  printf("%d\n\r", j++);
  printf("%d\n\r", ++j);
}
#endif

#ifdef Q19
int main() {
  printf("%d\n\r", 0xf0 | 0xf == 0xff);
}
#endif

#ifdef Q19A
// Precedence of the | and == operator are the same and so everything is evaluated from the right.
// (0xf == 0xff) = 0, (0xf0 | 0) = 0xf0.
int main() {
  printf("%d\n\r", 0xf0 | 0xf == 0xff);
}
#endif

#ifdef Q19B
// The parenthesis fix the precedence.
int main() {
  printf("%d\n\r", (0xf0 | 0xf) == 0xff);
}
#endif

#ifdef Q21
int main() {
  int i = 4;
  int x = 1;
  printf("%d\n\r", x/i);
}
#endif


#ifdef Q22
int main() {
  int i = 4;
  double x = 1;
  printf("%d\n\r", x/i);
}
#endif

#ifdef Q23
int main() {
  int i = 4;
  double x = 1;
  printf("%f\n\r", x/i);
}
#endif

#ifdef Q24
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
  printf("%s\n\r", str);
}
#endif

#ifdef Q25
#include <stdio.h>
// Returns the n-bit-field contained in x that starts at p, 
unsigned getbits(unsigned x, int p, int n);
#define PRINT_EXTRA_STUFF 1
int main() {
  unsigned a = 0x5A;
  unsigned result;
  result = getbits(a, 5, 4);
  printf("result = %x\n\r", result);
  result = getbits(a, 4, 2);
  printf("result = %x\n\r", result);
  result = getbits(a, 4, 4);
  printf("result = %x\n\r", result);  
}

unsigned getbits(unsigned x, int p, int n) {
  if (PRINT_EXTRA_STUFF) {
    printf("Extracting the %d-bit wide field starting from position %d from %08x\n\r", n, p, x);
    printf("x: %08x\n\r", x);
    printf("x: %08x (shifted right by %d)\n\r", x>>(p+1-n), p+1-n);
    printf("uninverted bit-mask: %08x\n\r", (~0 << n));
    printf("inverted bit-mask:   %08x\n\r", ~(~0 << n));
  }
  return (x >> (p+1-n)) & ~(~0 << n);
}

#endif

#ifdef Q26
#include <stdio.h>
#include <stdint.h>
uint16_t mysteryFunction(uint16_t a, uint16_t b) {
  return a * b;
}

int main() {
  uint16_t x = 14;
  uint16_t y = 0;
  y = mysteryFunction(++x, x++);  // May be invoked with (15, 15) or (16, 14).
  printf("%d\n\r", y);
}

// What does this program print out?
// a. 225
// b. 224
// (c). Unknown. Different compilers may produce different results.

#endif

#ifdef Q27
#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

int main() {
  printf("%d\n\r", isdigit('9'));
}
#endif

#ifdef Q28
#include <stdio.h>
int main() {
  char* str = "hello, "
    " world";
  printf("%s\n", str);
}

#endif

#ifdef Q29
#include <stdio.h>
int main() {
  int a=2, b=2;
  int x;
  x = a<b++ ? b+1 : b-1;
  printf("%d\n", x);
}
#endif

```