// 3. Напишете програма, която разменя елементите на два еднакви по размер
// масива, използвайки указатели.

#include <stdio.h>
#define SIZE 5

void swap(int *fNum, int *sNum);
void printArray(int *arr, int size);

int main()
{
    int arrA[SIZE] = {1, 2, 3, 4, 5};
    int arrB[SIZE] = {10, 20, 30, 40, 50};

    for (int i = 0; i < SIZE; i++)
    {
        swap(arrA + i, arrB + i);
    }

    printf("Array A: ");
    printArray(arrA, SIZE);
    printf("\n");
    printf("Array B: ");
    printArray(arrB, SIZE);
}

void swap(int *fNum, int *sNum)
{
    int temp = *fNum;
    *fNum = *sNum;
    *sNum = temp;
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", *(arr + i));
    }  
}