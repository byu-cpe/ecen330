---
layout: page
toc: false
title: "C Programming Part 8: Pointers II"
---

## Topics
* More complex pointer operations
* Arrays of pointers and double pointers
* Pointers to structs

## Class Slides
* [Slides]({% link media/c/C_part8.pdf %})

## Resources
* <https://en.wikibooks.org/wiki/C_Programming/Pointers_and_arrays>

## Study Questions

1. What does this program print?
```c
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
  printf("%s\n", s1);
}
```

1. What does this program print?
    ```c
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
      printf("%s\n", s2p);
    }
    ```

1. What does this program print? *Note that the swap() function is identical in the next five questions.*
    ```c
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
      printf("%s\n", *s);
    }
    ```

1. What does this program print?
    ```c
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
      printf("%s\n", s[0]);
    }
    ```

1. What does this program print?
    ```c
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
      printf("%s\n", s+1);
    }
    ```

1. What does this program print?
    ```c
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
      printf("%s\n", ++sp);
    }
    ```

1. What does this program print?
    ```c
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
      printf("%s\n", *(++t));
    }
    ```

1. (*Pointers to functions.*) What does the following program print?  **This program has a bug, can you fix it?**
    ```c
    #include <string.h>

    #define EQUAL 0
    #define LESS_THAN -1
    #define GREATER_THAN 1
    
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
    ```

1.  What does this program print?
    ```c
    #include <stdio.h>

    struct point {
      int x;
      int y;
    };

    void printPoint(struct point p) {
      printf("(%d, %d)\n", p.x, p.y);
    }

    struct point modifyPoint(struct point* p) {
      p->x = 4;
      p->y = 5;
      return *p;
    }

    int main() {
      struct point p[2];
      p[0].x = 3;
      p[0].y = 4;
      modifyPoint(p);
      printPoint(p[0]);
    }
    ```

1. What does this program print?
    ```c
    #include <stdio.h>

    struct point {
      int x;
      int y;
    };

    void printPoint(struct point p) {
      printf("(%d, %d)\n", p.x, p.y);
    }

    struct point modifyPoint(struct point* p) {
      p->x = 4;
      p->y = 5;
      return *p;
    }

    int main() {
      struct point* p[2];
      p[0]->x = 3;
      p[0]->y = 4;
      modifyPoint(*p);
      printPoint(*(p[0]));
    }
    ```

1. What argument must be passed to printPoint()?
    ```c
    struct point {
      int x;
      int y;
    };

    void printPoint(struct point p) {
      printf("(%d, %d)\n", p.x, p.y);
    }

    void modifyPoint(struct point* p) {
      p->x = 4;
      p->y = 5;
    }

    int main() {
      struct point* p[2];
      struct point p0 = {3, 4};
      p[0] = &p0;
      printPoint(???);
    }
    ```

1. What will this program print?
    ```c
    #include <stdio.h>

    struct point {
      int x;
      int y;
    };

    void printPoint(struct point p) {
      printf("(%d, %d)\n", p.x, p.y);
    }

    int main() {
      struct point p[2];
      struct point p0 = {3, 4};
      p[0] = p0;
      p[0].x++;
      p[0].y++;
      printPoint(p0);
    }
    ```

1.  What will this program print?
    ```c
    #include <stdio.h>

    struct point {
      int x;
      int y;
    };

    void printPoint(struct point p) {
      printf("(%d, %d)\n", p.x, p.y);
    }

    int main() {
      struct point* p[2];
      struct point p0 = {3, 4};
      struct point p1 = {9, 10};
      p[0] = &p0;
      *(p[0]) = p1;
      p[0]->x++;
      p[0]->y++;
      printPoint(p0);
    }
    ```

1. Select the answers for @1 @2 @3 so that the program will compile and will print 3 4 5.
    ```c
    #include <stdlib.h>

    struct node {
      int value;
      struct node* link;
    };

    struct node* nalloc(int v) {
      struct node* tmp = malloc(sizeof(struct node*));
      tmp->value = v;
      tmp->link = NULL;
      return tmp;
    }
    void p(struct node* n) {
      if (@1)
        return;
      else {
        @2
        @3
      }
    }

    a: n == NULL
    b: return;
    c: n != NULL
    d: printf("%d", n.value);
    e: p(n);
    f: p(n.link);
    g: p(n->link);
    h: printf("%d", n->value);
    i: p();

    int main() {
      struct node* n0 = nalloc(3);
      struct node* n1 = nalloc(4);
      struct node* n2 = nalloc(5);
      n0->link = n1;
      n1->link = n2;
      p(n0);
    }
    ```

1. Modify the commented code below so that the keyword struct does not appear in the body of the declaration for node, so that the main() function below will compile without error.
    ```c
    // struct node {
    //   int value;
    //   struct node* link;
    // };

    @1 @2 @3 @4;

    typedef struct node {
      int value;
      @5 link;
    } @6;


    int main() {
      Node myNode;
    }
    // Answers
    // a: typedef
    // b: node
    // c: node*
    // d: nodePtr
    // e: nodePtr*
    // f: Node
    // g: struct
    // @1: ?, @2: ?, @3: ?, @4: ?, @5: ?, @6: ?

    ```

1. Write a function that takes an array, and updates two pointers from the caller function to point to the smallest and largest integers in the array.  Create a test program that calls this function and prints the smallest and largest values.