// 1. Напишете програма, която въвежда и принтира елементитe на масив,
// използвайки указател.

#include <stdio.h>

int main()
{
    int arr[10] = {0};

    printf("Enter 10 numbers: ");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", arr + i);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d \t", *(arr + i));
    }
}