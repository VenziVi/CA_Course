// 5. Напишете програма за търсене на определен елемент в даден масив,
// използвайки указатели. Дали дадено число се среща в елементите на
// масива.

#include <stdio.h>
#include <stdbool.h>
#define SIZE 9

int main()
{
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
    int num = 0;
    bool isExist = false;

    printf("Enter number: ");
    scanf("%d", &num);

    for (int i = 0; i < SIZE; i++)
    {
        if (num == *(arr + i))
        {
            isExist = true;
            break;
        }
    }
    
    (isExist) ? printf("YES") : printf("NO");
    return 0;
}