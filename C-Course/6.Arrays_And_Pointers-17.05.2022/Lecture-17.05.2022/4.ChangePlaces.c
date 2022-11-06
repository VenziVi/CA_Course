// 4. Напишете програма, която обръща местата на елементите в един масив,
// използвайки указатели.

#include <stdio.h>
#define SIZE 8

int main()
{
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
    
    for (int i = 0; i < SIZE / 2; i++)
    {
        int temp = *(arr + i);
        *(arr + i) = *(arr + SIZE - 1 - i);
        *(arr + SIZE - 1 - i) = temp;
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d \t", *(arr + i));
    }
    
    return 0;
}
