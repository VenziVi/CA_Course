#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *ptr;
};

typedef struct stack Stack;
typedef Stack *stackPtr;

void push(stackPtr *top, int x);
int pop(stackPtr *top);
int checkEmpty(stackPtr top);
void printValue(stackPtr showPtr);
