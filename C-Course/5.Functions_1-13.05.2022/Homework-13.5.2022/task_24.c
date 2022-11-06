// 24. Функция, която по зададени граници на интервал [a,b] , намира и
// извежда сумата от четните числа от този интервал.

#include <stdio.h>

void intervalEvenSum(int minValue, int maxValue);

int main()
{
    int minValue, maxValue;

    printf("Enter interval min value: ");
    scanf("%d", &minValue);
    printf("Enter interval max value: ");
    scanf("%d", &maxValue);

    intervalEvenSum(minValue, maxValue);
}

void intervalEvenSum(int minValue, int maxValue)
{
    int sum = 0;

    for (int i = minValue; i <= maxValue; i++)
    {
        if (i % 2 == 0)
            sum += i;
    }
    
    printf("Even numbers sum = %d", sum); 
}