#ifndef STACK
#define STACK

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *word;
    struct node *next;
} node;

typedef node *stack;

int allSymbolsCount(stack *stackNode);
void deinitStack(stack *stackNode);
int menu(void);
char* maxSymbolWord(stack *stackNode, int maxSymbols);
bool push(stack *stackNode, char *word);
char* pop(stack *stackNode);
void printStack(stack *stacknode);
void printCurrenrSymbolWord(stack *stackNode, int command);

#endif