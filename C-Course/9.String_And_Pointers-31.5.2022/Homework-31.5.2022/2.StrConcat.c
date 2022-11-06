// 2) Напишете C програма за свързване на два низа в един низ, без да използвате библиотечна
// функция strcat().

#include <stdio.h>
#include <stdlib.h>

char * getString(void);
int findLen(char str[]);
char * concatStr(char firstStr[], int fLen, char secondStr[], int sLen);

int main()
{
    char *firstStr = getString();
    char *secondStr = getString();

    int firstStrLen = findLen(firstStr);
    int secondStrLen = findLen(secondStr);

    if (firstStrLen == 0 && secondStrLen == 0)
    {
        printf("Both strings are empty!");
        return -1;
    }
    else if (firstStrLen == 0)
    {
        printf("Concatenated string: %s \n", secondStr);
        return 0;
    }
    else if (secondStrLen == 0)
    {
        printf("Concatenated string: %s \n", firstStr);
        return 0;
    }

    char *resultStr = concatStr(firstStr, firstStrLen, secondStr, secondStrLen);

    printf("Concatenated string: %s \n", resultStr);

    free(firstStr);
    free(secondStr);

    return 0;
}

//concatenate two strings
char * concatStr(char firstStr[], int fLen, char secondStr[], int sLen)
{
    char *resultStr = malloc(fLen + sLen + 1);
    int i = 0;

    for (i = 0; i < fLen; i++)
    {
        resultStr[i] = firstStr[i];
    }
    
    for (int j = 0; j < sLen; j++, i++)
    {
        resultStr[i] = secondStr[j];
    }
    
    resultStr[i + 1] = '\0';

    return resultStr;
    free(resultStr);
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