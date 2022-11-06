// Напишете функция, с която да да изтриете възел, посочен с „p“ от едносвързан списък „L“.

#include <stdbool.h>
#include "func.h"

bool removeElementFromList(node *startNode, size_t value);

int main()
{
    const size_t listSize = 15;
    const size_t testSize = 4;
    size_t numbersToDlelte[] = {1, 7, 44, 15};
    node *list = createList(listSize);

    if (list == NULL)
    {
        printf("Not enough memory!");
        return 1;
    }

    printList(list);

    for (size_t i = 0; i < testSize; i++)
    {
        (removeElementFromList(list, numbersToDlelte[i])) ?
            printf("Element with value %I64d is deleted. \n", numbersToDlelte[i]) :
            printf("Element with value %I64d not found! \n", numbersToDlelte[i]);
    }
    
    printList(list);

    deinitList(list);
    return 0;
}

bool removeElementFromList(node *startNode, size_t value)
{
    node *currentNode = startNode;
    node *previousNode = NULL;
    node *nextNode = NULL;

    while (currentNode != NULL)
    {
        if (currentNode->value == value)
        {
            if (previousNode == NULL)
            {
                nextNode = currentNode->next;
                currentNode->value = nextNode->value;
                currentNode->next = nextNode->next;
                nextNode->next = NULL;
                free(nextNode);
            }
            else if (currentNode->next == NULL)
            {
                previousNode->next = NULL;
                free(currentNode);
            }
            else
            {
                previousNode->next = currentNode->next;
                currentNode->next = NULL;
                free(currentNode);
            }

            return true;
        }
        
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    return false;
}