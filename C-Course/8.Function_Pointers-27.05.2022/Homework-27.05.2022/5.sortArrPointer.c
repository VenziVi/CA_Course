// Задача 4. Напишете функция void sort_arr(void *A, int n, int dir, ftype fp),
// където А е обикновен масив от цели числа,
// n - размера на масива,
// dir - посоката, в която да бъде сортиран масива,
// ftype - указател към функция, която приема масив, неговия размер и в каква посока да бъде
// сортиран входния масив.
// ftype трябва да сортира масива във възходящ или низходящ ред в зависимост от третия
// параметър на функцията.
// Принтирайте изходния и резултатни масиви

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void setArray(int arr[], int size);
void printArray(int arr[], int size);
int setDirection(void);
void swap(int *fValue, int *sValue);
void sortDesc(int arr[], int size);
void sortAsc(int arr[], int size);
void sort_arr(int arr[], int size, int dir, void (*fp)(int arr[], int size));
void (*fp)(int arr[], int size) = NULL;

int main()
{
    int arr[SIZE] = {0};
    int dir = setDirection();

    setArray(arr, SIZE);
    printArray(arr, SIZE);

    sort_arr(arr, SIZE, dir, (*fp));
    
    printArray(arr, SIZE);
}

void sort_arr(int arr[], int size, int dir, void (*fp)(int arr[], int size))
{
    if (dir == 1)
    {
        fp = sortAsc;
    }
    else if (dir == -1)
    {
        fp = sortDesc;
    }

    fp(arr, size);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}

void setArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
}

void sortDesc(int arr[], int size)
{
    int numbersLeft = size;

    for (int j = 0; j < size; j++)
    {
        for (int i = 0 ; i < numbersLeft - 1; i++)
        {
            if (*(arr + i) < *(arr + i + 1))
            {
                swap(arr + i, arr + i + 1);
            }
        }

        numbersLeft--;
    }
}
void sortAsc(int arr[], int size)
{
    int numbersLeft = size;

    for (int j = 0; j < size; j++)
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
}

void swap(int *fValue, int *sValue)
{
    int temp = *fValue;
    *fValue = *sValue;
    *sValue = temp;
}

int setDirection(void)
{
    int dir = 0;

    do
    {
        printf("Enter 1 for ascending or -1 for descending sort: ");
        scanf("%d", &dir);
    } while (dir > 1 || dir < -1 || dir == 0);

    return dir;
}