// ● 9. Една крайна редица от цели числа се нарича зигзаг, ако всеки елемент на редицата (без
// първия и последния) е или по-голям от двата му съседа или по-малък от двата съседни
// елемента. Да се напише функция, която по зададен масив от цели числа, определя дали
// редицата, образувана от тези числа е зигзаг.
// Вход. На стандартния вход се задават числови редици – всяка на отделен ред с разделител
// един интервал между числата.
// Ограничения. Всички числа се представят в типа int
// Изход. За всяка редица се извежда на отделен ред yes за зигзаг и no – за редица, която не е
// зигзаг

#include <stdio.h>
#include <stdbool.h>

bool isZigZag(int arr[], int size);

int main()
{
    const int testSize = 9;
    //int arr[] = {3, 5, 3, 4, 8, 5, 1, 3, 9};
    int arr[] = {3, 5, 3, 5, 3, 5, 3, 5, 3};

    if (isZigZag(arr, testSize))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    
    return 0;
}

bool isZigZag(int arr[], int size)
{

    for (int i = 1; i < size - 1; i++)
    {
        if ( (arr[i] > arr[i + 1] && arr[i] < arr[i - 1]) ||
             (arr[i] < arr[i + 1] && arr[i] > arr[i- 1]) )
        {
            return false;
        }
    }
    
    return true;
}