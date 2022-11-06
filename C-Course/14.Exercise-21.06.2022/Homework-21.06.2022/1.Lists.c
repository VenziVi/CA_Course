// 1. - (преговор списъци) Да се състави програма, чрез която се въвеждат N броя
// естествени числа от интервала [1..101].
// Броят на въведените числа не се знае предварително - определя се от
// потребителя.
// Чрез използване на структура от тип опашка да се изведе въведената редица
// естествени числа като:
// а) първо се извеждат всички нечетни числа;
// б) след тях се извеждат всички четни числа;
// в) извеждането на числата съответства на реда на въвеждането им.
// Пример: 11, 12, 15, 17, 19, 21, 23, 9, 10, 16, 18, 20
// Изход: 11, 15, 17, 19, 21, 23, 9, 12, 10, 16, 18, 20

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_EMPTY INT_MIN

struct node
{
    int value;
    struct node *next;
};

typedef struct q_node
{
    int value;
    struct q_node *n_ptr;
} q_node;

typedef struct queueNode
{
    q_node *head;
    q_node *tail;
} queueStruc;

typedef struct node l_node;

int setSize(void);
bool insertInList(l_node **lastNode, int value);
void printList(l_node *lastNode);
bool enqueue(queueStruc *myQueue, int value);
void setQueue(queueStruc *myQueue, l_node *listNode);
int dequeue(queueStruc *myQueue);
void printQueue(queueStruc *myQueue);
void init_queue(queueStruc *queueNode);
void deinitList(l_node *startNode);

int main()
{
    l_node *list = NULL;
    queueStruc myQueue;
    init_queue(&myQueue);

    int size = setSize();

    for (int i = 0; i < size; i++)
    {
        insertInList(&list, i + 1);
    }
    
    printList(list);

    setQueue(&myQueue, list);

    printQueue(&myQueue);

    deinitList(list);

    return 0;
}

void setQueue(queueStruc *myQueue, l_node *listHead)
{
    l_node *tempNode = listHead;
    int data = 0;

    while (tempNode != NULL)
    {
        data = tempNode->value;
        if (data % 2 != 0)
        {
            enqueue(myQueue, data);
        }
        tempNode = tempNode->next;
    }

    tempNode = listHead;
    while (tempNode != NULL)
    {
        data = tempNode->value;
        if (data % 2 == 0)
        {
            enqueue(myQueue, data);
        }
        tempNode = tempNode->next;
    }
    
}

bool enqueue(queueStruc *myQueue, int value)
{
    q_node *newNode = malloc(sizeof(q_node));

    if (newNode == NULL)
    {
        return false;
    }

    newNode->value = value;
    newNode->n_ptr = NULL;

    if (myQueue->tail != NULL)
    {
        myQueue->tail->n_ptr = newNode;
    }
    
    myQueue->tail = newNode;

    if (myQueue->head == NULL)
    {
        myQueue->head = newNode;
    }
    
    return true;
}

bool insertInList(l_node **head, int value)
{
    l_node *newNode = malloc(sizeof(l_node));
    l_node *lastNode = *head;

    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return true;
    }
    
    while (lastNode->next != NULL)
    {
        lastNode = lastNode->next;
    }
    
    lastNode->next = newNode;

    return true;
}

int setSize(void)
{
    int size = 0;
    
    printf("Enter array size: ");
    scanf("%d", &size);

    return size;
}

void printList(l_node *head)
{
    l_node *tempNode = head;

    printf("Linked list: ");
    while (tempNode != NULL)
    {
        printf("%d ", tempNode->value);
        tempNode = tempNode->next;
    }
    printf("\n");
    
}

int dequeue(queueStruc *myQueue)
{
    q_node *tempNode = NULL;
    int result = 0;

    if (myQueue->head == NULL)
    {
        return QUEUE_EMPTY;
    }

    tempNode = myQueue->head;
    result = tempNode->value;

    myQueue->head = myQueue->head->n_ptr;

    if (myQueue->head == NULL)
    {
        myQueue->tail = NULL;
    }
    
    free(tempNode);
    return result;
}

void printQueue(queueStruc *myQueue)
{
    int dequeueValue = 0;

    printf("\n");
    while((dequeueValue = dequeue(myQueue)) != QUEUE_EMPTY)
    {
        printf("%d ", dequeueValue);
    }

    printf("\n");
}

void init_queue(queueStruc *queueNode)
{
    queueNode->head = NULL;
    queueNode->tail = NULL;
}

void deinitList(l_node *startNode)
{
    l_node *ptr = startNode;
    l_node *next_ptr = NULL;

    while (ptr != NULL)
    {
        next_ptr = ptr->next;
        free(ptr);
        ptr = next_ptr;
    }
}