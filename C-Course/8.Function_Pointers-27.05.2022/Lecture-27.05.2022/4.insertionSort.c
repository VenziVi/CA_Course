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

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int prev = i - 1;

        while (prev >= 0 && arr[prev] > curr)
        {
            arr[prev + 1] = arr[prev];
            prev = prev - 1;
        }     
        arr[prev + 1] = curr;
    }
    
}

int main()
{
    int n = 10;
    int *arr;
    arr = (int*)malloc(sizeof(int) * n);

    readArr(arr, n);
    printArr(arr, n);

    insertionSort(arr, n);
    printArr(arr, n);
}