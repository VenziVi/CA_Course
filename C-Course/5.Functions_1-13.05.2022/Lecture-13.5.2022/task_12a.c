//12. Функция, връщаща n-тото число на Фибоначи с рекурсия.

#include <stdio.h>

long fib(int n);

int main(){   

    int num;

    printf("Enter number: ");
    scanf("%d", &num);
    
    printf("%d", fib(num));
}

long fibonacci(int n){

    if (n == 1 || n == 2)
        return 1;
    else
        return fib(n -1) + fib(n - 2);
    
}