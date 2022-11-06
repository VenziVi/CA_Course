// Задача 9. Напишете програма, която отпечатва сумата от първите n
// събираеми, като числото n се въвежда
// [9 + 99 + 999 + 9999 ...].

#include <stdio.h>

int main(){

    int i, n;
    long long int s = 9, zeroes = 10, result;

    printf("Enter number: ");
    scanf("%d", &n);

    result = s;

    for ( i = 1; i < n; i++)
    {
        result += s * zeroes;
        zeroes *= 10;     
    } 

    printf("Result = %lld", result);   
}