// 19. Напишете рекурсивни функции
// max, min, sum, product, mean,
// за намиране съответно на максимум, минимум, сума, произведение и
// средно аритметично на елементите на масив от цели числа.
// Масивът и броят елементи в него се подават като параметри на
// функциите .

#include <stdio.h>

int findMax(int arr[], int size);
int findMin(int arr[], int size);
int findSum(int arr[], int size);
int findProduct(int arr[], int size);
float findAVG(int arr[], int index, int size);

int main()
{
    const int size = 6;
    int index = 0;
    int array[] = {5, 9, 2, 13, 44, 8};

    printf("Min = %d \n", findMin(array, size));
    printf("Max = %d \n", findMax(array, size));
    printf("Sum = %d \n", findSum(array, size));
    printf("Product = %d \n", findProduct(array, size));
    printf("Avg = %.2f \n", findAVG(array, index, size));

    return 0;
}

int findMin(int arr[], int size)
{
   int min = arr[0];

    if (size == 1)
    {
        return arr[0];
    }
    else 
    {
        min = findMin(arr, size - 1);

        if (min < arr[size - 1])
        {
            return min;
        }
        else
        {
            return arr[size - 1];
        }
    }
} 

int findMax(int arr[], int size)
{
    int max;

    if (size == 1)
    {
        return arr[0];
    }
    else 
    {
        max = findMax(arr, size - 1);

        if (max > arr[size - 1])
        {
            return max;
        }
        else
        {
            return arr[size - 1];
        }
    }
}

int findSum(int arr[], int size)
{
    int sum = 0;

    if (size == 0)
    {
        return sum;
    }
    
    return (sum = findSum(arr, size - 1) + arr[size - 1]);
}

int findProduct(int arr[], int size)
{
    int product = 1;

    if (size == 0)
    {
        return product;
    }
    
    return (product = findProduct(arr, size - 1) * arr[size - 1]);
}

float findAVG(int arr[], int index, int size)
{
  if (index == size - 1) {
        return arr[index];
    }

    if (index == 0)
        return ((arr[index] + findAVG(arr, index + 1, size)) / size);
    else
        return (arr[index] + findAVG(arr, index + 1, size));
}