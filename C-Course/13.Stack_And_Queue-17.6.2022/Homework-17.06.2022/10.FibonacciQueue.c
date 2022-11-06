// Като използвате опашка, отпечатайте първите n числа на
// Фибоначи.
// Напомняне F_0=1, F_1=1, F_2=F_0+F_1=2
// или всяка следващо е сбора на предишните две числа

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct
{
    node *head;
    node *tail;
} queue;

void init_queue(queue *queueNode);
bool enqueue(queue *queueNode, int value);
int dequeue(queue *queueNode);
void fibonacciNumbersEnqueue(queue *queueNode, int end);
int getValue(void);
void printQueue(queue *queueNode);

int main()
{
    int endNum = getValue();
    queue myQueue;
    init_queue(&myQueue);
 
    fibonacciNumbersEnqueue(&myQueue, endNum);

    printQueue(&myQueue);

    return 0;
}

void fibonacciNumbersEnqueue(queue *queueNode, int end)
{
    int first = 1;
    int second = 1;
    int next = 0;

    enqueue(queueNode, next);

    if (end >= 1)
    {
        enqueue(queueNode, first);
    }

    if (end >= 2)
    {
        enqueue(queueNode, second);
    }
    
    
    for (int i = 3; i <= end; i++)
    {
        next = first + second;
        first = second;
        second = next;
        enqueue(queueNode, next);
    }
}

bool enqueue(queue *queueNode, int value)
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

int dequeue(queue *queueNode)
{
    node *tempNode = NULL;
    int result = 0;

    if (queueNode->head == NULL)
    {
        return QUEUE_EMPTY;
    }

    tempNode = queueNode->head;
    result = tempNode->value;

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
    int dequeueValue = 0;

    printf("Fibonacci sequence: ");
    while((dequeueValue = dequeue(queueNode)) != QUEUE_EMPTY)
    {
        printf("%d \t", dequeueValue);
    }
}

int getValue(void)
{
    int value = 0;

    printf("Enter value: ");
    scanf("%d", &value);

    return value;
}