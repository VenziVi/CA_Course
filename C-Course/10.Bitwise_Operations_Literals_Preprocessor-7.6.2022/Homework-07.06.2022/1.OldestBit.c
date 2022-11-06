//  Намерете позицията на най-старшия бит, който е
// със стойност 1 в дадено число.

#include <stdio.h>

int OldestBitPosition(int num);

int main()
{
    int test[4] = {645, 1874, 25647, 39};
    // 645 --> 0000001010000101 -->  i = 9
    // 1874 --> 0000011101010010 --> i = 10
    // 25647 --> 0110010000101111 --> i = 14
    // 39 --> 0000000000100111 --> i = 5
    int position = 0;

    for (int i = 0; i < 4; i++)
    {
        position = OldestBitPosition(test[i]);
        printf("Number: %d --> %d \n", test[i], position);
    }
    
    return 0;
}

int OldestBitPosition(int num)
{
    int size = sizeof(num) * 8;
    int position = 0;
    
    for (int i = 0; i < size; i++)
    {   
        if ((num >> i) & 1)
        {
            position = i;
        } 
    }

    return position;
}
