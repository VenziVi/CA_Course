#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char * getString(void);
int getLength(char str[]);

int main()
{
    char *myStr = getString();
    int length = getLength(myStr);

    printf("Length = %d", length);

    free(myStr);
    return 0;
}

int getLength(char str[])
{
    int i = 0;

    while (str[i++] != '\0');
    
    return (i - 1);
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

