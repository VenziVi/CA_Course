// Задача 2. Направете едносвързан списък, съдържащ числата 1-14 и
// принтирайте петия елемент от края му.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    size_t value;
    struct node *next;
} node;

node *createList(size_t size);
void deinitList(node *startNode);
void printList(node *startNode);
void printPositionFromEnd(node *startNode, size_t positonToPrint);

int main()
{
    size_t const listSize = 14;
    size_t const positionToPrint = 5;
    node *list = createList(listSize);

    if (list == NULL)
    {
        printf("Not enough memory!");
        return 1;
    }

    printList(list);

    printPositionFromEnd(list, positionToPrint);

    deinitList(list);
    return 0;
}

void printPositionFromEnd(node *startNode, size_t positonToPrint)
{    
    node *firstNode = startNode;
    node *secondNode = startNode;
    size_t positionCounter = 1;

    while (positionCounter < positonToPrint && firstNode != NULL)
    {
        firstNode = firstNode->next;
        positionCounter++;
    }

    if (firstNode != NULL && positionCounter == positonToPrint)
    {
        while (firstNode->next != NULL)
        {
            firstNode = firstNode->next;
            secondNode = secondNode->next;
        }

        printf("Element on position %I64d is %I64d. \n", positonToPrint, secondNode->value);
    }
    else
    {
        printf("Position not found!");
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