#include <stdio.h>
#include <string.h>

void changeSymbol(char *str, char symbol, char toChange)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == toChange)
        {
            str[i] = symbol;
        }
    }
    
}

int main()
{
    char str[] = "asdasdfasa";

    char symbolToChange = 'a';
    char newSymbol = '#';

    changeSymbol(str, newSymbol, symbolToChange);

    printf("string: %s \n", str);
}
