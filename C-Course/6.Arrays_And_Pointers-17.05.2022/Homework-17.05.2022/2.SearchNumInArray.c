// 2. Напишете програма, която запълва масив от 20 елемента с произволно избрани
// цели числа. За целта използвайте функцията rand().
// Въведете едно цяло число от клавиатурата. Проверете дали въведеното число
// от клавиатурата е намерено в масива. Принтирайте масива и отговора дали
// числото е намерено в масива.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include<time.h>
#define SIZE 20

void printArray(int *arr, int arrSize);
bool isExist(int *arr, int size, int number);

int main()
{
    int arr[SIZE] = {0};
    int num = 0;
    //srand(time(0));

    printf("Enter number: ");
    scanf("%d", &num);

    //Set array with random values
    for (int i = 0; i < SIZE; i++)
    {
        *(arr + i) = rand() % 99;
    }

    printArray(arr, SIZE);

    printf("\n");

    (isExist(arr, SIZE, num)) ? 
        printf("Number %d exists.", num) :
        printf("Number %d does't exists.", num);
}

void printArray(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d \t", *(arr + i));
    }
}

//checks if number exists in array
bool isExist(int *arr, int size, int number)
{
    for (int i = 0; i < size; i++)
    {
        if (*(arr + i) == number)
        {
            return true;
        }
    }

    return false;
}