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


void changeElementValue(stack *stackNode, size_t position, size_t value)
{
    node *countingNode = *stackNode;
    node *currentNode = *stackNode;
    size_t positionCounter = 0;

    while (positionCounter < position && countingNode != NULL)
    {
        countingNode = countingNode->next;
        positionCounter++;        
    }

    if (positionCounter == position && countingNode == NULL)
    {
        currentNode->value = value;
    }
    else if (countingNode != NULL)
    {
        while (countingNode != NULL)
        {
            countingNode = countingNode->next;
            currentNode = currentNode->next;
        }

        currentNode->value = value;
    }
}

void changeValueWithArray(stack *stackNode, size_t position, size_t value)
{
    node *countingNode = *stackNode;
    size_t positionCounter = 0;
    size_t arrayInitSize = 20;
    size_t *tempArr = malloc(arrayInitSize * sizeof(size_t));
    size_t index = 1;

    while (positionCounter < position && countingNode != NULL)
    {
        countingNode = countingNode->next;
        positionCounter++;
    }

    if (positionCounter == position && countingNode == NULL)
    {
        (*stackNode)->value = value;
    }
    else if (countingNode != NULL)
    {
        while (countingNode != NULL)
        {
            if (index == arrayInitSize)
            {
                arrayInitSize *= 2;
                tempArr = realloc(tempArr, arrayInitSize * sizeof(size_t));
            }

            tempArr[index++] = pop(stackNode);
            countingNode = countingNode->next;
        }

        index--;
        (*stackNode)->value = value;

        while (index > 0)
        {
            push(stackNode, tempArr[index--]);
        }
    }

    free(tempArr);
}