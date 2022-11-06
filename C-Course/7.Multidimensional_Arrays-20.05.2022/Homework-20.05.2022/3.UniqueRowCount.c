// Задача 6*. Дом Напишете програма, която печата броя на уникалните редове в бинарна
// матрица, съставена само от единици и нули.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void setMatrix(int rows, int cols, int matrix[rows][cols]);
void printMatrix(int rows, int cols, int matrix[rows][cols]);
bool isRowUnique(int rows, int cols, int matrix[rows][cols], int currRow);
int setSize(char *str);

int main()
{
    const int rows = setSize("Enter matrix rows: ");
    const int cols = setSize("Enter matrix cols: ");

    int * uniqueRows = NULL;
    int uniqueRowsCount = 0;

    int matrix[rows][cols];
    memset(matrix, 0, sizeof matrix); 

    setMatrix(rows, cols, matrix);
    printMatrix(rows, cols, matrix);

    for (int i = 0; i < rows; i++)
    {
        if (isRowUnique(rows, cols, matrix, i))
        {
            uniqueRowsCount++;
            uniqueRows = realloc(uniqueRows, uniqueRowsCount * sizeof(int));
            uniqueRows[uniqueRowsCount - 1] = i;    
        }
    }

    (uniqueRowsCount == 1) ?
        printf("Matrix have %d unique row. \n", uniqueRowsCount) :
        printf("Matrix have %d unique rows. \n", uniqueRowsCount);

    for (int i = 0; i < uniqueRowsCount; i++)
    {
        printf("Row: %d \n", uniqueRows[i] + 1);
    }
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

//function compare every row of matrix with all other rows
bool isRowUnique(int rows, int cols, int matrix[rows][cols], int currRow)
{
    bool areSame = true;

    for (int i = 0; i < rows; i++)
    {
        areSame = true;

        //continues if the function attempts to compare one row with itself
        if (i == currRow)
        {
            continue;
        }
        
        //compare elements on same index of current row with next row[i]
        for (int j = 0; j < cols; j++)
        {
            if (matrix[currRow][j] != matrix[i][j])
            {
                areSame = false;
                break;
            }
        }

        if (areSame)
        {
            //current row is not unique
            return false;
        }
    }
    
    return true;
}

void setMatrix(int rows, int cols, int matrix[rows][cols])
{
    //printf("Enter matrix values: ");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = rand() % 2;
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