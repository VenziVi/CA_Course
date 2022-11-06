// 9. Напишете програма, която намира максималния и минималния
// елементи в масив, използвайки указатели.

#include <stdio.h>
#define SIZE 10

int findMin(int *arr, int size);
int findMax(int *arr, int size);

int main()
{
    int arr[SIZE] = {0};
    int min = 0;
    int max = 0;

    printf("Enter %d numbers: ", SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", arr + i);
    }

    min = findMin(arr, SIZE);
    max = findMax(arr, SIZE);

    printf("Min value = %d, Max value = %d", min, max);
    return 0;
}

int findMin(int *arr, int size)
{
    int min = *arr;

    for (int i = 0; i < size; i++)
    {
        if (min > *(arr + i))
        {
            min = *(arr + i);
        }
    }

    return min;
}

int findMax(int *arr, int size)
{
    int max = *arr;

    for (int i = 0; i < size; i++)
    {
        if (max < *(arr + i))
        {
            max = *(arr + i);
        }
    }
    
    return max;
}