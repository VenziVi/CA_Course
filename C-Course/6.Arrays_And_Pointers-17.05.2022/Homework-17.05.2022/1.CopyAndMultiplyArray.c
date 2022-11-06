// 1. Прочетете масив от цели числа от клавиатурата.
// Копирайте въведения масив във втори масив, като умножите стойността на
// всеки елемент по 2. Принтирайте двата масива.

#include <stdio.h>
#define SIZE 5

void printArray(int *arr, int arrSize);

int main()
{
    int firstArr[SIZE] = {0};
    int secondArr[SIZE] = {0};
    int multiplier = 2;

    printf("Enter %d digits: ", SIZE);

    //Set values of an array
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", firstArr + i);
    }
    
    //Multiply value by multiplier and set it on same index of secondArray
    for (int i = 0; i < SIZE; i++)
    {
        *(secondArr + i) = *(firstArr + i) * multiplier;
    }
    
    //Print both arrays
    printf("First array values:  ");
    printArray(firstArr, SIZE);

    printf("\n");

    printf("Second array values: ");
    printArray(secondArr, SIZE);
}

void printArray(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d \t", *(arr + i));
    }
}