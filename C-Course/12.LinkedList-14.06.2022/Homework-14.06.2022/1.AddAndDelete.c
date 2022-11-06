// Задача 1. Реализация на списък. Напишете програма, която добавя и
// изтрива елемент от списък по позиция в списъка.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    size_t value;
    struct node *next;
} node;

size_t setInteger(char msg[]);
node *createList(size_t size);
void printList(node *startNode);
size_t removeElementFromList(node *startNode, size_t position);
node* insertElementInList(node *startNode, size_t position);
void deinitList(node *startNode);

int main()
{
    size_t size = setInteger("Enter list size: ");
    node *list = createList(size);

    if (list == NULL)
    {
        printf("Not enough memory!");
        return 1;
    }

    printList(list);
    size_t positionToRemove = 0;
    size_t positionToInsert = 0;
    size_t deletedElement = 0;

    // press 'd' to delete element on input position
    // press 'i' to insert element on input position 
    // pres 'q' to quit program
    char choice;
    printf("Press 'i' for insert, 'd' for delete or 'q' to quit: ");
    scanf(" %c", &choice);

    while (choice != 'q')
    {
        if (choice == 'd')
        {
            positionToRemove = setInteger("Enter position to delete, starting from 1: ");
            deletedElement = removeElementFromList(list, positionToRemove);

            if (deletedElement > 0)
            {
                printf("Element on position %I64d is deleted. \n", deletedElement);
            }
            else
            {
                printf("Position not found! \n");
            }

            printList(list);
        }
        else if(choice == 'i')
        {
            positionToInsert = setInteger("Enter position to insert at, starting from 1: ");
            list = insertElementInList(list, positionToInsert);
            printList(list);
        }

        printf("Press 'i' for insert, 'd' for delete or 'q' to quit: ");
        scanf(" %c", &choice);
    }

    printList(list);

    deinitList(list);
    return 0;
}

// insert an element at a given position
// value is equal to a given position
// if there is no such position in the list, the element will be placed at the last position
node* insertElementInList(node *startNode, size_t position)
{
    node *newNode = malloc(sizeof(node));
    node *prev_ptr = NULL;
    node *last_ptr = NULL;
    size_t currentPosition = 1;

    if (newNode == NULL)
    {
        return startNode;
    }
    
    newNode->value = position;
    newNode->next = NULL;

    // insert element on first position
    if (position == 1)
    {
        newNode->next = startNode;
        startNode = newNode;
        return startNode;
    }

    prev_ptr = startNode;
    last_ptr = startNode->next;

    // insert element in the middle position
    while (last_ptr->next != NULL)
    {

        if (currentPosition == position)
        {
            prev_ptr->next = newNode;
            newNode->next = last_ptr;
            return startNode;
        }
        
        prev_ptr = last_ptr;
        last_ptr = last_ptr->next;
        currentPosition++;
    }

    // insert element at the end of the list
    last_ptr->next = newNode;
    return startNode;
}

// delete element from the given position if position exists
// returns given position
// if there is no such position -> return 0
size_t removeElementFromList(node *start, size_t position)
{
    size_t notFound = 0;
    size_t currPosition = 2;
    node *pos_ptr = NULL;
    node *prev_ptr = NULL;

    if (position > 1)
    {
        pos_ptr = start->next;

        // remove element in the middle position
        while (pos_ptr != NULL)
        {
            if (currPosition == position)
            {
                prev_ptr->next = pos_ptr->next;
                free(pos_ptr);

                return position;
            }
        
            currPosition++;
            prev_ptr = pos_ptr;
            pos_ptr = pos_ptr->next;
        }

        // remove element on the last position
        if (position == ++currPosition)
        {
            node *ptr_el = pos_ptr->next;
            pos_ptr->next = NULL;
            free(ptr_el);

            return position;
        }
        
    }  
    // remove element on the first position
    else if (position == 1)
    {
        node *next = start->next;
        start->value = next->value;
        start->next = next->next;
        free(next);

        return position;
    } 

    return notFound;
}

// create list with given size 
// the values are equal to the position index
// returns NULL if there is not enough space for the entire list
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