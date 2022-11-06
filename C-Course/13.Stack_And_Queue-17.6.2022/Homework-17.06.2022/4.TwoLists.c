// Да предположим, че подреден списък L = (l0, l1, .....,ln) е представен от единичен свързан
// списък. Добавете списъка L = (ln, l0, l1, ....., ln) след друг подреден списък M, представен от
// единично свързан списък

#include "func.h"

void concatLists(node *firstList, node *secondList);

int main()
{
    const size_t listSize = 7;
    node *firstList = createList(listSize);
    node *secondList = createList(listSize);

    if (firstList == NULL || secondList == NULL)
    {
        printf("Not enough memory!");
        return 1;
    }

    printList(firstList);
    printList(secondList);
    
    concatLists(firstList, secondList);

    printList(firstList);

    deinitList(firstList);
    return 0;
}

void concatLists(node *firstList, node *secondList)
{
    node *currentNode = firstList;

    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }

    currentNode->next = secondList;
}