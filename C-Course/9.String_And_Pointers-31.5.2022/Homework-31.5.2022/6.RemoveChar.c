// 6) Напишете C програма за премахване на всички повтарящи се символи в низ с помощта на
// цикли.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * getString(void);
void removeDuplicates(char str[]);
bool isEmpty(char str[]);

int main()
{
    char *myStr = getString();

    if (isEmpty(myStr))
    {
        printf("String is empty!");
        return -1;
    }

    if (strlen(myStr) == 1)
    {  
        printf("Reslt: %s", myStr);
        return 0;
    }

    removeDuplicates(myStr);
    
    printf("Result: %s", myStr);

    free(myStr);

    return 0;
}

//Remove duplicate characters in the string
void removeDuplicates(char str[])
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {   
        for (int j = i + 1; j < len;)
        {   
            if (str[i] == str[j])
            {
                for (int k = j; k < len; k++)
                {
                    str[k] = str[k + 1];
                }

                len--;
            }
            else
            {
                j++;
            }
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
