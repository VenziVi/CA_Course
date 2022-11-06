#include <stdio.h>
#include <unistd.h>

int main()
{   
    int input, bin[8], i;

    printf("Insert input: ");
    scanf("%d", &input);

    while (input != 0)
    {
        for (i = 0; i < 8; i++)
        {
            bin[i] = input % 2;
            input = input / 2;
        }
    }

    for (i = 7; i >= 0; i--)
    {
        printf("%d", bin[i]);
    }

    printf("\n");

    for (i = 7; i >= 0; i--)
    {
        usleep(200000);

        if (bin[i] == 0)
        {
            printf(".");
        }
        else
        {
            printf("*");
        }
    }
    
    return 0;
}