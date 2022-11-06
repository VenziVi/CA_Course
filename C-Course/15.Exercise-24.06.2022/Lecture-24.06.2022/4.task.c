#include "queue.h"

void enqueueNums(int arr[], int size, struct queue *queue1, struct queue *queue2, struct queue *queue3);

int main()
{
    struct queue *queue1 = QueueInit();
    struct queue *queue2 = QueueInit();
    struct queue *queue3 = QueueInit();
    
    const int size = 17;
    int arr[] = {15, 8, 1, 13, 3, 45, 123, 4, 21, 47, 74, 189, 78, 56, 49, 12, 9};

    enqueueNums(arr, size, queue1, queue2, queue3);
    
    display(queue1);
    display(queue2);
    display(queue3);
}

void enqueueNums(int arr[], int size, struct queue *queue1, struct queue *queue2, struct queue *queue3)
{
    for (int i = 0; i < 17; i++)
    {
        if (arr[i] < 10)
        {
            enqueue(queue1, arr[i]);
        }
        else if(arr[i] <= 50)
        {
            enqueue(queue2, arr[i]);
        }
        else
        {
            enqueue(queue3, arr[i]);
        }
        
    }
}