#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node
{
    int *arr;
    struct node *next;
} node;

typedef struct
{
    node *head;
    node *tail;
} queue;

void init_queue(queue *queueNode);
bool enqueue(queue *queueNode, int *value);
int *dequeue(queue *queueNode);
void printQueue(queue *queueNode);


int main()
{
    queue myQueue;
    init_queue(&myQueue);
    int numArr[3];

    int i, j, k;
    int n = 3;
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if ((i + j + k) == n)
                {
                    continue;
                }
                
                numArr[0] = i;
                numArr[1] = j;
                numArr[2] = k;
                printf("%d, %d, %d \n", i, j, k);
                enqueue(&myQueue, numArr);
            }
            
        }
        
    }

    printQueue(&myQueue);
    return 0;
}


bool enqueue(queue *queueNode, int *value)
{
    node *newNode = malloc(sizeof(node));

    if (newNode == NULL)
    {
        return false;
    }
    
    newNode->arr = value;
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

int *dequeue(queue *queueNode)
{
    node *tempNode = NULL;
    int *result = NULL;

    if (queueNode->head == NULL)
    {
        return NULL;
    }

    tempNode = queueNode->head;
    result = tempNode->arr;

    queueNode->head = queueNode->head->next;

    if (queueNode->head == NULL)
    {
        queueNode->tail = NULL;
    }
    
    free(tempNode);
    return result;
}

void init_queue(queue *queueNode)
{
    queueNode->head = NULL;
    queueNode->tail = NULL;
}


void printQueue(queue *queueNode)
{
    int *dequeueValue = NULL;

    while((dequeueValue = dequeue(queueNode)) != NULL)
    {
        for (int i = 0; i < 3; i++)
        {
            printf("%d \t", dequeueValue[i]);
        }
        
        printf("\n");
    }
}


