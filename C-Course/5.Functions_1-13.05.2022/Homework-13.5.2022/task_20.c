// 20. Напишете програма на C за броене на цифрите на дадено число с
// помощта на рекурсивна функция.

#include <stdio.h>

int countDigits(long long number);

int main()
{
    long long num;

    printf("Enter number: ");
    scanf("%lld", &num);

    printf("%d", countDigits(num));
}

int countDigits(long long num)
{
    static char count = 0;
    
    if (num == 0)
    {
        return count;
    }

    count++;
    return countDigits(num / 10);
}