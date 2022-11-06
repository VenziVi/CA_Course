// 4. Да се напише програма, която използва функция, обръщаща до 20
// цифрено цяло число. Водещите нули не се извеждат.
// Ако числото 123 е параметър —> връща 321
// 120 —> 21
// Програмата отпечатва резултата от изпълнението на функцията

#include <stdio.h>

long revers();

int main()
{   
    long num;

    printf("Enter numbers: ");
    scanf("%ld", &num);

    printf("%ld", revers(num));
}

long revers(int num)
{
    int result, temp;

    while (num != 0)
    {
        temp = num % 10;
        result = result * 10 + temp;
        num /= 10;
    }

    return result;
}
