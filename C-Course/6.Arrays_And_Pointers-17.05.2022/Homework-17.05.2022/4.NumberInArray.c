// 4. Напишете програма, която да брои колко пъти се среща едно число в даден масив
// от цели числа. Масивът трябва да бъде въведен от клавиатурата. Принтирайте
// резултатите.

#include <stdio.h>

#define SIZE 10

void allNumbersCounter(int *arr, int size);
void sortArray(int *arr, int size);
void swap(int *fValue, int *sValue);

int main()
{
    int arr[SIZE] = {0};

    printf("Enter %d numbers: ", SIZE);

    //Set values of an array
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", arr + i);
    }

    sortArray(arr, SIZE);
    allNumbersCounter(arr, SIZE);

    return 0;
}

//Count and print how many times each number is contained in the array.
void allNumbersCounter(int *arr, int size)
{
    int counter = 0;
    int currNum = 0;
    int lastNum = 0;

    for (int i = 0; i < size; i++)
    {
        currNum = *(arr + i);
        counter = 1;

        if (lastNum == currNum && i > 0)
        {
            continue;
        }

        for (int j = i + 1; j < size; j++)
        {
            if (*(arr + i) != *(arr + j))
            {     
                break;
            }

            counter++;
        }
        
        printf("Number %d --> %d \n", currNum, counter);
        lastNum = currNum;
    }
}

//Sort array using bubble sort algorithm
void sortArray(int *arr, int size)
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