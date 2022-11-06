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


void setQueue(queue *queueNode, size_t arr[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        enqueue(queueNode, arr[i]);
    }
}


void sortResultQueue(queue *firstQueue, queue *secondQueue, queue *resultQueue)
{
    size_t firstValue = dequeue(firstQueue);
    size_t secondValue = dequeue(secondQueue);

    while ((firstValue != QUEUE_EMPTY) || (secondValue != QUEUE_EMPTY))
    {   
        if (firstValue == QUEUE_EMPTY)
        {
            enqueue(resultQueue, secondValue);
            secondValue = dequeue(secondQueue);
        }
        else if (secondValue == QUEUE_EMPTY)
        {
            enqueue(resultQueue, firstValue);
            firstValue = dequeue(firstQueue);
        }
        else if(secondValue > firstValue)
        {
            enqueue(resultQueue, firstValue);
            firstValue = dequeue(firstQueue);
        }
        else
        {
            enqueue(resultQueue, secondValue);
            secondValue = dequeue(secondQueue);
        }
    }
}