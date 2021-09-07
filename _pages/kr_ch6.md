---
layout: page
toc: false
title: "K & R Chapter 6 Study Questions"
---

```c

#ifdef P1
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
  printf("(%d, %d)\n\r", p.x, p.y);
}

// Question: What does this program print?
int main() {
  struct point p1 = makePoint(3, 4);
  struct point p2 = p1;
  printPoint(p2);
}
#endif

#ifdef P2
#include <stdio.h>

struct point {
  int x;
  int y;
};

void printPoint(struct point p) {
  printf("(%d, %d)\n\r", p.x, p.y);
}

// Question: What does this program print?
void modifyPoint(struct point p) {
  p.x++;
  p.y++;
}

int main() {
  struct point p1 = {3, 4};
  modifyPoint(p1);
  printPoint(p1);
}
#endif

#ifdef P3
#include <stdio.h>
struct point {
  int x;
  int y;
};

void printPoint(struct point p) {
  printf("(%d, %d)\n\r", p.x, p.y);
}

// Question: What does this program print?
void modifyPoint(struct point p) {
  p.x++;
  p.y++;
}

int main() {
  struct point p[2] = { {3, 4}, {4, 5} };
  modifyPoint(p[0]);
  printPoint(p[0]);
}
#endif

#ifdef P4
#include <stdio.h>
// Question: What does this program print?
struct point {
  int x;
  int y;
};

void printPoint(struct point p) {
  printf("(%d, %d)\n\r", p.x, p.y);
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
#endif

#ifdef P5
// Question: What does this program print?
#include <stdio.h>
struct point {
  int x;
  int y;
};

void printPoint(struct point p) {
  printf("(%d, %d)\n\r", p.x, p.y);
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
#endif

#ifdef P6
// Question: What argument must be passed to printPoint()?
struct point {
  int x;
  int y;
};

void printPoint(struct point p) {
  printf("(%d, %d)\n\r", p.x, p.y);
}

void modifyPoint(struct point* p) {
  p->x = 4;
  p->y = 5;
}

int main() {
  struct point* p[2];
  struct point p0 = {3, 4};
  p[0] = &p0;
  printPoint();
}
#endif

#ifdef P7
// Question: What will this program print?
#include <stdio.h>
struct point {
  int x;
  int y;
};

void printPoint(struct point p) {
  printf("(%d, %d)\n\r", p.x, p.y);
}

int main() {
  struct point p[2];
  struct point p0 = {3, 4};
  p[0] = p0;
  p[0].x++;
  p[0].y++;
  printPoint(p0);
}
#endif

#ifdef P8
// Question: What will this program print?
#include <stdio.h>
struct point {
  int x;
  int y;
};

void printPoint(struct point p) {
  printf("(%d, %d)\n\r", p.x, p.y);
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
#endif

#ifdef P9
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
  // Question: Select the answers so that the program will compile and will print 3 4 5
  struct node* n0 = nalloc(3);
  struct node* n1 = nalloc(4);
  struct node* n2 = nalloc(5);
  n0->link = n1;
  n1->link = n2;
  p(n0);
}
//  Ans: @1: ?, @2: ?, @3: ?
#endif

#ifdef P10
// Question: Modify the commented code below so that the keyword struct does not appear in the body of the declaration for node, so that the main() function below will compile without error.
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

#endif

```