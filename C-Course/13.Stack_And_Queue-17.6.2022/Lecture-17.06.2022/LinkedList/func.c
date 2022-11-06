#include "func.h"

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
            deinitDoubleList(startNode);
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

void printDoubleList(dLNode *start)
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

void deinitDoubleList(dLNode *startNode)
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

void deinitList(node *startNode)
{
    node *ptr = startNode;
    node *next_ptr = NULL;

    while (ptr != NULL)
    {
        next_ptr = ptr->next;
        free(ptr);
        ptr = next_ptr;
    }
}

node *createList(size_t size)
{
    node *headNode = NULL;
    node *currNode = NULL;
    node *tempNode = NULL;
    node *lastNode = NULL;

    for (size_t i = 0; i < size; i++)
    {
        tempNode = malloc(sizeof(node));

        if (tempNode == NULL)
        {
            deinitList(headNode);
            return NULL;
        }

        tempNode->value = i + 1;
        tempNode->next = NULL;

        if (headNode == NULL)
        {
            headNode = tempNode;
            lastNode = tempNode;
        }
        else
        {
            currNode = lastNode;
            currNode->next = tempNode;
            lastNode = tempNode;
        }
    }

    return headNode;
}

void printList(node *start)
{
    node *print_ptr = NULL;
    print_ptr = start;

    while (print_ptr != NULL)
    {
        printf("%I64d \t", print_ptr->value);
        print_ptr = print_ptr->next;
    }

    printf("\n");
}

size_t setInteger(char msg[])
{
    size_t size = 0;
    printf("%s", msg);
    scanf("%I64d", &size);
    return size;
}