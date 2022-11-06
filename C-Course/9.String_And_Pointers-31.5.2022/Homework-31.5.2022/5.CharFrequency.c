// 5) Напишете C програма за намиране на символа с най-висока честота в низ с помощта на
// цикъл

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * getString(void);
char mostCommon(char str[]);
bool isEmpty(char str[]);

int main()
{
    char *myStr = getString();
    char result = 0;

    if (isEmpty(myStr))
    {
        printf("String is empty!");
        return -1;
    }

    if (strlen(myStr) == 1)
    {  
        printf("Most common char is: %s", myStr);
        return 0;
    }
    
    result = mostCommon(myStr);
    printf("Most common char is: %c", result);

    free(myStr);

    return 0;
}

//Returns most common char in string
char mostCommon(char str[])
{
    int len = strlen(str);
    char mostCommonChar = 0;
    int maxCount = 0;
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        count = 0;
        for (int j = 0; j < len; j++)
        {
            if (str[i] == str[j])
            {
                count ++;
            }
        }

        if (maxCount < count)
        {
            maxCount = count;
            mostCommonChar = str[i];
        }
    }
    
    return mostCommonChar;
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
