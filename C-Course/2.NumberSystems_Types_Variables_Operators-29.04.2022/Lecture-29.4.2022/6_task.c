#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
    printf("The minimum value of INT = %d \n", INT_MIN);
    printf("The maximum value of INT = %d \n", INT_MAX);

    printf("The maximum value of float = %.10e \n", FLT_MAX);
    printf("The minimum value of float = %.10e \n", FLT_MIN);
    return 0;
}