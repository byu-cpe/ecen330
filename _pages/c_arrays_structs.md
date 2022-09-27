---
layout: page
toc: false
title: "C Programming Part 4: Arrays & Structs"
---

## Topics
- Arrays
- Character Arrays
- Structs

## Class Slides
- [Slides]({% link media/c/C_part4.pdf %})

## Resources
* <https://en.wikibooks.org/wiki/C_Programming/Arrays_and_strings>
* <https://en.wikibooks.org/wiki/C_Programming/Advanced_data_types#Structs> 
    * *Note:* You can skip the material about **pointers** to structs.

## Study Questions
1. How do you declare arrays in C? How do you initialize them?
1. If you decare an array like this: `int values[10]={3};`, what is the value of `values[5]`?
1. (T/F) If you access an array element outside the array bounds, C has runtime code that will catch the error.
1. (T/F) `sizeof()` returns the number of elements in the array.
1. (T/F) If you have an array `uint32_t vals[10]`, what is the value of `sizeof(vals)`?
1. (T/F) C has a string datatype.
1. If you declare a string (char array) like this: `char str[10] = "hi";`, what is the size of the array (in bytes)? What is returned by `strlen(str)`?
1. How do you define a new struct?  Is the `struct` keyword optional?
1. In the following code, how many struct variables are declared? How many struct *types* are defined?
    ```c
    struct mystruct {
        int int_member;
        double double_member;
        char string_member[25];
    } s;
    struct mystruct t;
    ```
1. In the following code, how many struct variables are declared? How many struct *types* are defined?
    ```c
    typedef struct {
        int int_member;
        double double_member;
        char string_member[25];
    } mystruct;
    ```

1. Assuming you declared a struct variable using the struct above (`mystruct s;`), how would you write *printf* statements to print out each member of the struct?

1. What does this program print?
    ```c
    #include <stdio.h>

    struct point {
        int x;
        int y;
    };

    struct point makePoint(int x1, int y1) {
        struct point temp;
        temp.x = x1;
        temp.y = y1;
        return temp;
    }

    void printPoint(struct point p) {
        printf("(%d, %d)\n", p.x, p.y);
    }

    int main() {
        struct point p1 = makePoint(3, 4);
        struct point p2 = p1;
        printPoint(p2);
    }
    ```

1. What does this program print?
    ```c
    #include <stdio.h>

    struct point {
        int x;
        int y;
    };

    struct point makePoint(int x1, int y1) {
        struct point temp;
        temp.x = x1;
        temp.y = y1;
        return temp;
    }

    void printPoint(struct point p) {
        printf("(%d, %d)\n", p.x, p.y);
    }

    int main() {
        struct point p1 = makePoint(3, 4);
        struct point p2 = p1;
        p1.x = p1.y;
        printPoint(p2);
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

    void modifyPoint(struct point p) {
        p.x++;
        p.y++;
    }

    int main() {
        struct point p1 = {3, 4};
        modifyPoint(p1);
        printPoint(p1);
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

    void modifyPoint(struct point p) {
        p.x++;
        p.y++;
    }

    int main() {
        struct point p[2] = { {3, 4}, {4, 5} };
        modifyPoint(p[0]);
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

    int main() {
        struct point p[2] = { {3, 4}, {4, 5} };
        p[0] = p[1];
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

    int main() {
        struct point p[2] = { {3, 4}, {4, 5} };
        printPoint(p[2]);
    }
    ```