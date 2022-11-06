// 3. Напишете функция, която връща двумерен масив, запълнен по
// следния начин:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void setMatrix(int size, int matrix[][size]);
void printMatrix(int size, int matrix[][size]);

int main()
{
	const int rows = 5;
	int matrix[rows][rows];
	memset(matrix, 0, sizeof matrix); 

	setMatrix(rows, matrix);
	printMatrix(rows, matrix);
}

void setMatrix(int size, int matrix[][size])
{
	int num = 0;
	int rowsCounter = 2;

	for (int col = 0; col < size; col++)
	{    
		for (int row = 1 + col; row < size; row++)
		{
			matrix[row][col] = ++num;
		}
	}

	for (int col = size - 1; col > 0; col--)
	{
		for (int row = size - rowsCounter; row >= 0; row--)
		{
			matrix[row][col] = ++num;
		}
		rowsCounter++;
	}
}

void printMatrix(int size, int matrix[][size])
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			printf("%3d ", matrix[i][j]);
		}
		printf("\n");
	}
}