//  Премахнете всички битове на число след n-тия
// бит включително.

#include <stdio.h>

void clearBits(int *num, int position);
void turnToZero(int *num, int index);

int main()
{
    //int number = 125999; // 11110110000101111 --> 00101111(47)
    int number = 4586576; // 10001011111110001010000 --> 01010000(80)
    int position = 8;

    int *ptr_num = &number;

    clearBits(ptr_num, position);

    printf("%d", number);
    return 0;
}

void clearBits(int *num, int position)
{
    int end = sizeof(*num) * 8;
    for (int i = position - 1; i < end; i++)
    {
        turnToZero(num, i);
    }
}

void turnToZero(int *num, int index)
{
    unsigned int mask = ~(1 << index);
    *num = *num & mask;
}