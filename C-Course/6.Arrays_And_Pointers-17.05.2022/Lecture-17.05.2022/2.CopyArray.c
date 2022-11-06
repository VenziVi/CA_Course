// 2. Напишете програма, която копира един масив в друг, използвайки
// указатели.

#include <stdio.h>
#define SIZE 10

void copyElemnt(int *fNum, int *sNum);
void printArray(int *arr, int size);

int main()
{
    int arrA[SIZE] = {0};
    int arrB[SIZE] = {0};

    for (int i = 0; i < SIZE; i++)
    {
        *(arrA + i) = i;
    }

    for (int i = 0; i < SIZE; i++)
    {
        copyElemnt(arrA + i, arrB + i);
    }

    printf("Array A: ");
    printArray(arrA, SIZE);
    printf("\n");
    printf("Array B: ");
    printArray(arrB, SIZE);
}

void copyElemnt(int *fNum, int *sNum)
{
    *sNum = *fNum;
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", *(arr + i));
    }  
}