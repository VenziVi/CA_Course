#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char * getString(void);
int charCounter(char str[], char ch);

int main()
{
    char *myStr = getString();
    char ch = '.';

    int occurrences = charCounter(myStr, ch);

    printf("%d", occurrences);

    free(myStr);
    return 0;
}

int charCounter(char str[], char ch)
{
    int counter = 0;
    char *pt_ch = strchr(str, ch);
    
    while (pt_ch != NULL)
    {
        counter++;
        pt_ch = strchr(pt_ch + 1, ch);
    }
    
    return counter;
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

