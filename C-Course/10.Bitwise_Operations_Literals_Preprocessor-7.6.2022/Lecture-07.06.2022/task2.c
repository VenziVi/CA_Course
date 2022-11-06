#include <stdio.h>

#define MAX(a, b) (a > b) ? a : b

int main()
{
    int a = 6;
    int b = 12;
    printf("%d", MAX(a, b));
}