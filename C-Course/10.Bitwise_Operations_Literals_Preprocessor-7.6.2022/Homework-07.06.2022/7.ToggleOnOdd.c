// Обърнете битовете на число, които се намират на
// нечетна позиция.

#include <stdio.h>

void toggleOnOdd(int *num);
void toggleBit(int *num, int index);

int main()
{
    int number = 45865;   //1011001100101001  --> 0001100110000011 (6531)
    int *num_ptr = &number; 

    toggleOnOdd(num_ptr);

    printf("%d", number);
    return 0;
}

void toggleOnOdd(int *num)
{
    int size = 16;
    
    for (int i = 1; i < size; i+=2)
    {   
        toggleBit(num, i);
    }
}

void toggleBit(int *num, int index)
{
    unsigned int mask = 1 << index;
    *num = *num ^ mask;
}