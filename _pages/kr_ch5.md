---
layout: page
toc: false
title: "K & R Chapter 5 Study Questions"
---

```c

#ifdef P1
// Topic: Basic pointers.
// Question: What value with the program print?
#include <stdio.h>
int main() {
  int x=4;
  int *y = &x;
  y++;
  printf("%d\n", *y);
}
// Ans: 
#endif

#ifdef P2
// Topic: Basic pointers with post-increment
// Question: What value with the program print?
#include <stdio.h>
int main() {
  int x = 4;
  int y = &x;
  y++;
  printf("%d\n", y++);
}
// Ans: 
#endif

#ifdef P3
#include <stdio.h>
// Topic: Basic pointers with post-increment.
// Question: What value with the program print?
int main() {
  int x = 4;
  int* y = 5;
  y++;
  y++;
  printf("%d\n", y++);
}
// Ans: 
#endif

#ifdef P4
// Topic: Basic pointers with post-increment.
// Question: What value with the program print?
#include <stdio.h>
int main() {
  int x = 4;
  int* y = &x;
  (*y)++;
  printf("%d\n", y);
}
// Ans: 
#endif

#ifdef P5
// Topic: Basic pointers with post-increment.
// Question: What value with the program print?
#include <stdio.h>
int main() {
  int x = 4;
  int* y = &x;
  (*y)++;
  printf("%d\n", *y++);
}
// Ans: 
#endif

#ifdef P6
void swap(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}

#include <stdio.h>
// P6 - P11 are variations on the swap() program.
// See how the various changes to the code impact the results.

// Question: What will this program print?
int main() {
  int x = 10, y = 20;
  swap(x, y);
  printf("%d\n\r", x);
}
// Ans: 
#endif

#ifdef P7

// Question: What will this program print?
void swap(int *a, int *b) {
  int temp = a;
  a = b;
  b = temp;
}

#include <stdio.h>
int main() {
  int x = 10, y = 20;
  swap(x, y);
  printf("%d\n\r", x);
}
// Ans: 
#endif

#ifdef P8
// Question: What will this program print?
void swap(int *a, int *b) {
  int temp = a;
  *a = b;
  b = temp;
}

#include <stdio.h>
int main() {
  int x = 10, y = 20;
  swap(&x, &y);
  printf("%d\n\r", x);
}
// Ans: 
#endif

#ifdef P9
// Question: What will this program print (note that it is printing y)?
void swap(int *a, int *b) {
  int* temp = a;
  *a = *b;
  *b = temp;
}

#include <stdio.h>
int main() {
  int x = 10, y = 20;
  swap(&x, &y);
  printf("%d\n\r", y);
}
// Ans: 
#endif

#ifdef P10
// Question: What will this program print (note that it is printing y)?
void swap(int *a, int *b) {
  int temp = a;
  *a = *b;
  *b = temp;
}

#include <stdio.h>
int main() {
  int x = 10, y = 20;
  swap(&x, &y);
  printf("%d\n\r", y);
}
// Ans: 
#endif

#ifdef P11
// Question: What will this program print (note that it is printing y)?
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

#include <stdio.h>
int main() {
  int x = 10, y = 20;
  swap(&x, &y);
  printf("%d\n\r", y);
}
// Ans: 
#endif

// These questions are related to arrays and pointers.

#ifdef P12
// Topic: Pointer declaration syntax with arrays.
// Question:(T or F) The program below will generate an error or warning when compiled.
#include <stdio.h>
#define SIZE 20
int main() {
  char str[SIZE] = "hi there!\n\r";
  char* strp = str;
}
// Ans: 
#endif

#ifdef P13
// Topic: Using pointers and arrays.
// Question: What will this program print?
#include <stdio.h>
#define SIZE 20
int main() {
  char str[SIZE] = "hi-there!\n\r";
  char* strp = &str[8];
  printf("%c\n\r", strp);
}
// Ans: 
#endif

#ifdef P14
// Topic: Using pointers, arrays, and pointer-addressing.
// Question: What will this program print?
#include <stdio.h>
#define SIZE 20
int main() {
  char str[SIZE] = "hi-there!\n\r";
  char* strp = &str[7];
  printf("%c\n\r", *(strp+1));
}
// Ans: 
#endif

#ifdef P15
// Topic: Using pointers, arrays, and pointer-addressing.
// Question: What will this program print?
#include <stdio.h>
#define SIZE 20
int main() {
  char str[SIZE] = "hi-there!\n\r";
  char* strp = &str[1];
  printf("%c\n\r", *(strp++));
}
// Ans: 
#endif

#ifdef P16
// Topic: Using pointers, arrays, and pointer-addressing.
// Question: What will this program print?
#include <stdio.h>
#define SIZE 20
int main() {
  char str[SIZE] = "hi-there!\n\r";
  char* strp = str;
  printf("%c\n\r", *(++strp));
}
// Ans: 
#endif

#ifdef P17
// Topic: Using pointers, arrays, and pointer-addressing.
// Question: (T or F) This program will compile correctly.
#include <stdio.h>
#define SIZE 20
int main() {
  char str[SIZE] = "hi-there!\n\r";
  char* strp = str++;
  printf("%c\n\r", *strp);
}
// Ans: 
#endif

#ifdef P18
// Question: What does this program print?
#include <stdio.h>
void mystery(char a[]) {
  a[1] = 'b';
}

#define SIZE 20
int main() {
  char str[SIZE] = "hi-there!\n\r";
  mystery(str);
  printf("%c\n\r", str[1]); 
}
// Ans: h, (b), i, none of these
#endif

#ifdef P20
// Question: What does this program print?
#include <stdio.h>
void mystery(char a[]) {
  *(a+1) = 'b';
}

#define SIZE 20
int main() {
  char str[SIZE] = "hi-there!\n\r";
  mystery(str);
  printf("%c\n\r", str[1]); 
}
// Ans: 
#endif

#ifdef P21
// Question: What does this program print?
#include <stdio.h>
void mystery(char* a) {
  *(a+1) = 'b';
}

#define SIZE 20
int main() {
  char str[SIZE] = "hi-there!\n\r";
  mystery(str);
  printf("%c\n\r", str[1]); 
}
// Ans: 
#endif

#ifdef P22
// Question: What does this program print?
#include <stdio.h>
void mystery(char a[]) {
  *(a++) = 'b';
}

#define SIZE 20
int main() {
  char str[SIZE] = "hi-there!\n\r";
  mystery(str);
  printf("%c\n\r", str[1]); 
}
// Ans: 
#endif

#ifdef P23
// Topic: Pointers to pointers and character arrays.
// Question: What does this program print?
#include <stdio.h>
void swap(char* a, char* b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}
#define SIZE 20
int main() {
  char s1[SIZE] = "hello";
  char s2[SIZE] = "bye";
  swap(s1, s2);
  printf("%s\n\r", s1);
}
// Ans: hello, bye, (none of these).
// Note: You need a pointer to a pointer to handle this one.
// Note: Will actually print "bello" and second string becomes "hye". 
#endif

#ifdef P24
// Question: What does this program print?
#include <stdio.h>
void swap(char** a, char** b) {
  char* tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
#define SIZE 20
int main() {
  char s1[SIZE] = "bye";
  char* s1p = s1;
  char** s1pp = &s1p;
  char s2[SIZE] = "hello";
  char* s2p = s2;
  char** s2pp = &s2p;
  swap(s1pp, s2pp);
  printf("%s\n\r", s2p);
}
// Ans: 
#endif

#ifdef P25
// Topic: Pointers and 2D arrays.
// Note that the swap() function is identical though P29.
// Question: What does this program print?
#include <stdio.h>
void swap(char** a, char** b) {
  char* tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
#define SIZE 20
int main() {
  char *s[10] = {"bye", "hello"};
  swap(s, s+1);
  printf("%s\n\r", *s);
}
// Ans: 
#endif

#ifdef P26
// Topic: Pointers and 2D arrays.
// Question: What does this program print?
#include <stdio.h>
void swap(char** a, char** b) {
  char* tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
int main() {
  char *s[10] = {"bye", "hello"};
  swap(s, s+1);
  printf("%s\n\r", s[0]);
}
// Ans: 
#endif

#ifdef P27
// Topic: Pointers and 2D arrays.
// Question: What does this program print?
#include <stdio.h>
void swap(char** a, char** b) {
  char* tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
int main() {
  char *s[10] = {"bye", "hello"};
  swap(s, s+1);
  printf("%s\n\r", s+1);
}
// Ans: 
#endif

#ifdef P28
// Topic: Pointers and 2D arrays.
// Question: What does this program print?
#include <stdio.h>
void swap(char** a, char** b) {
  char* tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
int main() {
  char *s[10] = {"bye", "hello"};
  swap(s, s+1);
  char* sp = *s;
  printf("%s\n\r", ++sp);
}
// Ans: 
#endif

#ifdef P29
// Topic: Pointers and 2D arrays.
// Question: What does this program print?
#include <stdio.h>
void swap(char** a, char** b) {
  char* tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
int main() {
  char *s[10] = {"bye", "hello"};
  swap(s, s+1);
  char** t = s;
  printf("%s\n\r", *(++t));
}
// Ans: 
#endif

#ifdef P30
// Topic: Pointers to functions.
// This is a simpler example than the one in the book.
// Used for numerical comparisons, same return value as strcmp.
// Note: (return-value < 0), a < b, (return-value > 0), b < a, (return-value == 0), a==b
// Question: What does the following program print?
// Ans: 5 followed by bye, 5 followed by hello, none of these.
// Note: This program has a bug, can you fix it?
#define EQUAL 0
#define LESS_THAN -1
#define GREATER_THAN 1
#include <string.h>
int numcmp(int* a, int* b) {
  if (*a == *b)
    return EQUAL;
  else if (*a < *b)
    return LESS_THAN;
  else
    return GREATER_THAN;
}

#include <stdio.h>
void swap(void* v[], int (*comparator)(void*, void*)) {
  void* temp;
  if (comparator(v[0], v[1]) == GREATER_THAN) {  // The bug is here, what is it?
    temp = v[0];
    v[0] = v[1];
    v[1] = temp;
  }
}

int main() {
  int num0 = 6;
  int num1 = 5;
  int* numbers[2] = {&num0, &num1};
  
  swap((void **) numbers, (int (*)(void*, void*)) numcmp);
  printf("%d\n", *(numbers[0]));
  
  char* strings[2] = {"hello", "bye"};
  swap((void **) strings, (int (*)(void*, void*)) strcmp);
  printf("%s\n", strings[0]);
}

#endif

#ifdef P31
// Question: What will this program print?
// Question: (T or F) Is the result implementation-independent.
#include <stdio.h>
int main() {
  int* x = 4;
  printf("%d\n\r", ++x);
}
// Ans:
// Ans:
#endif


```

## Additional Commentary on Pointers 

The following figures are provided for in-class discussion.

The following figure illustrates the relationship between addresses for 8-bit (char), 16-bit (short) and 32-bit (int) variables.

<img src="{% link media/pointerdiscussionaddressanddata2.png %}" width="400" alt="Diagram of memory layout">

----

The next figure shows how variables may be stored in memory and relates pointers to their "pointed-to" location.

<img src="{% link media/pointerdiscussionaddresses.jpg %}" width="600" alt="Diagram of memory layout">

----

The next figure illustrates the before and after contents of memory after executing the body of the swap function.

<img src="{% link media/pointerdiscussionswap3.png %}" width="700" alt="Diagram of memory layout">
