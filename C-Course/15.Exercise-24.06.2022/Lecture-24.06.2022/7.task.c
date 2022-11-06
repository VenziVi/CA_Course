#include "queue.h"

void setResultQueue(struct queue *resultQueue, int start, int size)
{
    int value = start;
    struct queue *numsQueue = QueueInit();
    enqueue(numsQueue, value);

    for (int i = 0; i < size; i++)
    {
        value = dequeue(numsQueue);

        enqueue(numsQueue, (value + 1));
        enqueue(numsQueue, (value * 2 + 1));
        enqueue(numsQueue, (value + 2));

        enqueue(resultQueue, value);
    }
    
}

int main()
{
    struct queue *resultQueue = QueueInit();

    int start = 2;
    int size = 50;

    setResultQueue(resultQueue, start, size);
    
    disply(resultQueue);
}