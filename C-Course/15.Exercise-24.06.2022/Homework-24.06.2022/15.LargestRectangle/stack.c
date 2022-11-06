#include "stack.h"

bool push(stack *stackNode, size_t value)
{
    node *newNode = malloc(sizeof(node));

    if (newNode == NULL)
    {
        return false;
    }

    newNode->value = value;
    newNode->next = NULL;

    if (*stackNode == NULL)
    {
        *stackNode = newNode;
        return true;
    }
    
    newNode->next = *stackNode;
    *stackNode = newNode;
    
    return true;
}

size_t pop(stack *stackNode)
{
    node *tempNode = NULL;
    size_t popResult = 0;

    if (*stackNode == NULL)
    {
        return STACK_EMPTY;
    }

    popResult = (*stackNode)->value;

    tempNode = *stackNode;
    *stackNode = (*stackNode)->next;

    free(tempNode);
    return popResult;
}

void printStack(stack *stacknode)
{
    node *tempNode = *stacknode;

    while (tempNode != NULL)
    {
        printf("%I64d ", tempNode->value);
        tempNode = tempNode->next;
    }
    printf("\n");
}

void deinitStack(stack *stackNode)
{
    node *tempNode = *stackNode;
    node *nextNode = NULL;

    while (tempNode != NULL)
    {
        nextNode = tempNode->next;
        free(tempNode);
        tempNode = nextNode;
    }
}

size_t largestRectangleArea(size_t arr[], size_t size)
{
    stack myStack = NULL;
    size_t newArea = 0;
    size_t height = 0;
    size_t width = 0;
    size_t maxArea = 0;

    for (size_t i = 1; i <= size; i++)
    {
        while(myStack != NULL && (i == size || arr[myStack->value] >= arr[i]))
        {
            height = arr[myStack->value];
            pop(&myStack);

            if (myStack == NULL)
            {
                width = i;
            }
            else
            {
                width = i - myStack->value - 1;
            }

            newArea = width * height;

            if (maxArea < newArea)
            {
                maxArea = newArea;
            }
        }
        push(&myStack, i);
    }

    deinitStack(&myStack);

    return maxArea;
}