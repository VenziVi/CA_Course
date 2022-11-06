#include <stdio.h>

int findMin(int *arr, int start, int end)
{
    int min = arr[start];

    for (int i = start; i < end; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    
    return min;
}


int main()
{
    int arr[10] = {2, 4, 3, 8, 5, 6, 1, 8, 9, 4};
    int a = 3;

    int min = 0;

    int start = 0;
    int end = a;
    for (int i = 0; i < 10; i++)
    {

        min = findMin(arr, start, end);
        start = end;
        end += 3;
        if (end > 9)
        {
            end = 9;
        }

        printf("%d \n", min);
        
    }
    
}

