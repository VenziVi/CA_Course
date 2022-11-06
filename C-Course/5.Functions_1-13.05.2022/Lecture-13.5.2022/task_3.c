// 3. Функция, намираща сумата на целите числата в даден интервал [a,b],
// като a и b са параметри на функцията.
// long sum(int a, int b)
// Програмата чете 3 интервала и отпечатва в кой интервал сумата е
// нечетно числа.

#include <stdio.h>

long sum();

int main(){
    
    int a, b, count = 0, numSum;

    do
    {
        count++;

        printf("Enter number a: ");
        scanf("%d", &a);

        printf("Enter number b: ");
        scanf("%d", &b);

        numSum = sum(a, b);

        if(numSum % 2 != 0)
            printf("Sum in interval %d, %d = %d \n", a, b, numSum);
        
    } while (count < 3);
}

long sum(int a, int b){
    long sum = 0;

    for (int i = a; i <= b; i++)
    {
        sum += i;
    }
        
    return sum;
}

