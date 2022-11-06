#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * getString(void);

int main()
{
    char *myStr = getString();

    const size_t size = strlen(myStr) + 1;

    char copy[size];
    
    strcpy(copy, myStr);

    printf("String: %s \n", myStr);
    printf("Copy: %s", copy);

    free(myStr);
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
