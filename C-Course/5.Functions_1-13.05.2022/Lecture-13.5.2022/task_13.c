//13. Рекурсивна функция, връщаща n!=1*2*3*4*5*...(n-1)*n=(n-1)!*n

#include <stdio.h>

long fact(int n);

int main(){   

    int num;

    printf("Enter number: ");
    scanf("%d", &num);
    
    printf("%i", fact(num));
}

long fact(int n){

    if (n == 1)
        return 1;
    else
        return n * fact(n - 1);     
}