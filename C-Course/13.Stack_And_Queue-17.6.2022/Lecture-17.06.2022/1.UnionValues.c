#include <stdio.h>

union value
{
    long int i_val;
    float f_val;
} data;

int i;
float f;

int main()
{
    data.f_val = 5.0;
    data.i_val = 3;

    printf("%d \t %f \n", data.i_val, data.f_val);

    i = data.i_val;
    f = data.f_val;

    printf("%d \t %f \n", i, f);

    data.f_val = 5.5;

    printf("%d \t %f \n", data.i_val, data.f_val);

    i = data.i_val;

    printf("%d \t %f \n", i, f);

    return 0;
}