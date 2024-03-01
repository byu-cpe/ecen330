#include <stdio.h>

#define ADD '+'
#define SUB '-'
#define MULT '*'
#define DIV '/'

unsigned char n1;
unsigned char n2;
unsigned char operator;

void print(signed char result) {
    printf("%u %c %u = %d\n", n1, operator, n2, result);
}

void getUserInput() {
    n1 = getchar() - '0';
    operator = getchar();
    n2 = getchar() - '0';
}

signed char calculateResult(unsigned char n1, unsigned char n2, unsigned char operator) {   
    signed char result;

    if (operator == ADD)
        result = n1 + n2;
    else if (operator == SUB)
        result = n1 - n2;
    else if (operator == MULT)
        result = n1 * n2;
    else if (operator == DIV)
        result = n1 / n2;
    else
        result = 0;

    return result;
}

int main() {
    getUserInput();
    signed char result = calculateResult(n1, n2, operator);
    print(result);
}