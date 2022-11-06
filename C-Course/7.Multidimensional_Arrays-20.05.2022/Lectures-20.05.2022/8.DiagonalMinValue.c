#include <stdio.h>
#include <stdlib.h>

int main()
{
    int const size = 5;
    int matrix[size][size];
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = rand() % 59;
        }
    }

    int min = matrix[0][0];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d \t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < size; i++)
    {
        if (min > matrix[i][i])
        {
            min = matrix[i][i];
        }
    }

    printf("Min = %d", min);
}