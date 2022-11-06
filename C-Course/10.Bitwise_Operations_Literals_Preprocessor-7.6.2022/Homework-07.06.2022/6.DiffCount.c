// Намерете броя на позициите на битовете, в които две
// числа се различават.

#include <stdio.h>

int differenceCount(int numA, int numB);

int main()
{
    int numA = 2586; // 0000101000011010
    int numB = 1632; // 0000011001100000

    int result = differenceCount(numA, numB);

    printf("%d", result);
    return 0;
}

int differenceCount(int numA, int numB)
{
    int diff = numA ^ numB;
    int count = 0;
    // diff = 3194 / 110001111010
    while (diff)
    {
        diff = diff & (diff - 1);
        count++;

        // 110001111010  --> 3194
        //&
        // 110001111001  --> 3194 - 1

        // 110001111000  --> 3192
        //& 
        // 110001110111  --> 3192 - 1

        // 110001100000  --> 3168
        //&
        // 110001011111  --> 3168 - 1

        // 110001000000
        // 110000000000
        // 100000000000
    }
    
    return count;
}