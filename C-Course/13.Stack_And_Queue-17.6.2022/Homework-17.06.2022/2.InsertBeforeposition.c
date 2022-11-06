// Напишете функция, с която да вмъкнете възел „t“ преди възел, посочен с „X“ в
// единичен свързан списък „L“.

#include "func.h"

node *createNode(size_t value);
void insertElementOnPosition(node *startNode, node *newNode, size_t positionValue);

int main()
{
    const size_t listSize = 10;
    node *list = createList(listSize);
    node *newNode = NULL;
    size_t numberToInsert = 69;
    const size_t testSize = 3;
    size_t positionValues[] = {1, 4, 10};

    if (list == NULL)
    {
        printf("Not enough memory!");
        return 1;
    }

    printList(list);
    
    for (size_t i = 0; i < testSize; i++)
    {
        newNode = createNode(numberToInsert + i);

        if (newNode == NULL)
        {
            printf("Not enough memory!");
        }
        
        insertElementOnPosition(list, newNode, positionValues[i]);
    }
    
    printList(list);
    deinitList(list);

    return 0;
}

void insertElementOnPosition(node *startNode, node *newNode, size_t positionValue)
{
    node *previousNode = NULL;
    node *currentNode = startNode;
    node *nodeToInsert = newNode;
    size_t currentValue = 0;

    while (currentNode != NULL)
    {
        if (currentNode->value == positionValue)
        {
            if (previousNode == NULL)
            {
                currentValue = currentNode->value;
                previousNode = currentNode->next;
                currentNode->value = nodeToInsert->value;
                nodeToInsert->value = currentValue;
                currentNode->next = nodeToInsert;
                nodeToInsert->next = previousNode;

            }
            else
            {
                previousNode->next = nodeToInsert;
                nodeToInsert->next = currentNode;
            }

            break;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
}

node *createNode(size_t value)
{
    node *newNode = malloc(sizeof(node));

    if (newNode == NULL)
    {
        return NULL;
    }
    
    newNode->value = value;
    newNode->next = NULL;
    
    return newNode;
}