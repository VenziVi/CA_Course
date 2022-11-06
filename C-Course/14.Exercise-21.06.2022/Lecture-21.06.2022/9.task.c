#include <stdio.h>
#include <stdlib.h>

int main()
{
    char arr[10] = "0010010101";

    int firstChar = 0;
    int secondChar = 0;

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == '1')
        {
            for (int j = 9; j >= i; j--)
            {
                if (arr[j] == '1')
                {
                    if (arr[j] == '1')
                    {
                        for (int k = i; k <= j; k++)
                        {
                            printf("%c", arr[k]);
                        }
                    }
                    printf("\n");
                }
            }
        }
    }
}
