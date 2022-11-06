// Задача 3. Напишете програма, която проверява дали две дадени матрици са
// еднакви, сравнявайки съответните елементи в тях. Разпечатайте в конзолата
// двете изходни матрици и резултата от сравнението.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void setMatrix(int size, int matrix[size][size]);
void printMatrix(int size, int matrix[size][size]);

int main()
{
    int const size = 3;
    int matrixA[size][size];
    int matrixB[size][size];
    bool areEqual = true;

    setMatrix(size, matrixA);
    setMatrix(size, matrixB);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrixA[i][j] != matrixB[i][j])
            {
                areEqual = false;
            }
        }
    }
    
    printMatrix(size, matrixA);
    printMatrix(size, matrixB);

    (areEqual) ? 
        printf("YES") : 
        printf("NO");
}

void setMatrix(int size, int matrix[size][size])
{
    printf("Enter matrix values: ");

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            //matrix[i][j] = rand() % 100;
            scanf("%d", &matrix[i][j]);
        }      
    }
}

void printMatrix(int size, int matrix[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d \t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}