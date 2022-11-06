#include <stdio.h>

int maxCount = 0;

void swap(int *fNum, int *sNum)
{
    int temp = *fNum;
    *fNum = *sNum;
    *sNum = temp;
}

void bubbleSort(int arr[], int size)
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

int findLongestLine(int arr[], int size)
{
    int count = 0;
    int maxLineIndex = 0;
    int startIndex = 0;

    for (int i = 0; i < size; i++)
    {
        count = 1;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                startIndex = i;
                count++;
            }
            else
            {
                break;
            } 
        }

        if (maxCount < count)
        {
            maxCount = count;
            maxLineIndex = startIndex;
        }
    }

    return maxLineIndex;
}

int main()
{
    int numArr[] = {1, 4, 2, 1, 6, 4, 3, 1, 2, 6, 7, 6, 6, 8, 6};
    int arrSize = sizeof(numArr) / sizeof(int);
    int index = 0;

    bubbleSort(numArr, arrSize);

    index = findLongestLine(numArr, arrSize);

    for (int i = index; i < (index + maxCount); i++)
    {
        printf("%d ", numArr[i]);
    }
    
    return 0;
}