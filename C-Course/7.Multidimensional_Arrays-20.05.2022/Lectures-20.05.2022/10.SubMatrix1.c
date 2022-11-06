// Задача 7*.( да се помисли-решението следващо занятие) Напишете програма, която намира
// под-матрица с максимален размер в дадена бинарна матрица, съставена само от нули и
// единици. Пример:
// The given array in matrix form is :
// 0 1 0 1 1
// 1 1 1 1 0
// 1 1 1 1 0
// 1 1 1 1 0
// 1 1 1 1 1
// 0 1 0 1 0
// The maximum size sub-matrix is:
// 1 1 1 1
// 1 1 1 1
// 1 1 1 1
// 1 1 1 1

#include<stdio.h>

void printMatrix(int rows, int cols, int matrix[rows][cols]);
void printSubmatrix(int rows, int cols, int matrix[rows][cols]);
int min(int a, int b, int c);

int main()
{
    int matrix[6][5] = {{0, 1, 0, 1, 1},
                        {1, 1, 1, 1, 0},
                        {1, 1, 1, 1, 0},
                        {1, 1, 1, 1, 0},
                        {1, 1, 1, 1, 1},
                        {0, 1, 0, 1, 0}};

    // int matrix[6][5] = {{0, 1, 0, 1, 1},
    //                     {1, 1, 0, 1, 0},
    //                     {1, 1, 1, 1, 0},
    //                     {1, 1, 1, 0, 0},
    //                     {1, 1, 1, 1, 1},
    //                     {0, 1, 1, 1, 0}};

    printSubmatrix(6, 5, matrix);    
}

void printSubmatrix(int rows, int cols, int matrix[rows][cols])
{
    int subMatrix[6][5] = {{0}};
    int iMax = 0;
    int jMax = 0;
    int subMax = subMatrix[0][0];

    for (int i = 0; i < 6; i++)
    {
        subMatrix[i][0] = matrix[i][0];
    }

    for (int j = 0; j < 5; j++)
    {
        subMatrix[0][j] = matrix[0][j];
    }

    printMatrix(6, 5, subMatrix);
    
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            if (matrix[i][j] == 1)
            {
                subMatrix[i][j] = min(subMatrix[i][j - 1], 
                subMatrix[i - 1][j], subMatrix[i - 1][j - 1]) + 1;
            }
            else
            {
                subMatrix[i][j] = 0;
            }
        }
    }

    printMatrix(6, 5, subMatrix);

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (subMax < subMatrix[i][j])
            {
                subMax = subMatrix[i][j];
                iMax = i;
                jMax = j;
            }
        }
    }

    printf("Max row = %d \n", iMax);
    printf("Max col = %d \n", jMax);
    printf("\n");

    for (int i = iMax; i > iMax - subMax; i--)
    {
        for (int j = jMax; j > jMax - subMax; j--)
        {
            printf("%d \t", matrix[i][j]);
        }
        printf("\n");
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

int min(int a, int b, int c)
{
    int m = a;
    if (m > b)
        m = b;
    if (m > c)
        m = c;
    return m;
}