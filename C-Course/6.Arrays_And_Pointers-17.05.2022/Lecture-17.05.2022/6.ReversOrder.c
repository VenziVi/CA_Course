// 6. Напишете програма, която приема 10 цели числа от клавиатурата, запазва ги в
// масив и ги принтира в обратен ред.

#include <stdio.h>
#define SIZE 10

int main()
{
    int arr[SIZE] = {0};

    printf("Enter 10 numbers: ");

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", arr + i);
    }

    for (int i = SIZE - 1; i >= 0; i--)
    {
        printf("%d \t", *(arr + i));
    }
    
    return 0;
}