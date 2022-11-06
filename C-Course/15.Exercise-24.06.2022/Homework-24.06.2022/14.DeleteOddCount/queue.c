#include "queue.h"

bool enqueue(queue *queueNode, size_t value)
{
    node *newNode = malloc(sizeof(node));

    if (newNode == NULL)
    {
        return false;
    }

    newNode->value = value;
    newNode->next = NULL;

    if (queueNode->tail != NULL)
    {
        queueNode->tail->next = newNode;
    }

    queueNode->tail = newNode;

    if (queueNode->head == NULL)
    {
        queueNode->head = newNode;
    }
    
    return true;
}


size_t dequeue(queue *queueNode)
{
    size_t result = 0;
    node *tempNode = NULL;

    if (queueNode->head == NULL)
    {
        return QUEUE_EMPTY;
    }

    result = queueNode->head->value;
    tempNode = queueNode->head;
    queueNode->head = queueNode->head->next;

    free(tempNode);
    return result;
}


void display(queue *queueNode)
{
    node *tempNode = queueNode->head;

    printf("\n");
    while (tempNode != NULL)
    {
        printf("%I64d ", tempNode->value);
        tempNode = tempNode->next;
    }
    printf("\n");
}


void deinitQueue(queue *queueNode)
{
    node *tempNode = queueNode->head;
    node *nextNode = NULL;

    while (tempNode != NULL)
    {
        nextNode = tempNode->next;
        free(tempNode);
        tempNode = nextNode;
    }
}


queue *initQueue(void)
{
    queue *newQueu = malloc(sizeof(queue));
    newQueu->head = NULL;
    newQueu->tail = NULL;

    return newQueu;
}


void firstFilter(queue *myQueue, size_t arr[], size_t size)
{
    size_t currValue = 0;
    size_t occurrences = 0;

    for (size_t i = 0; i < size; i++)
    {
        currValue = arr[i];
        occurrences = 0;

        for (size_t j = 0; j < size; j++)
        {
            if (currValue != arr[j])
            {
                occurrences++;
            }
        }

        if (occurrences % 2 != 0)
        {
            enqueue(myQueue, currValue);
        }
    }
}

void secondFilter(queue *myQueue, size_t size)
{
    size_t iterations = 1;
    size_t value = 0;
    size_t dequeueValue = 0;
    size_t occurrences = 1;
    size_t chaeckSize = size - 1;

    while (iterations < size)
    {
        value = dequeue(myQueue);
        occurrences = 1;

        for (size_t i = 0; i < chaeckSize; i++)
        {
            dequeueValue = dequeue(myQueue);

            if (dequeueValue == value)
            {
                occurrences++;
            }
            
            enqueue(myQueue, dequeueValue);
        }

        if (occurrences == 1)
        {
            chaeckSize--;
            iterations++;
        }       
        else if (occurrences % 2 != 0)
        {
            for (size_t i = 0; i < chaeckSize + occurrences - 1; i++)
            {
                dequeueValue = dequeue(myQueue);

                if (dequeueValue != value)
                {
                    enqueue(myQueue, dequeueValue);
                }
                else
                {
                    chaeckSize--;
                    iterations++;
                }
            }
            chaeckSize--;
        }
        else
        {
            enqueue(myQueue, value);
            iterations++;
        }
    }
}

void setQueueFromArray(queue *myQueue, size_t arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        enqueue(myQueue, arr[i]);
    }
}
