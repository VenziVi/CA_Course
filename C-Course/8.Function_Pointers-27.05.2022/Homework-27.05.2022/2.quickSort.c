#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void swap(int *fNum, int *sNum);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void printArray(int arr[], int size);
void setArray(int arr[], int size);

int main()
{
    int arr[SIZE] = {0};

    setArray(arr, SIZE);
    printArray(arr, SIZE);
    quickSort(arr, 0, SIZE - 1);
    printArray(arr, SIZE);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi -1);
        quickSort(arr, pi + 1, high);
    }
    
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
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
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

void setArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}