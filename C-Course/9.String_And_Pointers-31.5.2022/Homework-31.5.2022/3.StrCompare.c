// 3) Напишете C програма за сравняване на два низа, използвайки цикъл символ по символ, без
// да използвате вградена библиотечна функция strcmp()

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


char * getString(void);
int findLen(char str[]);
bool isEmpty(char str[]);
bool areEqual(char firstStr[], char secondStr[]);

int main()
{
    char *firstStr = getString();
    char *secondStr = getString();
    char result = 0;

    if (isEmpty(firstStr) && isEmpty(secondStr))
    {
        printf("Both strings are empty!");
        return -1;
    }
    else if (isEmpty(firstStr) || isEmpty(secondStr))
    {
        printf("One of the strings is empty!");
        return -1;
    }

    result = (areEqual(firstStr, secondStr)) ? '=' : '!';

    printf("%s %c= %s", firstStr, result, secondStr);

    free(firstStr);
    free(secondStr);
    
    return 0;
}

//Compares two strings, first by length, than char with char
bool areEqual(char firstStr[], char secondStr[])
{
    int lenFirstStr = findLen(firstStr);
    int lenSecondStr = findLen(secondStr);

    if (lenFirstStr == lenSecondStr)
    {
        for (int i = 0; i < lenFirstStr; i++)
        {
            if (firstStr[i] != secondStr[i])
            {
                return false;
            }
        }

        return true;
    }
    
    return false;
}

//Counting the length of the string
int findLen(char str[])
{
    int result = 0;

    for (int i = 0; (str[i] != '\0'); i++)
    {  
        result++;
    }
    
    return result;
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
