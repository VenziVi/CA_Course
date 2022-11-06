// 4) Напишете програма на C, за да проверите дали даден низ е палиндром или не, без да
// използвате цикъл.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * getString(void);
bool palendromeCheck(char str[], int len);
bool isEmpty(char str[]);

int main()
{
    char *myStr = getString();
    bool isPalendrome = false;
    int len = strlen(myStr);

    if (len == 0 || isEmpty(myStr))
    {
        printf("String is empty!");
        return -1;
    }
    else if (len == 1)
    {
        isPalendrome = true;
    }
    else
    {
        isPalendrome = palendromeCheck(myStr, len);
    }

    if (isPalendrome)
    {
        printf("%s is palendrome.", myStr);
    }
    else
    {
        printf("%s is NOT palendrome.", myStr);
    }
    
    free(myStr);

    return 0;
}

//copies the string, reverse the new string and compare it with original one
bool palendromeCheck(char str[], int len)
{
    char reversedStr[len + 1];
    strcpy(reversedStr, str);
    strrev(reversedStr);

    if (strcmp(reversedStr, str) == 0)
    {
        return true;
    }

    return false;
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
