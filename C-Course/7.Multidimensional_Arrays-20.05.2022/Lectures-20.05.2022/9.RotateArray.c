// 3. Напишете програма, която да завърти даден масив от цели числа с N позиции
// наляво. Масива и числото N трябва да бъдат въведени от клавиатурата.
// Принтирайте оригиналния и резултатния масиви.

#include <stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < 5; i++)
    {
        printf("%d \t", arr[i]);
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        int temp = arr[0];

        for (int i = 0; i < 5; i++)
        {
            if (i < 4)
            {
                arr[i] = arr[i + 1];
            }
            else
            {
                arr[i] = temp;
            }
        }   
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d \t", arr[i]);
    }
}