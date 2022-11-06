// Задача 3. Моделиране на играта “Броеница”: N деца застават в кръг
// и получават номера от 1 до N. Като се започне от дете 1, по
// часовниковата стрелка се отброяват М деца. Дете с номер М излиза
// от кръга, след което започва ново броене от следващото дете.
// Продължава, докато остане само едно дете, чийто номер трябва да
// се определи.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    size_t value;
    struct node *next;
} node;

node *createList(size_t size);
void deinitList(node *startNode);
node *lastSurvivor(node *startNode, size_t kidsPass, size_t kidsCount);

int main()
{
    const size_t testSize = 3;
    const size_t listSizeTests[] = {8, 12, 19};
    const size_t kidsPassTests[] = {3, 5, 7};
    node *survivor = NULL;
    node *list = NULL;

    for (size_t i = 0; i < testSize; i++)
    {
        list = createList(listSizeTests[i]);

        if (list == NULL)
        {
            printf("Not enough memory!");
            return 1;
        }

        survivor = lastSurvivor(list, kidsPassTests[i], listSizeTests[i]);
        printf("Survivor from test[%I64d] is %I64d \n", i, survivor->value);

        free(survivor);
    }

    return 0;
}

node *lastSurvivor(node *startNode, size_t kidsPass, size_t kidsCount)
{
    node *currKid = startNode;
    node *previousKid = NULL;
    node *tempKid = NULL;
    size_t kidsCounter = 1;
    size_t kidsLeft = kidsCount;

    if (kidsCount == 1)
    {
        return startNode;
    }
    
    while (currKid->next != NULL)
    {
        if (kidsCounter % kidsPass == 0)
        {
            if (kidsLeft > 2)
            {
                tempKid = currKid;
                currKid = currKid->next;
                previousKid->next = currKid;
                free(tempKid);
            }
            else
            {
                tempKid = currKid;
                currKid = previousKid;
                currKid->next = NULL;
                free(tempKid);
            }

            kidsLeft--;
        }
        else
        {
            previousKid = currKid;
            currKid = currKid->next;
        }

        kidsCounter++;
    }

    return currKid;
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

    tempNode->next = headNode;
    return headNode;
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