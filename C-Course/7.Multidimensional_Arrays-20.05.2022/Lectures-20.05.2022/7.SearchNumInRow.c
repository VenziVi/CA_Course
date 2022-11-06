// Задача 5*. Напишете програма, която търси дадено число в сортирана по редове
// матрица. Генерирайте елементите на матрицата с rand(). Принтирайте матрицата и
// въведете от клавиатурата търсеното число. Покажете позицията му.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void setMatrix(int rows, int cols, int matrix[rows][cols]);
void sortArray(int arr[], int size);
void swap(int *fValue, int *sValue);
void printMatrix(int rows, int cols, int matrix[rows][cols]);


int main()
{
    int const rows = 3;
    int const cols = 4;
    int matrix[rows][cols];

    setMatrix(3, 4, matrix);
    
    for (int i = 0; i < 3; i++)
    {
        int *pRow = matrix[i];
        sortArray(pRow, cols);
    }
    
    printMatrix(rows, cols, matrix);

    int num = 0;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (matrix[i][j] == num)
            {
                printf("[%d][%d] \n", i, j);
            }  
        }
    }
}

void setMatrix(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 59;
        }
    }
}

void swap(int *fValue, int *sValue)
{
    int temp = *fValue;
    *fValue = *sValue;
    *sValue = temp;
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
                swap(&arr[i], &arr[i + 1]);
            }
        }

        numbersLeft--;
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d \t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}