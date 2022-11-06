#include <stdio.h>

typedef int (*calc)(int a, int b);

int plus(int nA, int nB)
{
    return  (nA + nB);
}

int minus(int nA, int nB)
{
    return  (nA - nB);
}

int multi(int nA, int nB)
{
    return  (nA * nB);
}

int div(int nA, int nB)
{
    return  (nA / nB);
}

int main()
{
    calc func = multi;
    int a = 35;
    int b = 5;

    printf("%d", func(a, b));
}