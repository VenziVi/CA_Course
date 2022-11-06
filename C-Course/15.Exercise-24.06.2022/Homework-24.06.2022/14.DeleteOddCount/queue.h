#ifndef QUEUE
#define QUEUE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_EMPTY SIZE_MAX

typedef struct node
{
    size_t value;
    struct node *next;
} node;

typedef node *nodePtr;

typedef struct
{
    nodePtr head;
    nodePtr tail;
} queue;

bool enqueue(queue *queueNode, size_t value);
size_t dequeue(queue *queueNode);
void display(queue *queueNode);
void deinitQueue(queue *queueNode);
queue *initQueue(void);
void setQueueFromArray(queue *myQueue, size_t arr[], size_t size);
void secondFilter(queue *myQueue, size_t size);
void firstFilter(queue *myQueue, size_t arr[], size_t size);


#endif