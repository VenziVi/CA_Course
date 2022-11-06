#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char * getString(void);
void wordsReverse(char str[], char reversed[], size_t len);

int main()
{
    char *myStr = getString();
    const size_t len = strlen(myStr);
    char reversed[len];

    wordsReverse(myStr, reversed, len);

    printf("Reversed = %s", reversed);

    free(myStr);
    return 0;
}

void wordsReverse(char str[], char reversed[], size_t len)
{
    size_t start = len - 1;
    size_t end = len - 1;
    size_t i = 0, index = 0;

    while (start > 0)
    {
        if (isspace(str[start]))
        {
            i = start + 1;

             while (i <= end)
             {
                 reversed[index] = str[i];
                 i++;
                 index++;
             }
             
             reversed[index++] = ' ';
             
             end = start - 1;
        }
        start--;
    }

    for (size_t i = 0; i <= end; i++)
    {
        reversed[index] = str[i];
        index++;
    }

    reversed[index] = '\0';
}

char * getString(void)
{
    size_t size = 20;
    char *setString = malloc(size);
    size_t length = 0;
    char ch = 0;

    printf("Enter string: ");

    while ( (ch = getchar()) != '\n')
    {
        if (length == size - 1)
        {
            setString = realloc(setString, size * 2);
            size *= 2;
        }

        setString[length++] = ch;
    }

    setString[length] = '\0';
    return setString;
}

