#include <stdio.h>
#include <stdlib.h>

void readArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

void binarySearch(int arr[], int n, int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == n)
        {
            return mid;
        }
        if (arr[mid] < n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main()
{
    int size = 10;
    int n = 4;
    int *arr;
    arr = (int*)malloc(sizeof(int) * n);

    readArr(arr, n);
    printArr(arr, n);

    binarySearch(arr, n, arr[0], arr[size -1]);
    printArr(arr, n);
}