#include "stack_.h"

void push(stackPtr *top, int x)
{
    stackPtr nodePtr;

    nodePtr = malloc(sizeof(Stack));

    if (nodePtr != NULL)
    {
        nodePtr->data = x;
        nodePtr->ptr = *top;
        *top = nodePtr;
    }
    else
    {
        printf("\n Not enought memory!");
    }
}

int pop(stackPtr *top)
{
    int val = 0;
    stackPtr temPtr = *top;

    val = (*top)->data;
    *top = (*top)->ptr;
    free(temPtr);
    return val;
}

void printValue(stackPtr showPtr)
{
    if (showPtr == NULL)
    {
        printf(" \n No value found!");
    }
    else
    {
        printf("\n Data stored in stack: \n");
        while (showPtr != NULL)
        {
            printf(" %d --> \n", showPtr->data);
            showPtr = showPtr->ptr;
        }

        printf("NULL \n");
    }
    
}

int checkEmpty(stackPtr top)
{
    return top == NULL;
}