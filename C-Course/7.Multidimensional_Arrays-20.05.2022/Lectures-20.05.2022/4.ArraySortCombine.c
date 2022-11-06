// 1. Напишете програма, която да обедини два масива от цели числа,
// като ги сортира в низходящ ред и ги принтира.

#include <stdio.h>
#include <stdlib.h>

void sortArray(int arr[], int size);
void swap(int *fValue, int *sValue);
void printArray(int arr[], int arrSize);


int main()
{
    int a[5] = {3, 6, 0, 5, 9};
    int b[7] = {1, 8, 9, 4, 6, 2, 7};
    int step = 1;
    
    sortArray(a, 5);
    sortArray(b, 7);

    printArray(a, 5);
    printArray(b, 7);

    int *c = malloc(12 * sizeof(int));
    

    printArray(c, 12);
    
}

void sortArray(int arr[], int size)
{
    int numbersLeft = size;

    for (int j = 0; j < size; j++)
    {
        for (int i = 0 ; i < numbersLeft - 1; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }

        numbersLeft--;
    }
}

void swap(int *fValue, int *sValue)
{
    int temp = *fValue;
    *fValue = *sValue;
    *sValue = temp;
}

void printArray(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}