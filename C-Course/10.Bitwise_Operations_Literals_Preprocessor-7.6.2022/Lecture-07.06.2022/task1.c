#include <stdio.h>

void LEtoBe(unsigned int *t)
{
    printf("%x \n", (*t >> 24));
}


int main()
{
    unsigned int cell = 0x12345678;
    printf("%X \n", cell);

    LEtoBE(&cell);
    printf("%X \n", cell);
}
