// 16. Дадена е редица от N цели положителни числа. Напишете програма, която
// намира дължината на най-дългата подредица, сумата от елементите на която се
// дели без остатък на дадено число K. Не е задължително подредицата да съдържа
// последователни елементи от дадената редица. Подредицата може да бъде празна
// (т.е. с дължина 0), както и може да съвпада с цялата редица.
// Вход
// Първият ред съдържа две числа N и K. Следват елементите на редицата.
// Всички числа във входа (включително N и К) са цели положителни числа, по-малки от
// 1000.
// Изход
// Дължината на най-дългата намерена подредица с описаното свойство.
// Пример
// Вход:
// 7 5
// 1 2 1 2 2 1 4
// Изход:
// 5

#include <stdio.h>

int longestLineSize(int arr[], int size, int divider);
int entireArraySum(int arr[], int size, int divider);

int main()
{
    int testArray[] = {1, 2, 1, 2, 2, 1, 4};
    int testSize = sizeof(testArray) / sizeof(int);
    int divider = 5;

    int lineSize = longestLineSize(testArray, testSize, divider);

    printf("Line is %d elements long.", lineSize);

    return 0;
}

int longestLineSize(int arr[], int size, int divider)
{
    int result = 0;
    int counter = 0;
    int sum = 0;

    result = entireArraySum(arr, size, divider);

    if (result > 0)
    {
        return result;
    }

    for (int i = 0; i < size; i++)
    {
        counter = 0;
        sum = arr[i];
        counter++;

        for (int j = i + 1; j < size; j++)
        {
            sum += arr[j];
            counter++;

            if (sum % divider == 0)
            {
                if (result < counter)
                {
                    result = counter;
                }
            }
        }
    }
    
    return result;
}

int entireArraySum(int arr[], int size, int divider)
{
    int result = 0;
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    
    if (sum % divider == 0)
    {
        result = size;
        return result;
    }
    
    return result;
}