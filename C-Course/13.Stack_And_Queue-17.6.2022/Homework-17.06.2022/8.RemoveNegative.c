// Даден е стек от произволни реални числа. Да се напише програма, която
// изтрива от този стек всички отрицателни числа

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_EMPTY INT_MIN

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef node *stack;

bool push(stack *stackNode, int value);
int pop(stack *stackNode);
void setPositiveStack(stack *stackNode, stack *positiveStck);
void printStack(stack *stackNode);


int main()
{
    stack myStack = NULL;
    stack positiveStack = NULL;    

    const int testSize = 10;
    const int test[] = {3, -5, 0, 2, -9, 11, -24, 23, -55, 1};

    for (int i = 0; i < testSize; i++)
    {
        (push(&myStack, test[i])) ?
            printf("%d pushed in stack successfully! \n", test[i]):
            printf("Not enough memory! \n");
    }

    setPositiveStack(&myStack, &positiveStack);

    printStack(&positiveStack);
    
    return 0;
}

void setPositiveStack(stack *stackNode, stack *positiveStck)
{
    int popResult = 0;

    printf("\n");
    while ( (popResult = pop(stackNode)) != STACK_EMPTY)
    {
        if (popResult >= 0)
        {
            (push(positiveStck, popResult)) ?
                printf("%d pushed in positive stack successfully! \n", popResult):
                printf("Not enough memory! \n");
        }
    }
}

bool push(stack *stackNode, int value)
{
    node *newNode = malloc(sizeof(node));

    if (newNode == NULL)
    {
        return false;
    }

    newNode->value = value;
    newNode->next = *stackNode;
    *stackNode = newNode;

    return true;
}

int pop(stack *stackNode)
{
    node *tempNode = NULL;
    int result = 0;

    if (*stackNode == NULL)
    {
        return STACK_EMPTY;
    }

    result = (*stackNode)->value;
    tempNode = *stackNode;
    *stackNode = (*stackNode)->next;
    free(tempNode);

    return result;
    
}

void printStack(stack *stackNode)
{
    int popResult = 0;

    printf("\nPositive stack: ");
    while ( (popResult = pop(stackNode)) != STACK_EMPTY)
    {
        printf("%d \t", popResult);
    }
}
