#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *ptrQueue;

struct queue
{
    ptrQueue front;
    ptrQueue rear;
};

struct queue *QueueInit();

void enqueue(struct queue* , int);
int dequeue();
void disply();