---
layout: page
toc: false
title: "K & R Chapter 4 Study Questions"
---

```c
/*********************** General Comments *********************/
// 1. To compile individual programs (P1, for example) on the linux command-line:
// gcc -D P1 ch4_studyQuestions.c

// Many of the programs come directly from Chapter 4 of K&R.

#ifdef P1
// K&R, Ch4, pg. 71
// Note: renamed getline() to my_getline to avoid naming conflict with stdio.h
// Topic: General control question.
// Question: (T or F) In my_getline(): When getchar() returns a '\n', the '\n' is always copied to s.

#include <stdio.h>
#define MAXLINE 1000  /* maximum input line length */

int my_getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";  /* pattern to search for */

/* find all lines matching pattern */
int main() {
  char line[MAXLINE];
  int found = 0;

  while (my_getline(line, MAXLINE) > 0)
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }
  return found;
}
#endif

// Need getline for multiple questions.
#include <stdio.h>
/* getline: get line into s, return length */
int my_getline(char s[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

#ifdef P1
/* strindex: return index of t in s, -1 in none */
int strindex( char s[], char t[]) {
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}
#endif

#ifdef P2
#include <stdio.h>
// Topic: What is the default return type for functions without a declared prototype.
// Question: Looking just at the main function below, what does the compiler assume is the
// return type within main()
// when the return type for atof() if the line "double atof(char[]);" is deleted?
// NOTE: If you delete the "double atof(... line, the C++ compiler generates an error, not a warning.
// Carefully read Chapter 4 so you understand what the default return type is for functions.
#define MAXLINE 100
/* rudimentary calculator */
int main() {
  double sum;
  double atof(char[]);
  char line[MAXLINE];
  int my_getline(char line[], int max);

  sum = 0;
  while (my_getline(line, MAXLINE) > 0)
    printf("\t%g\n", sum += atof(line));
  return 0;
}

// Note: Program from Ch 4 of K&R, pgs. 71-72.
// Topic: How are characters encoded?
// Question: (T or F) '0' is equivalent to '\0'

// Question: What value does this expression return: 1000 - '0'?

// Question: What value does this expression return: '1' - '0'?

// Topic: General
// Question: (T or F) for-loop A terminates immediately when the input contains '.'

// Question: If  return-statement C was modified to "return sign * val;", and the number 003.05 was typed in, the program would print:

#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[]) {
  double val, power;
  int i, sign;

  for (i=0; isspace(s[i]); i++)  /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)  // for-loop A
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {  // for-loop B
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  return sign * val / power;  // Return Statement C
}
#endif

#ifdef P3

#include <stdio.h>
#include <stdlib.h>
#define MAXOP 100   // max size of operand or operator.
#define NUMBER '0'  // Signal that a number was found.
int getop(char[]);
void push(double);
double pop(void);

// Reverse Polish calculator
int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      // push(pop() - pop() is WRONG. pop() on left-hand-side of - could be either the first or second pop
      // because C does not enforce the order that arguments are evaluated.
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
	push(pop() / op2);
      else
	printf("error: zero divisor\n");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

#define MAXVAL 100 // maximum depth of stack.

int sp = 0;
double val[MAXVAL];
// push: push f onto value stack.
void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n.", f);
}

// pop: pop and return top value from stack
double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stsack empty\n");
    return 0.0;
  }
}

#include <ctype.h>
int getch(void);
void ungetch(int);

// getop: get next operator of numeric operand.
int getop(char s[]) {
  int i, c;
  // Question: (T or F) The sole purpose of the statement below is to skip over spaces and tabs.
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;  // not a number.
  i = 0;
  if (isdigit(c))  // collect integer part.
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.') // collect fractional part.
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;  // next free position in buf.

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {  // push character back on input.
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters.\n");
  else
    buf[bufp++] = c;
}
  
#endif

// Topic: Scope.
// Question: (T or F) The scope of a name is the part of the program within whch the name can be used.

// Topics: variable scope, initialization of variables, external linkage.
// For the questions that use P4 - P12, study the differences to see what
// causes compilation errors.

#ifdef P4
// Question (T or F) The program below will compile without error.
#include <stdio.h>
int main() {
  printf("%d\n", my_variable);
}
int my_variable;

#endif

#ifdef P5
// Question (T or F) The program below will compile without error.
#include <stdio.h>
int my_variable = 4;
int main() {
  printf("%d\n", my_variable);
}
int my_variable;

#endif

#ifdef P6
// Question (T or F) The program below will compile without error.
#include <stdio.h>
int my_variable=4;
int main() {
  printf("%d\n", my_variable);
}
int my_variable=5;

// Error: ch4_studyQuestions.c:278:5: error: redefinition of 'my_variable'
#endif

#ifdef P7
// Question (T or F) The program below will compile without error.

// in my_variable is a declaration, int my_variable=5 is a definition.
// illegal for g++: ch4_studyQuestions.c:292:5: error: redefinition of 'my_variable'
#include <stdio.h>
int my_variable;
int main() {
  printf("%d\n", my_variable);
}
int my_variable=5;
#endif

#ifdef P8
// Question (T or F) The program below will compile without error.

#include <stdio.h>
int my_variable = 4;
int main() {
  int my_variable = 3;
  printf("%d\n", my_variable);
}
#endif

#ifdef P9
// Question (T or F) The program below will compile without error.

#include <stdio.h>
int my_variable = 4;
int main() {
  static int my_variable = 3;
  printf("%d\n", my_variable);
}
#endif

#ifdef P10
// Question (T or F) The program below will compile without error.

#include <stdio.h>
static int my_variable = 4;
int main() {
  static int my_variable = 3;
  printf("%d\n", my_variable);
}
#endif

#ifdef P11
// Question (T or F) The program below will compile without error.

// Note: variables cannot be seen outside of the block where they are declared.
#include <stdio.h>
int my_variable = 4;
int main() {
  int my_variable = 3; {
    int my_variable = 4;
  }
  printf("%d\n", my_variable);
}
#endif

#ifdef P12
// Topic: scope.
// Question How many compilation errors will this program generate?

#include <stdio.h>
double foo () {return 2;}
double my_variable = 4 * 3 / foo();
int main() {
  double my_variable = 4 * 3 / foo();
  printf("%f\n", my_variable);
}
#endif

#ifdef P13
#include <stdio.h>
// Recursive printd
void printd(int n) {
  if (n < 0) {
    putchar('-');
    n = - n;
  }
  if (n / 10)
    printd(n / 10);
  putchar (n % 10 + '0');
}

int main() {
  printd(1234);
}
#endif

#ifdef P14
#include <stdio.h>

int fib(int x) {
    if (x == 0)
        return 0;

    if (x == 1)
        return 1;

    return fib(x-1)+fib(x-2);
}

int main() {
  int inputValue = 10;
  for (int i=0; i<=inputValue; i++)
    printf("fib(%d):%d\n", i, fib(i));
}

#endif

#ifdef P15
// Topic: Writing and using macros.
// Question: What value will this program print?

#define max(A, B) ((A) > (B) ? (A) : (B))
int main() {
  int i=0, j=0;
  int val = max(i++, j++);
  printf("%d\n", val);
}

#endif

#ifdef P16
// Topic: Writing and using macros.
// Question: What value will this program print?
#define square(x) x * x
#include <stdio.h>
int main() {
  int value = square(2-1);
  // Note: converts to 2 -1 * 2 - 1 -> 2 - (-1 * 2) - 1
  printf("%d\n", value);
}

#endif

#ifdef P17
#include <stdio.h>
int main() {
  printf("%d\n", '0');
}
#endif

#ifdef P18
// Topic: Using the extern keyword.
// Question: What will this program print?
// Ans: 
#include <stdio.h>
int my_variable = 5;
int main() {
  int foo(int);
  int my_variable = 6;
  printf("%d\n", foo(my_variable));
}

int foo(int a) {
  extern int my_variable;
  return my_variable + a;
}
#endif

```