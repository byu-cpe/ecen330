---
layout: page
toc: false
title: "K & R Chapter 3 Study Questions"
---

```c
#ifdef Q1
// Question: (T or F) This code will terminate after 5 iterations.
#include <stdio.h>
int main() {
  int val = 5;
  while (val)
    printf("%d\n\r", val);
  val--;
}
#endif

#ifdef Q2
#include <stdio.h>
int main() {
  int x;
  x = 1;
  x > 1; // Question: (T or F) This line of code contains a statement.
  printf("%d\n\r", x);
}
#endif

#ifdef Q3
#include <stdio.h>
// Question: How many statements does this program contain?
int main() {
  int x = 1, y = 2, z = 3;
  printf("%d\n\r", x);
}
#endif

#ifdef Q4
// Question: (T or F) The two if-statements are equivalent.
#include <stdio.h>
int main() {
  int x = 1;
  if (x != 0)
    printf("%d\n\r", x);
  if (x)
    printf("%d\n\r", x);
}
#endif

#ifdef Q5
// Question: (T or F) How many times will this program  print out the statement
// "did nothing"?
#include <stdio.h>
int main() {
  int i = 10, j;
  if (i >= 0) // Do nothing if i < 0.
    for (j = 0; j < i; j++)
      if (j == 10) {
        printf("%d\n\r", j);
        return i;
      } else
        printf("did nothing.\n\r");
}
#endif

#ifdef Q6
// Question: The following program will print out:
#include <stdio.h>
int main() {
  int x = 10;
  if (x > 0)
    printf("1\n\r");
  else if (x > 1)
    printf("2\n\r");
  else if (x > 2)
    printf("3\n\r");
  else
    printf("4\n\r");
}
#endif

#ifdef Q7
// Question: How many times will this program will print out "1"?
#include <stdio.h>
int main() {
  int i = 2;
  switch (i) {
  case 1:
    printf("1\n\r");
    break;
  case 2:
    printf("1\n\r");
  case 3:
    printf("1\n\r");
    break;
  case 4:
    printf("1\n\r");
    break;
  }
}
#endif

#ifdef Q8
// Question: (T or F) The functions p1 and p2 have the same behavior.
#include <stdio.h>
void p1() {
  int x;
  x = 0;
  while (x < 5) {
    printf("looped\n\r");
    x++;
  }
}

void p2() {
  int x;
  for (x = 0; x < 5; x++)
    printf("looped\n\r");
}

int main() {
  p1();
  p2();
}
#endif

#ifdef Q9
// Question: The last thing that this program below will print is:
#include <stdio.h>
int main() {
  int x = 0;
  for (;;) {
    printf("%d\n\r", x++);
    if (x > 2)
      break;
  }
}
#endif

#ifdef Q10
// Question: How many times with this program print hi!?
#include <stdio.h>
int main() {
  int i = 0;
  do
    printf("hi!\n\r");
  while (i);
}
#endif

#ifdef Q11
// Question: How many times will this program print "hi!"?
#include <stdio.h>
int main() {
  while (1) {
    printf("hi!\n\r");
    break;
  }
}
#endif

#ifdef Q12
// Question: How many times will this program print "hi!"?
#include <stdio.h>
int main() {
  while (1) {
    printf("hi!\n\r");
    continue;
  }
}
#endif

#ifdef Q13
// Question: How many times will this program print "hi!"?
#include <stdio.h>
int main() {
  int i;
  for (i = 0; i < 10; i++) {
    if (i % 2)
      continue;
    printf("hi!\n\r");
  }
}
#endif

#ifdef Q14
// Question: How many times will this program print "hi!"?
#include <stdio.h>
int main() {
  int i;
  for (i = 0; i < 10; i++) {
    if (i % 2)
      break;
    printf("hi!\n\r");
  }
}
#endif 

#ifdef Q15
// This is exercise 3-4 in K&R.
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int n, char s[]);
void itoaModified(int n, char s[]);
void reverse(char s[]);

#define MAXBUF 1000
#define TEST_VALUE INT_MIN
int main() {
  char stringNum[MAXBUF];
  itoaModified(TEST_VALUE, stringNum);
  printf("%s\n", stringNum);
}

void itoa(int n, char s[]) {
  int i, sign;
  if ((sign = n) < 0)
    n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
#endif
```