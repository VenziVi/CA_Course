#include <stdio.h>

int main(){

    double a, b;
    int n;

    printf("Enter number a: ");
    scanf("%lf", &a);

    do
    {
        printf("Enter number b: ");
        scanf("%lf", &b);
    } while (b == 0);

    do
    {
        printf("Enter number N: ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    
    printf("Result = %.*lf", n, a / b);
}