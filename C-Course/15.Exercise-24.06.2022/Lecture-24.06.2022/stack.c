#include "stack.h"

void push(stack *stackNode, int value)
{
    node *newNode = malloc(sizeof(node));

    if (newNode == NULL)
    {
        return;
    }

    newNode->data = value;
    newNode->next = *stackNode;
    *stackNode = newNode;
}

int pop(stack *stackNode)
{
    node *tempNode = NULL;
    int result = 0;

    if (*stackNode == NULL)
    {
        return STACK_EMPTY;
    }

    result = (*stackNode)->data;
    tempNode = *stackNode;
    *stackNode = (*stackNode)->next;
    free(tempNode);

    return result;
}

void display(stack *stackNode)
{
    struct node *temp = *stackNode;

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}