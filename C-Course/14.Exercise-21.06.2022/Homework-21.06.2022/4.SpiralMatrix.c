// 4. Напишете функция, която по зададено n връща двумерен масив n x n,
// елементите на който са подредени като спирала:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int setSize(void);
int **createSpiralMatrix(int size);
void setWithZero(int size, int **matrix);
void printMatrix(int size, int **matrix);
void fillSpiralMatrix(int size, int **matrix);
void deinitMatrix(int size, int **matrix);

int main()
{
    int size = setSize();
    int **matrix = createSpiralMatrix(size);

    setWithZero(size, matrix);
    printMatrix(size, matrix);

    fillSpiralMatrix(size, matrix);

    printMatrix(size, matrix);

    deinitMatrix(size, matrix);
    
    return 0;
}

void fillSpiralMatrix(int size, int **matrix)
{
    int startRow = 0;
    int startCol = 0;
    int endRow = size  - 1;
    int endCol = size - 1;
    int nextNum = 1;
    int maxIterations = size * size;

    while (nextNum <= maxIterations)
    {
        for (int j = startRow; j <= endRow; j++)
        {
            matrix[j][startCol] = nextNum++;
        }

        for (int i = startCol + 1; i <= endCol; i++)
        {
            matrix[endRow][i] = nextNum++;
        }

        for (int j = endRow - 1; j >= startRow; j--)
        {
            matrix[j][endCol] = nextNum++;
        }

        for (int i = endCol - 1; i >= startCol + 1; i--)
        {
            matrix[startRow][i] = nextNum++;
        }

        startRow++;
        endRow--;
        startCol++;
        endCol--;
    }
}

int **createSpiralMatrix(int size)
{
    int **matrix = (int**)malloc(sizeof(int*) * size);

    for (int i = 0; i < size; i++)
    {
        matrix[i] = (int*)malloc(sizeof(int) * size);
    }

    return matrix;
}

int setSize(void)
{
    int size = 0;
    
    printf("Enter array size: ");
    scanf("%d", &size);

    return size;
}

void setWithZero(int size, int **matrix)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = 0;
        }
    }

}

void printMatrix(int size, int **matrix)
{
    printf("\n");
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%3d ", matrix[i][j]);
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