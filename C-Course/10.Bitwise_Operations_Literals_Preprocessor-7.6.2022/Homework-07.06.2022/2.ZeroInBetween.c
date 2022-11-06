// Направете на нула битовете в числа, намиращи се на
// позиции между 3 и 7.

#include <stdio.h>

void changeBits(int *num, int start, int end);
void turnToZero(int *num, int index);

int main()
{
    int number = 150;  // 10010110 --> 00000110(6)
    //int number = 120; //01111000 --> 00000000(0)
    int startPosition = 3;
    int endPosition = 7;

    int *ptr_num = &number;

    changeBits(ptr_num, startPosition, endPosition);

    printf("%d", number);
    return 0;
}

void changeBits(int *num, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        turnToZero(num, i);
    }
}

void turnToZero(int *num, int index)
{
    unsigned int mask = ~(1 << index);
    *num = *num & mask;
}