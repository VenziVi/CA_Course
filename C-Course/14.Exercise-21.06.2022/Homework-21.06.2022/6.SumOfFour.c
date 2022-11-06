// ● 6. Даден e масив от 5 положителни числа. Да се напишат две функции, които
// намират минималната и максималната стойност, които могат да се
// изчислят, като се сумират точно 4 от тези 5 числа.
// ● Програмата чете масива от тези 5 числа, извиква съответните функции и
// отпечатва съответно minimum и maximum стойностите, всяка на нов ред.
// arr = [1,3,5,7,9]
// minimum sum is 1 + 3 + 5 + 7 = 16
// maximum sum is 3 + 5 + 7 + 9 = 24.
// 5. отпечатва се 16 24

#include <stdio.h>
#include <limits.h>

#define SIZE 5
#define MIN INT_MIN
#define MAX INT_MAX

void printMinAndMax(int arr[], int size);

int main()
{
    int const testSize = 3;
    int arr[][SIZE] = {{1, 3, 5, 7, 9},
                        {3, 7, 2, 22, 12},
                        {54, 23, 65, 43, 12}};

    for (int i = 0; i < testSize; i++)
    {
        printMinAndMax(arr[i], SIZE);
    }
    
    return 0;
}

void printMinAndMax(int arr[], int size)
{
    int sum = 0;
    int min = MAX;
    int max = MIN;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j)
            {
                sum += arr[j];
            }
            
        }

        if (sum > max)
        {
            max = sum;
        }
        if (sum < min)
        {
            min = sum;
        }
        
        sum = 0;
    }

    printf("Min = %d Max = %d \n", min, max);
} 