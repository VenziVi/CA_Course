// Задача 8. Напишете програма за триене на елемент от двойно свързан
// списък по зададена позиция в него.


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
bool isDeletedSuccessfully(dLNode *startNode, size_t position);
void deinitList(dLNode *startNode);
void deleteFirstElement(dLNode *node);
void deleteLastElement(dLNode *node);
void deleteMiddleElement(dLNode *node);

int main()
{
    const size_t listSize = 9;
    const size_t positionToRemove = 4;
    bool isDeleted = false;

    dLNode *list = createDoubleLinkedList(listSize);

    if (list == NULL)
    {
        printf("Not enough memory!");
        return 1;
    }

    printList(list);

    isDeleted = isDeletedSuccessfully(list, positionToRemove);
    (isDeleted) ? printf("Element on position %I64d deleted successfully. \n", positionToRemove) :
                    printf("Position %I64d was not found. \n", positionToRemove);

    printList(list);

    deinitList(list);
    return 0;
}

bool isDeletedSuccessfully(dLNode *startNode, size_t position)
{
    dLNode *currentNode = startNode;
    size_t currentPosition = 1;

    while (currentNode != NULL)
    {
        if (position == currentPosition)
        {
            if (currentNode->prev == NULL)
            {
                deleteFirstElement(currentNode);
            }
            else if (currentNode->next == NULL)
            {
                deleteLastElement(currentNode);
            }
            else
            {
                deleteMiddleElement(currentNode);
            }

            return true;
        }
        else
        {
            currentNode = currentNode->next;
            currentPosition++;
        }
    }
    return false;
}

void deleteMiddleElement(dLNode *node)
{
    dLNode *tempNode = node;
    dLNode *previousNode = tempNode->prev;
    dLNode *nextNode = tempNode->next;
    nextNode->prev = previousNode;
    previousNode->next = nextNode;
    free(tempNode);
}

void deleteLastElement(dLNode *node)
{
    dLNode *currentNode = node;
    dLNode *tempNode = currentNode->prev;
    dLNode *previousNode = tempNode->prev;
    currentNode->value = tempNode->value;
    currentNode->prev = previousNode;
    previousNode->next = currentNode;
    free(tempNode);
}

void deleteFirstElement(dLNode *node)
{
    dLNode *currentNode = node;
    dLNode *tempNode = currentNode->next;
    dLNode *nextNode = tempNode->next;
    currentNode->value = tempNode->value;
    currentNode->next = nextNode;
    nextNode->prev = currentNode;
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