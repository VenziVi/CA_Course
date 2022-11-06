// 17. Функция, която намира сумата от елементите на масив и програма,
// намираща средното аритметично от елементите на масив.
// 18. Функция, която отпечатва стойностите на масив.

#include <stdio.h>

int calcSum(int *arr, int n);
void arrPrint(int * arr, int n);

int main()
{   
    int x;
    int arr[5];

    for (int i = 0; i < 5; i++)
    {
        printf("Enter number: ");
        scanf("%d", &x);
        arr[i] = x;
    }
    

    int sum = calcSum(arr, 5);
    printf("%d \n", sum);
    printf("%f \n", sum / 5.);
    arrPrint(arr, 5); 
}

int calcSum(int *arr, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    return sum;
}

void arrPrint(int * arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
}