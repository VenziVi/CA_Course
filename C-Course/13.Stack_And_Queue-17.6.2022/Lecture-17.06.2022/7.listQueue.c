#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};

typedef struct queue node;

node *front = NULL;
node *rear = NULL;

node * createNode(int data)
{
    node *temp = malloc(sizeof(node));

    if (temp == NULL)
    {
        printf("NULL");
        return;
    }
    
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void enqueue(int data)
{
    node *newNode = createNode(data);

    if (newNode == NULL)
    {
        printf("Full");
        return;
    }
    
    if (front == rear)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Data inserted \n");
}

void dequeue()
{
    node *temp;
    if (front == NULL)
    {
        printf("empty Queue!");
        return;
    }

    temp = front;
    front = front->next;
    printf("Deleted %d \n", temp->data);
    free(temp);
}