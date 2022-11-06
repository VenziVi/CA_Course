// Напишете функция, с която да разделите даден едносвързан свързан списък от цели числа, в
// два списъка по следния начин.
// Ако първоначалният списък е L = (l0, l1, ....., ln), то
// новополучените списъци мжгот до са R1 = (l0, l2, l4, .....) и R2 = (l1, l3, l5, .....)

#include "func.h"

void splitList(node *originalList, node *evenList, node *oddList);
node *createNode(void);

int main()
{
    const size_t listSize = 20;
    node *evenList = createNode();
    node *oddList = createNode();
    node *list = createList(listSize);

    if (list == NULL || oddList == NULL || evenList == NULL)
    {
        printf("Not enough memory!");
        return 1;
    }

    printList(list);
    splitList(list, evenList, oddList);

    printList(evenList);
    printList(oddList);
    printList(list);

    free(list);
    deinitList(evenList);
    deinitList(oddList);

    return 0;
}

void splitList(node *originalList, node *evenList, node *oddList)
{
    node *currentNode = originalList;
    node *freeNode = NULL;
    node *evenLastNode = NULL;
    node *oddLastNode = NULL;

    while (currentNode != NULL)
    {
        if (currentNode->value % 2 == 0)
        {
            if (evenLastNode == NULL)
            {
                evenList->value = currentNode->value;
                evenLastNode = evenList;
            }
            else
            {
                evenLastNode->next = currentNode;
                evenLastNode = currentNode;
            }
        }
        else
        {
            if (oddLastNode == NULL)
            {
                oddList->value = currentNode->value;
                oddLastNode = oddList;
            }
            else
            {
                oddLastNode->next = currentNode;
                oddLastNode = currentNode;
            }
        }
        freeNode = currentNode;
        currentNode = currentNode->next;
        freeNode->next = NULL;
    }
}

node *createNode(void)
{
    node *newNode = malloc(sizeof(node));

    if (newNode == NULL)
    {
        return NULL;
    }

    newNode->value = 0;
    newNode->next = NULL;
    
    return newNode;
}