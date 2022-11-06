#include <stdio.h>
#define N 5

void tabul(float (*f)(float), float x[], float y[], int count, float step)
{
    for (int i = 0; i < count; i++)
    {
        x[i] = i * step;
        y[i] = (*f)(x[i]);
    }
}

float f1(float x)
{
    return (x * x + 2);
}

float f2(float x)
{
    return (x * x - 1);
}

int main()
{
    float x[N] = {0}, y[N] = {0};

    tabul(f1, x, y, N, 2);

    for (int i = 0; i < N; i++)
    {
        printf("x[%d] = %f, y[%d] = %f \n", i, x[i], i, y[i]);
    }

    printf("\n");

    tabul(f2, x, y, N, 3);

    for (int i = 0; i < N; i++)
    {
        printf("x[%d] = %f, y[%d] = %f \n", i, x[i], i, y[i]);
    }
}