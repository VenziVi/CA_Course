// 20. Да се напише функция, която зависи от един двумерен масив и
// броят на неговите редове и колони и транспонира този масив, като
// транспонираният масив се връща кото стойност на функцията.
// Действието транспониране на една матрица, означава първият ред да
// стане първи стълбр вторият ред да стане втори стълб и т.н.
// Или казано с други думи редовете стават колони, а колоните стават
// редове

#include <stdio.h>
#include <stdlib.h>

int** transpositionMatrix(int rows, int cols, int matrix[rows][cols]);
void printMatrix(int rows, int cols, int **matrix);
void deinitMatrix(int size, int **matrix);

int main()
{
    const int rows = 4;
    const int cols = 3;

    int matrix[4][3] = {{1, 1, 1},
                        {2, 2, 2},
                        {3, 3, 3},
                        {4, 4, 4}};


    int **resultMatrix = transpositionMatrix(rows, cols, matrix);

    printMatrix(cols, rows, resultMatrix);

    deinitMatrix(cols, resultMatrix);
    return 0;
}

int** transpositionMatrix(int rows, int cols, int matrix[rows][cols])
{
    int **trMatrix = (int**)malloc(sizeof(int*) * cols);

    for (int i = 0; i < cols; i++)
    {
        trMatrix[i] = (int*)malloc(sizeof(int) * rows);
    }
    
    for (int row = 0; row < cols; row++)
    {
        for (int col = 0; col < rows; col++)
        {
            trMatrix[row][col] = matrix[col][row];
        }
    }
    
    return trMatrix;
}

void printMatrix(int rows, int cols, int **matrix)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            printf("%3d ", matrix[row][col]);
        }
        printf("\n");
    }
}

void deinitMatrix(int size, int **matrix)
{
    for (int i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    
    free(matrix);
}