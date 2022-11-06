// Задача 6. Напишете програма за въвеждане на елемент по средата на
// двойно свързан списък.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    size_t value;
    struct node *next;
    struct node *prev;
} dLNode;

dLNode *createDoubleLinkedList(size_t size);
void printList(dLNode *startNode);
void inserInTheMiddle(dLNode *middleNode, size_t value);
dLNode *findMiddleNode(dLNode *startNode, dLNode *lastNode, size_t listSize);
dLNode *getLastNode(dLNode *startNode);
void deinitList(dLNode *startNode);

int main()
{
    const size_t listSize = 8;
    const size_t elementValue = 666;

    dLNode *middleNode = NULL;
    dLNode *lastNode = NULL;

    dLNode *list = createDoubleLinkedList(listSize);

    if (list == NULL)
    {
        printf("Not enough memory!");
        return 1;
    }

    lastNode = getLastNode(list);

    printList(list);

    middleNode = findMiddleNode(list, lastNode, listSize);

    inserInTheMiddle(middleNode, elementValue);

    printList(list);

    deinitList(list);
    return 0;
}

dLNode *findMiddleNode(dLNode *startNode, dLNode *lastNode, size_t listSize)
{
    dLNode *beginNode = startNode;
    dLNode *endNode = lastNode;
    dLNode *middleNode = NULL;

    if (listSize % 2 == 0)
    {
        while (beginNode->next != endNode)
        {
            beginNode = beginNode->next;
            endNode = endNode->prev;
        }
        
        middleNode = beginNode;
    }
    else
    {
        while (beginNode->next != endNode->prev)
        {
            beginNode = beginNode->next;
            endNode = endNode->prev;
        }
        
        middleNode = beginNode->next;
    }
    
    return middleNode;
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

void inserInTheMiddle(dLNode *middleNode, size_t value)
{
    dLNode *newNode = malloc(sizeof(dLNode));
    newNode->value = value;

    dLNode *previousNode = middleNode;
    dLNode *nextNode = middleNode->next;

    newNode->next = nextNode;
    nextNode->prev = newNode;

    newNode->prev = previousNode;
    previousNode->next = newNode;
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
    dLNode *end_ptr = NULL;

    printf("-->   ");
    while (print_ptr != NULL)
    {
        printf("%I64d \t", print_ptr->value);
        end_ptr = print_ptr;
        print_ptr = print_ptr->next;
    }

    printf("\n");
    printf("<--   ");
    while (end_ptr != NULL)
    {
        printf("%I64d \t", end_ptr->value);
        end_ptr = end_ptr->prev;
    }
    
    printf("\n");
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