#include <stdio.h>
#include <stdlib.h>

void readArr(int **arr, int n, int m);
void printArr(int **arr, int n, int m);

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