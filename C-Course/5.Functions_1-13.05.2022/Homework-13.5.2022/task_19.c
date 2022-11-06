// 19. Да се напише рекурсивна функция
// int numPrint(int n),
// С помощта на която се отпечатват всички естествени числа до 100.

#include <stdio.h>

void numPrint(int number);

int main()
{
    int num = 100;
    numPrint(num);
}

void numPrint(int num)
{
    if (num == 1)
    {
         printf("1 \n");
         return;
    }

    numPrint(num - 1);
    printf("%d \n", num);
}