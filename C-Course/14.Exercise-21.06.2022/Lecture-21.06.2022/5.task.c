#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int *arr, int size, int key)
{
    int min = 100;

    if (key  == 0)
    {
        for (int  i = 0; i < size; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }
    }
    else if (key == 1)
    {
        for (int  i = 0; i < size; i++)
        {
            if (arr[i] > 0)
            {
                if (arr[i] < min)
                {
                    min = arr[i];
                }
            }
        }
    }
    return min;
}

int max(int *arr, int size, int key)
{
    int max = -100;

    if (key  == 0)
    {
        for (int  i = 0; i < size; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
    }
    else if (key == 1)
    {
        for (int  i = 0; i < size; i++)
        {
            if (arr[i] > 0)
            {
                if (arr[i] > max)
                {
                    max = arr[i];
                }
            }
        }
    }
    return max;
}

int sum(int *arr, int size, int key)
{
    int sum = 0;

    if (key  == 0)
    {
        for (int  i = 0; i < size; i++)
        {
            sum += arr[i];
        }
    }
    else if (key == 1)
    {
        for (int  i = 0; i < size; i++)
        {
            if (arr[i] > 0)
            {
                sum += arr[i];
            }
        }
    }

    return sum;
}

int count(int *arr, int size, int key)
{
    int count = 0;

    if (key  == 0)
    {
        return size;
    }
    else if (key == 1)
    {
        return size;
        for (int  i = 0; i < size; i++)
        {
            if (arr[i] > 0)
            {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    char command[5];
    printf("Enter command: ");
    scanf("%s", command);
    int len = strlen(command);
    char op = 0;
    int size = 0;

    printf("Enter array: ");
    scanf("%d", &size);

    int *arr = malloc(sizeof(int) * size);

    printf("Enter vlues: ");

    for (int i = 0; i < size; i++)
    {
       scanf("%d", &arr[i]);
    }
    int key = 0;

    if (len == 4)
    {
        if (command[len -1] == 'p')
        {
            key = 1;
        }
        if (command[len -1] == 'n')
        {
            key = 0;
        }   
    }

    int result = 0;
    
}