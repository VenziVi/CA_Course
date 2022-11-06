//8) Напишете C програма за премахване на допълнителните интервали и празни места от низ.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * getString(void);
void removeWhitespaces(char str[]);
void clearDuplicatedWhitespaces(char str[]);
bool isEmpty(char str[]);

int main()
{
    char *myStr = getString();

    if (isEmpty(myStr))
    {
        printf("String is empty!");
        return -1;
    }

    removeWhitespaces(myStr);
    clearDuplicatedWhitespaces(myStr);

    int len = strlen(myStr);
    
    printf("String:|%s| \n", myStr);
    printf("String length: %d", len);

    free(myStr);

    return 0;
}

//Removes duplicate whitespaces in the string
void clearDuplicatedWhitespaces(char str[])
{
    int len = strlen(str);

    for (int i = 0; i < len;)
    {
        if (isspace(str[i]) && isspace(str[i + 1]))
        {
            for (int k = i; k < len; k++)
            {
                str[k] = str[k + 1];
            }

            len--;
        }
        else
        {
            i++;
        }
    }
}

//Removes whitespaces at the beginning and end of the string
void removeWhitespaces(char str[])
{
    int len = strlen(str);

    for (int i = 0; isspace(str[i]);)
    {   
        if (isspace(str[i]))
        {
            for (int k = i; k < len; k++)
            {
                str[k] = str[k + 1];
            }

            len--;
        }
        else
        {
            i++;
        }
    }

    for (int i = len - 2; isspace(str[i]); i--)
    {   
        if (isspace(str[i]))
        {   
            str[i] = '\0';
            str[i + 1] = 0;
        }
    }
}

//Read and set the string dynamically
char * getString(void)
{
    size_t size = 20;
    char *inputStr = malloc(size);
    size_t length = 0;
    char ch;

    printf("Enter string: ");

    while ((ch = getchar()) != '\n')
    {   
        if (length >= size - 1)
        {
            inputStr = realloc(inputStr, size * 2);
            size *= 2;
        }
        
        inputStr[length++] = ch;
    }

    inputStr[length] = '\0';
    return inputStr;
}

//Checks if string is from whitespaces only
bool isEmpty(char str[])
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (!isspace(str[i]))
        {
            return false;
        }

        i++;
    }
    
    return true;
}
