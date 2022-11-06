// 2. Напишете програма, която въвежда масив от цели числа от
// клавиатурата. Сортирайте го във възходящ ред. След това от
// клавиатурата въведете цяло число и го поставете на правилната му
// позиция в масива, така че да не се нарушава реда. Принтирайте
// масива

#include <stdio.h>
#include <stdlib.h>

void swap(int *fValue, int *sValue);
void sortArray(int arr[], int size);
int* readArr(int n);
void printArray(int arr[], int arrSize);

int main()
{
    int* myArr = readArr(10);

    int num = 0;
    scanf("%d", &num);

    sortArray(myArr, 10);

    int *sArr = malloc(11 * (sizeof(int)));

    int k = 0;

    for (int i = 0; i < 10; i++)
    {
        if ((num <= myArr[i]))
        {
            sArr[i] = num;
            k++;
            break;
        }
        else if (num > myArr[i])
        {
            sArr[i] = myArr[i];
            k++;
        }
    }

    for (int i = k; i < 11; i++)
    {
        sArr[i] = myArr[i - 1];
    }

    printArray(sArr, 11);
}

void swap(int *fValue, int *sValue)
{
    int temp = *fValue;
    *fValue = *sValue;
    *sValue = temp;
}

void sortArray(int arr[], int size)
{
    int numbersLeft = size;

    for (int j = 0; j < size; j++)
    {
        for (int i = 0 ; i < numbersLeft - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(&arr[i], &arr[i + 1]);
            }
        }

        numbersLeft--;
    }
}

int* readArr(int n)
{
    int* result = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", result + i);
    }
    return result;
}

void printArray(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        printf("%d \t", arr[i]);
    }
    printf("\n");
}