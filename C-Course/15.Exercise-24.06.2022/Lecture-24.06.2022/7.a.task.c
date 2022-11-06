#include "queue.h"

void findOperationsCount(int start, int end)
{
    int value = end;
    struct queue *numsQueue = QueueInit();
    enqueue(numsQueue, value);

    while (value > start)
    {
        value = dequeue(numsQueue);

        if ((value % 2 == 0) && (value / 2) >= start)
        {
            enqueue(numsQueue, value / 2);
        }
        else if ((value - 2) >= start)
        {
            enqueue(numsQueue, value - 2);
        }
        else
        {
            enqueue(numsQueue, value - 1);
        }
        
        printf("%d ", value);
    }
}

int main()
{
    int start = 5;
    int end = 16;

    findOperationsCount(start, end);
}