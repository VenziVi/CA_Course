#include <stdio.h>
#include <math.h>

int main(){

    int num, n, k;

    printf("Enter number: ");
    scanf("%d", &num);

    int r = sqrt(num);

    for (int i = 0; i <= r; i++)
    {
        n = i;
        for (int j = 0; j <= r; j++)
        {
            k = j;
            int result = n * n + k * k;
            if (result == num)
            {
                printf(" m = %d, k = %d, n = %d \n", n, k, num);
            }
        }   
    }
}