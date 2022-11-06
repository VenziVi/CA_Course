#include <stdio.h>

#define SWAP(t, x, y) {t c = x; x= y; y = c;}

int main ()
{
    int a = 5;
    int b = 9;
    SWAP(int, a, b);
    printf("%d, %d", a, b);
}