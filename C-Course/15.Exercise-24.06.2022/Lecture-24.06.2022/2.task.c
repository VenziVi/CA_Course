#include "queue.h"

int main()
{
    struct queue *myQueue = QueueInit();

    enqueue(myQueue, 5);
    enqueue(myQueue, 15);
    enqueue(myQueue, 35);

    dequeue(myQueue);

    display(myQueue);
}