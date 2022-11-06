// 7. Функция, проверяваща дали едно число е просто. Програма, която от
// 3 въведени числа, извежда само простите от тях.

#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main()
{
    int num, count = 0;

    do
    {
        count++;
        printf("Enter number: ");
        scanf("%d", &num);

        if (isPrime(num))
            printf("Number %d is prime number. \n", num);
        
    } while (count < 3);
    
}

bool isPrime(int n)
{
    for (int i = 2; i <= n / 2; i++)
    {
        if(n % i == 0)
            return 0;
    }

    return 1;
}