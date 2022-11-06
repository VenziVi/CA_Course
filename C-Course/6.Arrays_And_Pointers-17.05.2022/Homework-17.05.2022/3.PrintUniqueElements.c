// 3. Напишете програма, която принтира уникалните елементи от масив с цели числа,
// въведени от клавиатурата. За целта, някои от числата трябва да се повтарят.

#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

void printUniqueElements(int *arr, int size);

int main()
{
    int arr[SIZE] = {0};

    printf("Enter %d numbers: ", SIZE);

    //Set values of an array
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", arr + i);
    }

    printUniqueElements(arr, SIZE);
}

// print unique elements in array
void printUniqueElements(int *arr, int size)
{
    bool isUnique = true;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((arr + i) != (arr + j) && *(arr + i) == *(arr + j))
            {
                isUnique = false;
                break;
            }
        }

        if (isUnique == true)
        {
            printf("%d \t", *(arr + i));
        }

        isUnique = true;
    }
}