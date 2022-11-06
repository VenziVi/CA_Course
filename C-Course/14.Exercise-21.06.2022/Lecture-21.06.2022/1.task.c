#include <stdio.h>
#include <math.h>

int diagonals( int size, int matrix[size][size])
{
    int firstDiagonal = 0;
    int secondDiagonal = 0;
    int result = 0;

    for (int i = 0; i < size; i++)
    {
        firstDiagonal += matrix[i][i];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            secondDiagonal  += matrix[size - 1 -i][size - i -1];
        }
        
    }

    result = abs(firstDiagonal - secondDiagonal);
    
    return result;
}

int main()
{
    int result = 0;
    int matrix[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    result = diagonals(matrix, 3);

    printf("result = %d \n", result);
}