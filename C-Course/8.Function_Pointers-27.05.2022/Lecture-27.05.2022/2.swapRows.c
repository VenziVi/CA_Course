#include <stdio.h>
#include <stdlib.h>

void readArr(int **arr, int n, int m);
void printArr(int **arr, int n, int m);
void swap(int *a, int *b, int n);
int maxElement(int *arr, int n);
int maxElMatrix(int **arr, int n, int m);

int main()
{
    int n = 3, m = 4;
    int  **arr;

    arr = (int**)malloc(sizeof(int*) * n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * m);
    }
    
    readArr(arr, n, m);
    printArr(arr, n, m);
    swap(arr[0], arr[1], n);
    printArr(arr, n, m);

    
    for (int i = 0; i < n; i++)
    {
        int max = maxElement(arr[i], m);
        printf("Max in row %d = %d \n", i, max);
    }

    int matMax = maxElMatrix(arr, n, m);
    printf("Max = %d", matMax);
    

    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
        arr[i] = NULL;
    }

    free(arr);
    arr = NULL;
}

void readArr(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 100;
            //scanf("%d", &arr[i][j]);
        }
    }
}

void printArr(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void swap(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

int maxElement(int *arr,int n)
{
    int max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

int maxElMatrix(int **arr, int n, int m)
{
    int max = arr[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}