#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

char * getString(void);
bool isExists(char str[], char element);

int main()
{
    char *myStr = getString();
    char element = 0;
    printf("Enter searched element: ");
    scanf("%c", &element);

    if (isExists(myStr, element))
    {
        printf("String %s contains element %c.", myStr, element);
    }
    else
    {
        printf("String %s does't contains element %c.", myStr, element);
    }

    free(myStr);
    return 0;
}

bool isExists(char str[], char element)
{
    size_t size = strlen(str);

    for (size_t i = 0; i < size; i++)
    {
        if (str[i] == element)
        {
            return true;
        }
    }
    
    return false;
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

