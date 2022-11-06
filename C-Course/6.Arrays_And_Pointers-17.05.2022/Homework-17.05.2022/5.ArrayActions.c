// Задача 5.Дефинирайте едномерен масив int с 10 елемента =
// {100,90,80,70,60,50,40,30,20,10}.
// Дефинирайте пойнтер, който ще сочи към масива.
// Достъпете 3 тия елемент от масива и му задайте стойност 5.
// Достъпете 4 тия елемент и му задайте стойност 33.
// Достъпете 5 тия елемент и го намалете със 7.
// Достъпете 7 мия елемент и го увеличете с 10.
// Достъпете 10 тия елемент и го умножете по 3.
// Изпишете го по двата възможни начина и закоментирайте единия.
// Принтирайте на екрана всички елементи на масива.

#include <stdio.h>
#define SIZE 10

void printArray(int *arr, int size);

int main()
{
    int arr[SIZE] = {0};
    int *ptr_arr = arr;

    for (int i = 0; i < SIZE; i++)
    {
        *(arr + i) = 100 - (i * 10);
    }

    // Достъпете 3 тия елемент от масива и му задайте стойност 5.
    //*(arr + 2) = 5;
    *(ptr_arr + 2) = 5;
    //arr[2] = 5;

    // Достъпете 4 тия елемент и му задайте стойност 33.
    //*(arr + 3) = 33;
    *(ptr_arr + 3) = 33;
    //arr[3] = 33;

    // Достъпете 5 тия елемент и го намалете със 7.
    //*(arr + 4) -= 7;
    *(ptr_arr + 4) -= 7;
    //arr[4] -= 7;

    // Достъпете 7 мия елемент и го увеличете с 10.
    //*(arr + 6) += 10;
    *(ptr_arr + 6) += 10;
    //arr[6] += 10;

    // Достъпете 10 тия елемент и го умножете по 3.
    //*(arr + 9) *= 3;
    *(ptr_arr + 9) *= 3;
    //arr[9] *= 3;
    
    printArray(arr, SIZE);
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d \t", *(arr + i));
    }
    
}