// Задача 4* Дом. Напишете програма, която проверява дали дадена матрица е
// identity matrix - матрица с размер (N x N), където само елементите в главния
// диагонал са единици, а всички останали елементи са нули.
//size = 4  1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1
//size = 3  1 0 0 0 1 0 0 0 1
//size = 3  0 1 1 1 0 1 1 1 0 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void setMatrix(int rows, int cols, int matrix[rows][cols]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);
bool isIdentity(int rows, int cols, int matrix[rows][cols]);
int setSize(char *str);

int main()
{
    const int size = setSize("Enter matrix size: ");;

    int matrix[size][size];
    memset(matrix, 0, sizeof matrix); 

    setMatrix(size, size, matrix);
    printMatrix(size, size, matrix);

    (isIdentity(size, size, matrix)) ?
        printf("Matrix is identity.") :
        printf("Matrix is NOT identity.");
}

int setSize(char *str)
{
    int num = 0;

    do
    {
        printf("%s", str);
        scanf("%d", &num);
    } while (num <= 0);

    return num;
}

bool isIdentity(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //checks if the index is in the main diagonal by comparing addresses
            if (j == i)
            {
                if (matrix[i][j] == 0)
                {
                    return false;
                }
            }
            else if (matrix[i][j] == 1)
            {
                return false;
            }
        }
    }

    return true;
}

void setMatrix(int rows, int cols, int matrix[rows][cols])
{
    printf("Enter matrix values: ");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            //matrix[i][j] = rand() % 2;
            scanf("%d", &matrix[i][j]);
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