// 14. Напишете програма, която при дадена редица изтрива всички числа, които
// се срещат нечетен брой пъти. За целта използвайте функция.
// Пример:
// array = {4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2}
// {5, 3, 3, 5}

#include "queue.h"

int main()
{
    const size_t size = 13;
    size_t testArray[] = {4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2, 9, 4};

    queue *firstQueue = initQueue();
    queue *secondQueue = initQueue();

    setQueueFromArray(secondQueue, testArray, size);

    display(secondQueue);

    firstFilter(firstQueue, testArray, size);
    secondFilter(secondQueue, size);

    display(firstQueue);
    display(secondQueue);

    deinitQueue(firstQueue);
    deinitQueue(secondQueue);
    return 0;
}

