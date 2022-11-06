#include <stdio.h>

typedef int arr[5];

int main()
{
    arr myArr = {4, 9, 6, 2, 3};

    for (int i = 0; i < 5; i++)
    {
        printf("%d \t", myArr[i]);
    }

    printf("\n");

    arr myArr2 = {7, 1, 0, 2, 3};

    for (int i = 0; i < 5; i++)
    {
        printf("%d \t", myArr2[i]);
    }
    
}