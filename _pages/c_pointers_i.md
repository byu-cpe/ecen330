---
layout: page
toc: false
title: "C Programming Part 7: Pointers I"
---

## Topics
* Basic pointer operations
* Pointers to Arrays 

## Class Slides

* [Slides]({% link media/c/C_part7.pdf %})

## Resources
* <https://en.wikibooks.org/wiki/C_Programming/Pointers_and_arrays>

## Study Questions

1.  What value with the program print?
    ```c
    #include <stdio.h>
    int main() {
      int x=4;
      int *y = &x;
      y++;
      printf("%d\n", *y);
    }
    ```

1. What value with the program print?
    ```c
    #include <stdio.h>
    int main() {
      int x = 4;
      int y = &x;
      y++;
      printf("%d\n", y++);
    }
    ```

1. What value will the program print?
    ```c
    #include  <stdio.h>
    int main() {
      int x = 4;
      int* y = 5;
      y++;
      y++;
      printf("%d\n", y++);
    }
    ```

1. What value will the program print?
    ```c
    #include <stdio.h>
    int main() {
      int x = 4;
      int* y = &x;
      (*y)++;
      printf("%d\n", y);
    }
    ```

1. What value will the program print?
    ```c
    #include <stdio.h>
    int main() {
      int x = 4;
      int* y = &x;
      (*y)++;
      printf("%d\n", *y++);
    }
    ```

1. *The following programs are variations on the swap() program. See how the various changes to the code impact the results*. What will this program print?
    ```c
    #include <stdio.h>

    void swap(int a, int b) {
      int temp = a;
      a = b;
      b = temp;
    }

    int main() {
      int x = 10, y = 20;
      swap(x, y);
      printf("%d\n", x);
    }
    ```

1. What will this program print?
    ```c
    #include <stdio.h> 

    void swap(int *a, int *b) {
      int temp = a;
      a = b;
      b = temp;
    }

    int main() {
      int x = 10, y = 20;
      swap(x, y);
      printf("%d\n", x);
    }
    ```

1. What will this program print?
    ```c
    #include <stdio.h>

    void swap(int *a, int *b) {
      int temp = a;
      *a = b;
      b = temp;
    }

    int main() {
      int x = 10, y = 20;
      swap(&x, &y);
      printf("%d\n", x);
    }
    ```

1. What will this program print (note that it is printing y)?
    ```c
    #include <stdio.h>

    void swap(int *a, int *b) {
      int* temp = a;
      *a = *b;
      *b = temp;
    }

    int main() {
      int x = 10, y = 20;
      swap(&x, &y);
      printf("%d\n", y);
    }
    ```

1. What will this program print (note that it is printing y)?
    ```c
    #include <stdio.h>

    void swap(int *a, int *b) {
      int temp = a;
      *a = *b;
      *b = temp;
    }

    int main() {
      int x = 10, y = 20;
      swap(&x, &y);
      printf("%d\n", y);
    }
    ```

1. What will this program print (note that it is printing y)?
    ```c
    #include <stdio.h>

    void swap(int *a, int *b) {
      int temp = *a;
      *a = *b;
      *b = temp;
    }

    int main() {
      int x = 10, y = 20;
      swap(&x, &y);
      printf("%d\n", y);
    }
    ```

1. (T or F) The program below will generate an error or warning when compiled.
    ```c
    #include <stdio.h>
    #define SIZE 20
    int main() {
      char str[SIZE] = "hi there!\n";
      char* strp = str;
    }
    ```

1.  What will this program print?
    ```c
    #include <stdio.h>
    #define SIZE 20
    int main() {
      char str[SIZE] = "hi-there!\n";
      char* strp = &str[8];
      printf("%c\n", strp);
    }
    ```

1. What will this program print?
    ```c
    #include <stdio.h>
    #define SIZE 20
    int main() {
      char str[SIZE] = "hi-there!\n";
      char* strp = &str[7];
      printf("%c\n", *(strp+1));
    }
    ```

1. What will this program print?
```c
    #include <stdio.h>
    #define SIZE 20
    int main() {
      char str[SIZE] = "hi-there!\n";
      char* strp = &str[1];
      printf("%c\n", *(strp++));
    }
```

1. What will this program print?
    ```c
    #include <stdio.h>
    #define SIZE 20
    int main() {
      char str[SIZE] = "hi-there!\n";
      char* strp = str;
      printf("%c\n", *(++strp));
    }
    ```

1. (T or F) This program will compile correctly.
    ```c
    #include <stdio.h>
    #define SIZE 20
    int main() {
      char str[SIZE] = "hi-there!\n";
      char* strp = str++;
      printf("%c\n", *strp);
    }
    ``` 

1. What does this program print?
    ```c
    #include <stdio.h>

    void mystery(char a[]) {
      a[1] = 'b';
    }

    #define SIZE 20
    int main() {
      char str[SIZE] = "hi-there!\n";
      mystery(str);
      printf("%c\n", str[1]); 
    }
    ```

1. What does this program print?
    ```c
    #include <stdio.h>
    void mystery(char a[]) {
      *(a+1) = 'b';
    }

    #define SIZE 20
    int main() {
      char str[SIZE] = "hi-there!\n";
      mystery(str);
      printf("%c\n", str[1]); 
    }
    ```

1. What does this program print?
    ```c
    #include <stdio.h>
    void mystery(char* a) {
      *(a+1) = 'b';
    }

    #define SIZE 20
    int main() {
      char str[SIZE] = "hi-there!\n";
      mystery(str);
      printf("%c\n", str[1]); 
    }
    ```

1. What does this program print?
    ```c
    #include <stdio.h>
    void mystery(char a[]) {
      *(a++) = 'b';
    }
    
    #define SIZE 20
    int main() {
      char str[SIZE] = "hi-there!\n";
      mystery(str);
      printf("%c\n", str[1]); 
    }
    ```

1. What will this program print? Is the result implementation-independent?
    ```c
    #include <stdio.h>
    
    int main() {
      int* x = 4;
      printf("%d\n", ++x);
    }
    ```

1. Write a function that takes an array of *int*s (*nums*) and returns a pointer to the largest element. Create a test program that calls the function and prints out the largest value.
1. Write a function that takes a string (*str*) and int (*i*), and prints the string from location *i* to the end. 
1. Write a function that takes a string (*str*) and a pointer to a location in the string (*p*), and prints everything up to, but not including the character pointed to by *p*.  Create a test program that calls this function.
1. Write a function that increments an *int* from the caller function.  Create a test program that calls this function and prints the modified int before and after calling the function.
1. Write a function *swap* that swaps two *char* variables from the caller function.  Create a test program that calls this function and prints the chars before and after calling *swap*.
1. Write a function *reverse* that uses your *swap* function from the previous question to reverse the direction of the string.  Create a test program that prints a string before and after using the *reverse* function.
1. Write a function *replicate* that takes a string and prints it out twice consecuitively to a provided location.  Create a test program that prints the new string.
