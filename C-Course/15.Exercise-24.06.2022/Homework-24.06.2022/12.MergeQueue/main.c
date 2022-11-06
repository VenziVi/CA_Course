// 12. Дадени са двe опашки от числа, подредени в нараства ред от началото
// към края на опашката. Да се напише функция mergeQueues, която чрез
// операциите InsertElem и DeleteElem построява нова опашка, която се състои
// от всички елементи на дадените две опашки, подредени в нарастващ ред от
// началото към края.
// Пример: ако първата опашка съдържа 1, 3, 5, а втората опашка съдържа
// числата 1, 2, 6, получената опашка трябва да съдържа числата 1, 1, 2, 3, 5, 6.

#include "queue.h"

int main()
{
    queue *firstQueue = initQueue();
    queue *secondQueue = initQueue();
    queue *resultQueue = initQueue();

    static size_t size = 5;
    size_t firstArr[] = {1, 3, 5, 6, 8};
    size_t secondArr[] = {1, 2, 6, 7, 9};

    setQueue(firstQueue, firstArr, size);
    setQueue(secondQueue, secondArr, size);

    sortResultQueue(firstQueue, secondQueue, resultQueue);

    display(resultQueue);

    deinitQueue(resultQueue);
    return 0;
}