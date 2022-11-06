#ifndef STACK
#define STACK

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_EMPTY SIZE_MAX

typedef struct node
{
    size_t value;
    struct node *next;
} node;

typedef node *stack;

bool push(stack *stackNode, size_t value);
size_t pop(stack *stackNode);
void printStack(stack *stacknode);
void deinitStack(stack *stackNode);
void changeElementValue(stack *stackNode, size_t position, size_t value);
void changeValueWithArray(stack *stackNode, size_t position, size_t value);

#endif