#include "queue.h"

void enqueue(struct queue *myQueue, int data)
{
    struct node *temp;
    temp = malloc(sizeof(struct node));

    temp->data = data;
    temp->next = NULL;

    if (myQueue->front == NULL && myQueue->rear == NULL)
    {
        myQueue->front = myQueue->rear = temp;
        return;
    }
    
    myQueue->rear->next = temp;
    myQueue->rear = temp;
}

int dequeue(struct queue *myQueue)
{
    struct node *temp = myQueue->front;
    int result = 0;

    if (myQueue->front == NULL)
    {
        return 0;
    }
    
    result = myQueue->front->data;

    if (myQueue->front == myQueue->rear)
    {
        myQueue->front = myQueue->rear = NULL;
    }
    else
    {
        myQueue->front = myQueue->front->next;
    }

    free(temp);

    return result;
}

void disply(struct queue *myQueue)
{
    struct node *temp = myQueue->front;

    while (temp)
    {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}

struct queue *QueueInit()
{
    struct queue *thisQueue = malloc(sizeof(struct queue));

    thisQueue->front = NULL;
    thisQueue->rear = NULL;

    return thisQueue;
}