#include <stdio.h>
#include <stdlib.h>

#define STACK_EMPTY INT_MIN

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef node *stack;

void push(stack *stackNode, int value);
int pop(stack *stackNode);
void display(stack *stackNode);