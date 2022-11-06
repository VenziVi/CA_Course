// Задача 8. Напишете програма, която по зададено естествено число n,
// отпечатва сумата от първите n члена на редицата
// 1, 1/2, 1/3, .... 1/n

#include <stdio.h>

int main(){

    int i, n;
    double s = 0.0;

    printf("Enter number: ");
    scanf("%d", &n);

    for ( i = 1; i <= n; i++)
    {
        s += 1./i;
    } 

    printf("Result = %lf", s);   
}