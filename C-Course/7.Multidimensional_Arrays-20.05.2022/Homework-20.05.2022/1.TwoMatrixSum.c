// Задача 2. Дом Напишете програма, която събира две матрици (4х4) и записва
// резултата в трета такава със същия размер. Събирането на матриците става като
// намерим сумата на съответстващите елементи в тях. Данните за изходните матрици
// трябва да бъдат въведени от потребителя. Разпечатайте трите матрици в конзолата.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void setMatrix(int rows, int cols, int matrix[rows][cols]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);

int main()
{
    const int rows = 4;
    const int cols = 4;

    int matrixA[rows][cols];
    int matrixB[rows][cols];
    int matrixC[rows][cols];

    memset(matrixA, 0, sizeof matrixA);
    memset(matrixB, 0, sizeof matrixB);
    memset(matrixC, 0, sizeof matrixC);

    printMatrix(rows, cols, matrixA);
    printMatrix(rows, cols, matrixB);
    printMatrix(rows, cols, matrixC);


    setMatrix(rows, cols, matrixA);
    setMatrix(rows, cols, matrixB);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
    
    printMatrix(rows, cols, matrixA);
    printMatrix(rows, cols, matrixB);
    printMatrix(rows, cols, matrixC);
}

void setMatrix(int rows, int cols, int matrix[rows][cols])
{
    //printf("Enter matrix values: ");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 100;
            //scanf("%d", &matrix[i][j]);
        }
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