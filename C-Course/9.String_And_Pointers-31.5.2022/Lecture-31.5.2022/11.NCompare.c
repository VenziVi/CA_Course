#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char * getString(void);

int main()
{
    char *myStr = getString();
    char *myStr1 = getString();
    int n = 0;
    printf("How many charactes to compare: ");
    scanf("%d", &n);

    int result = strncmp(myStr, myStr1, n);
    
    if (result == 0)
    {
        printf("Equal.");
    }
    else
    {
        printf("NOT equal.");
    }

    free(myStr);
    free(myStr1);
    return 0;
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
