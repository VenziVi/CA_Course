#include <stdio.h>

char bitAt(int num, int index);
void clearBit(int *num, int index);
void setBit(int *num, int i);
void reverseBit(int *num, int i);
void zeroBit(int *num);

int main()
{
    int n = 15;
    int i = 2;
    int *ptr = &n;

    zeroBit(ptr);

    printf("%d", n);
}

char bitAt(int num, int index)
{
    return (num >> index) & 1;
}

void clearBit(int *num, int index)
{
    int b = ~(1 << index);
    *num = *num & b;
}

void setBit(int *num, int i)
{
    int b = 1 << i;
    *num = *num | b;
}

void reverseBit(int *num, int i)
{
     int b = 1 << i;
    *num = *num ^ b;
}

void zeroBit(int *num)
{
    for (size_t i = 0; i < 8; i+=2)
    {
        clearBit(num, i);
    }
}