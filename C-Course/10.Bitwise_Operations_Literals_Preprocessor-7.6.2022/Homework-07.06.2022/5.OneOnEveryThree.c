// Вдигнете всички битове на 32 битово число,
// на позиции делящи се на 3.

#include <stdio.h>

void changeToOne(int *num);
void setBit(int *num, int index);

int main()
{
    int number = 1;  // --> 001001001001001001001001001001001(1227133513)
    int *num_ptr = &number; 

    changeToOne(num_ptr);

    printf("%d", number);
    return 0;
}

void changeToOne(int *num)
{
    int end = sizeof(*num) * 8;

    for (int i = 0; i < end; i+=3)
    {   
        setBit(num, i);
    }
}

void setBit(int *num, int index)
{
    unsigned int mask = 1 << index;
    *num = *num | mask;
}