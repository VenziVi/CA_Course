// Задача 1. Декларирайте двумерен масив с по 5 елемента (5 x 5). След като сте
// готови, направете въвеждане на данните в масива, като четете от потребителя
// със scanf. Отпечатайте масива в конзолата, спазвайки броя редове и колони.

#include <stdio.h>
#include <stdlib.h>

void setMatrix(int size, int matrix[size][size]);
void printMatrix(int size, int matrix[size][size]);

int main()
{
    int const size = 5;
    int matrix[size][size];

    setMatrix(size, matrix);
    printMatrix(size, matrix);
}

void setMatrix(int size, int matrix[size][size])
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = rand() % 100;
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
}