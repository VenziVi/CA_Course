// Разбийте число като сума от степени на
// двойката.
#include <stdio.h>
#include <math.h>

void printSteps(int num);

int main()
{
    //int number = 645;   
    int number = 1874;  

    printSteps(number);

    return 0;
}

void printSteps(int num)
{
    int size = sizeof(num) * 8;
    int sum = 0;
    int calc = 0;
    
    for (int i = 0; i < size; i++)
    {   
        if ((num >> i) & 1)
        {
            calc =(int)(1 * (pow(2, i)));
            printf("1 * 2 ^ %d --> %d \n", i, calc);
        }
        else
        {
            calc = (int)(0 * (pow(2, i)));
            printf("0 * 2 ^ %d --> %d \n", i, calc);
        }

        sum += calc;
    }

    printf("Number = %d \n", sum);
}
