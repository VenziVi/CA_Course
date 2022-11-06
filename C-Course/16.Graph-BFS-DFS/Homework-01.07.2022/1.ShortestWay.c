

#include <stdio.h>
#include <stdbool.h>

enum direction {UP, DOWN, RIGHT, LEFT};

bool isValid(int rows, int cols, char matrix[rows][cols], int currRow, int currCol);
void matrixTraversal(int rows, int cols, char matrix[rows][cols]);
void DFS(char direction, int rows, int cols, char matrix[rows][cols], int startRow, int startCol, char path[]);

int main()
{
    const int rows = 4;
    const int cols = 6;
    const char matrix[][6] = {"...#.S",
                              ".....#",
                              ".##...",
                              "E...#."};

    matrixTraversal(rows, cols, matrix);
}

void matrixTraversal(int rows, int cols, char matrix[rows][cols])
{
    int startRow = -1;
    int startCol = -1;

    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (matrix[row][col] == 'S')
            {
                startRow = row;
                startCol = col;
            }
        }
    }
    char path[20] = {'0'};
    char direction = 'S';
    DFS(direction, rows, cols, matrix, startRow, startCol, path);
    
}

void DFS(char direction, int rows, int cols, char matrix[rows][cols], int startRow, int startCol, char path[])
{
    static int index = 0;
    int currentRow = startRow;
    int currentCol = startCol;

    if (!isValid(rows, cols, matrix, currentRow, currentCol))
    {
        return;
    }
    
    path[index++] = direction;

    if (matrix[currentRow][currentCol] == 'E')
    {
        for (int i = 1; i < index; i++)
        {
            printf("%c ", path[i]);
        }
        printf("\n");
        
        return;
    }
    
    matrix[currentRow][currentCol] = 'V';

    DFS('D', rows, cols, matrix, currentRow + 1, currentCol, path);
    DFS('L', rows, cols, matrix, currentRow, currentCol - 1, path);
    DFS('R', rows, cols, matrix, currentRow, currentCol + 1, path);
    DFS('U', rows, cols, matrix, currentRow - 1, currentCol, path);

    matrix[currentRow][currentCol] = '.';
    path[--index] = '0';
}

bool isValid(int rows, int cols, char matrix[rows][cols], int currRow, int currCol)
{
    if (currRow < 0 || currRow > rows - 1 || currCol < 0 || currCol > cols - 1) 
    {
       return false;
    }

    if (matrix[currRow][currCol] == '#' || matrix[currRow][currCol] == 'V')
    {
        return false;
    }
    
    return true;
}