#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char * getString(void);
void lettersResizing(char str[]);

int main()
{
    char *myStr = getString();

    lettersResizing(myStr);
    printf("%s", myStr);

    free(myStr);
    return 0;
}

void lettersResizing(char str[])
{
    size_t size = strlen(str);

    for (size_t i = 0; i < size; i++)
    {
        if (isalpha(str[i]) && isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
        else if (isalpha(str[i]) && islower(str[i]))
        {
            str[i] = toupper(str[i]);
        }
    }
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

