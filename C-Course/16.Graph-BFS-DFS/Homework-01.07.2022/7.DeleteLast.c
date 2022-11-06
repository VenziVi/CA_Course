// Задача 7. Напишете програма за триене на N-тия елемент от края на двойно
// свързан списък.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
        size_t value;
        struct node *next;
        struct node *prev;
} dLNode;

dLNode *createDoubleLinkedList(size_t size);
void printList(dLNode *lastNode);
void deinitList(dLNode *startNode);
void deleteLastElement(dLNode *lastNode);
dLNode *getLastNode(dLNode *startNode);

int main()
{
    const size_t listSize = 9;
    const size_t deletedElementsCount = 4;

    dLNode *list = createDoubleLinkedList(listSize);
    if (list == NULL)
    {
        printf("Not enough memory!");
        return 1;
    }

    printList(list);

    dLNode *listLastElement = getLastNode(list);

    for (size_t i = 0; i < deletedElementsCount; i++)
    {
        deleteLastElement(listLastElement);
        printList(list);
    }

    deinitList(list);
    return 0;
}

dLNode *getLastNode(dLNode *startNode)
{
    dLNode *currentNode = startNode;

    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    return currentNode;
}

void deleteLastElement(dLNode *lastNode)
{
    dLNode *currentNode = lastNode;
    dLNode *tempNode = currentNode->prev;
    dLNode *previousNode = tempNode->prev;
    currentNode->value = tempNode->value;
    currentNode->prev = previousNode;
    previousNode->next = currentNode;
    free(tempNode);
}

dLNode *createDoubleLinkedList(size_t size)
{
    dLNode *startNode = NULL;
    dLNode *tempNode = NULL;
    dLNode *currentNode = NULL;
    dLNode *lastNode = NULL;

    for (size_t i = 0; i < size; i++)
    {
        tempNode = malloc(sizeof(dLNode));

        if (tempNode == NULL)
        {
            deinitList(startNode);
            return NULL;
        }

        tempNode->value = i * 2;
        tempNode->next = NULL;
        tempNode->prev = NULL;

        if (startNode == NULL)
        {
            startNode = tempNode;
            lastNode = tempNode;
        }
        else
        {
            currentNode = lastNode;
            currentNode->next = tempNode;
            tempNode->prev = currentNode;
            lastNode = tempNode;
        }
    }
    
    return startNode;
}

void printList(dLNode *start)
{
    dLNode *print_ptr = start;

    while (print_ptr != NULL)
    {
        printf("%I64d \t", print_ptr->value);
        print_ptr = print_ptr->next;
    }

    printf("\n");
}

void deinitList(dLNode *startNode)
{
    dLNode *ptr = startNode;
    dLNode *next_ptr = NULL;

    while (ptr != NULL)
    {
        next_ptr = ptr->next;
        free(ptr);
        ptr = next_ptr;
    }
}