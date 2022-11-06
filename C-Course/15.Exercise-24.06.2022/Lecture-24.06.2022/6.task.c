#include "stack.h"

void swap(int *fNum, int *sNum);
void sortDesc(int arr[], int size);
void printArray(int arr[], int size);
void setStack(stack *myStack, int arr[], int size);

int main()
{
    const int size = 10;
    int arr[] = {42, 468, 335, 501, 170, 725, 479, 359, 963, 465};

    stack myStack = NULL;
    sortDesc(arr, size);

    setStack(&myStack, arr, size);
    printf("\n");
    display(&myStack);

    return 0;
}

void setStack(stack *myStack, int arr[], int size)
{
    int middle = size / 2;

    for (int i = size - 1; i >= middle; i--)
    {
        push(myStack, arr[i]);
    }

    for (int i = 0; i < middle; i++)
    {
        push(myStack, arr[i]);
    }
}

void sortDesc(int arr[], int size)
{
    int numbersLeft = size;

    for (int j = 0; j < size; j++)
    {
        for (int i = 0 ; i < numbersLeft - 1; i++)
        {
            if (*(arr + i) < *(arr + i + 1))
            {
                swap(arr + i, arr + i + 1);
            }
        }

        numbersLeft--;
    }
}

void swap(int *fNum, int *sNum)
{
    int temp = *fNum;
    *fNum = *sNum;
    *sNum = temp;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}