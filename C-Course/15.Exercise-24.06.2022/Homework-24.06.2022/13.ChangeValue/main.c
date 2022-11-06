#include "stack.h"

int main()
{
    stack myStack = NULL;
    stack playStack = NULL;
    size_t elementToChange = 4;
    size_t newValue = 0;
    size_t testArr[] = {55, 44, 3, 43, 54, 76, 12, 87, 34, 32};
    size_t testSize = sizeof(testArr) / sizeof(size_t);

    for (size_t i = 0; i < testSize; i++)
    {
        push(&myStack, testArr[i]);
        push(&playStack, testArr[i]);
    }

    printStack(&myStack);

    changeElementValue(&myStack, elementToChange, newValue);
    printf("myStack: ");
    printStack(&myStack);

    changeValueWithArray(&playStack, elementToChange, newValue);
    printf("playStack: ");
    printStack(&playStack);

    deinitStack(&myStack);
    deinitStack(&playStack);

    return 0;
}