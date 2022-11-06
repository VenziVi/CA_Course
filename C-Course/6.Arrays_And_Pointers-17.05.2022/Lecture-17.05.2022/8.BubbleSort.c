// 8. Напишете програма, която сортира масив, въведен от клавиатурата,
// използвайки указатели. За целта използвайте метода на мехурчето,
// Bubble sor

#include <stdio.h>
#define SIZE 10

void swap(int *fNum, int *sNum);
void printArray(int *arr, int size);

int main()
{
    int arr[SIZE] = {0};

    printf("Enter %d numbers: ", SIZE);

    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", arr + i);
    }

    int numbersLeft = SIZE;

    for (int j = 0; j < SIZE; j++)
    {
        for (int i = 0 ; i < numbersLeft - 1; i++)
        {
            if (*(arr + i) > *(arr + i + 1))
            {
                swap(arr + i, arr + i + 1);
            }
        }

        numbersLeft--;
    }

    printArray(arr, SIZE);
    return 0;
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