#include <stdbool.h>
#include "queue.h"

int main()
{
    struct queue *primeNumbers = QueueInit();
    bool isPrime = true;
    int startNum = 5;
    int endNNum = 30;
    int currNum = 0;

    for (int i = startNum; i <= endNNum; i++)
    {
        currNum = i;

        for (int j = 2; j < currNum / 2; j++)
        {
            if (i % j == 0)
            {   
                isPrime = false;
                break;
            }
        }
        
        if (isPrime)
        {
            enqueue(primeNumbers, i);
        }
        isPrime = true;
    }
    
    disply(primeNumbers);
}