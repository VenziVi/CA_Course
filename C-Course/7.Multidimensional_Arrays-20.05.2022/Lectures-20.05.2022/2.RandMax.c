#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("%d \n", RAND_MAX);
    int *arr = malloc(100 * sizeof(int));

    for (int i = 0; i < 100; i++)
    {
        *(arr + i) = rand() % 100;
    }
    
    for (int i = 0; i < 100; i++)
    {
        printf("%d \t", *(arr + i));
    }
}
