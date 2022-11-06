//12. Функция, връщаща n-тото число на Фибоначи.

#include <stdio.h>

long fibonacci(int n);

int main(){   

    int num;

    printf("Enter number: ");
    scanf("%d", &num);
    
    printf("%d", fibonacci(num));
}

long fibonacci(int n){
    int first = 1, second = 1, next = 0;

    if (n == 1 || n == 2)
        return 1;
    
    for (int i = 3; i <= n; i++)
    {
        next = first + second;
        first = second;
        second = next;
    }
    
    return next;
}