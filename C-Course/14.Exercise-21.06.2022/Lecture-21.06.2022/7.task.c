#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getBinary(int num)
{
    int count = 0;
    while (num > 0)
    {
        if (num % 2 == 1)
        {
            count++;
        }
        num /= 2;
    }
    return count;
}

int *oneCount(int *arr, int size)
{
    int *countOne = malloc(sizeof(int) * size);
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        count = getBinary(arr[i]);

        countOne[i] = count;
    }
    
    return countOne;
}

void swap(int *fNum, int *sNum)
{
    int temp = *fNum;
    *fNum = *sNum;
    *sNum = temp;
}

void sort(int *arr, int *arr2, int size)
{
    int numbersLeft = size;

    for (int j = 0; j < size; j++)
    {
        for (int i = 0 ; i < numbersLeft - 1; i++)
        {
            if (*(arr + i) > *(arr + i + 1))
            {
                swap(arr + i, arr + i + 1);
                swap(arr2 + i, arr2 + i + 1);
            }
        }

        numbersLeft--;
    }
}


int main()
{
    int arr[10] = {5, 15, 23, 54, 12, 7, 8, 54, 34, 21};

    int *arr2 = oneCount(arr, 10);

    sort(arr2, arr, 10);

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", arr2[i]);
    }

    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", arr[i]);
    }

    printf("\n");
}