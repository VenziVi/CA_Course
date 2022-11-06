#include <stdio.h>

int main()
{
    int i = 0;

    for (;;)
    {
        if (i == 48)
        {
            break;
        }
        printf("%d\n", i);
        i++;
    }
}