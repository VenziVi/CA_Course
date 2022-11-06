#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* findCommonElements(int fArr[], int fArrSize, int sArr[], int sArrSize);
int* setUnionArray(int fArr[], int fArrSize, int sArr[], int sArrSize);
void printArray(int arr[], int size);

int resultSize = 0;

int main()
{
    int fArr[] = {5, 2, 2, 65, 13, 2, 45};
    int sArr[] = {2, 18, 23, 2, 2, 13};
    int fArrSize = sizeof(fArr) / sizeof(int);
    int sArrSize = sizeof(sArr) / sizeof(int);

    int *common = findCommonElements(fArr, fArrSize, sArr, sArrSize);
    int *unionArr = setUnionArray(fArr, fArrSize, sArr, sArrSize);

    printArray(common, resultSize);
    printArray(unionArr, fArrSize);

    free(common);
    free(unionArr);
    return 0;
}

int* setUnionArray(int fArr[], int fArrSize, int sArr[], int sArrSize)
{
    int biggestSize = 0;
    int smallestSize = 0;
    int *biggestArr = NULL;
    int *smallestArr = NULL;

    if (fArrSize > sArrSize)
    {
        biggestArr = fArr;
        biggestSize = fArrSize;
        smallestArr = sArr;
        smallestSize = sArrSize;
    }
    else
    {
        biggestArr = sArr;
        biggestSize = sArrSize;
        smallestArr = fArr;
        smallestSize = fArrSize;
    }


    int *resultArr = malloc(sizeof(int) * biggestSize);

    for (int i = 0; i < biggestSize; i++)
    {
        if (i < smallestSize)
        {
            resultArr[i] = biggestArr[i] + smallestArr[i];
        }
        else
        {
            resultArr[i] = biggestArr[i];
        }
    }

    return resultArr; 
}

int* findCommonElements(int fArr[], int fArrSize, int sArr[], int sArrSize)
{
    int smallestArr = (fArrSize < sArrSize) ? fArrSize : sArrSize;

    bool isExists = false;
    int *resultArr = malloc(sizeof(int) * smallestArr);

    for (int i = 0; i < fArrSize; i++)
    {
        for (int j = 0; j < sArrSize; j++)
        {
            if (fArr[i] == sArr[j])
            {
                for (int k = 0; k < resultSize; k++)
                {
                    if (resultArr[k] == fArr[i])
                    {
                        isExists = true;
                    }
                }
                
                if (isExists == false)
                {
                    resultArr[resultSize++] = fArr[i];
                }

                isExists = false;
            }
        }
    }

    return resultArr;
}

void printArray(int arr[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}