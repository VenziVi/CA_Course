#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);
void printArray(int arr[], int size);
void setArray(int arr[], int size);


int main()
{
    int arr[SIZE] = {0};

    setArray(arr, SIZE);
    printArray(arr, SIZE);
    mergeSort(arr, 0, SIZE - 1);
    printArray(arr, SIZE);
}

void mergeSort(int arr[], int low, int high)
{   
    int mid = 0;

    if (low < high)
    {
        mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int size1 = mid - low + 1;
    int size2 = high - mid;

    int arr1[size1];
    int arr2[size2];

    for (i = 0; i < size1; i++)
    {
        arr1[i] = arr[low + i];
    }

    for (j = 0; j < size2; j++)
    {
        arr2[j] = arr[mid + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = low;

    while (i < size1 && j < size2)
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] =arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }

        k++;
    }

    while (i < size1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    
    while (j < size2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
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