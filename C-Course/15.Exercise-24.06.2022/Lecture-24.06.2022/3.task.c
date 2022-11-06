#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *getString(void);
char *filterChars(char *str);
char **getWordsFromString(char *str);

int main()
{
    char *str = getString();
    char *newStr = filterChars(str);

    char **words = getWordsFromString(newStr);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%s", words[i]);
        }
        
    }
    
    printf("%s", newStr);

    free(str);
    free(newStr);
}

char **getWordsFromString(char *str)
{
    char **words = (char**)malloc(sizeof(char*) * 10);
    
    for (int i = 0; i < 10; i++)
    {
        words[i] = (char*)malloc(10);
    }

    char *currStr = malloc(10);

    int ind = 0;
    int j = 0;
    int k = 0;
    int firstIndex = -1;
    int secondIndex = -1;

    while (str[ind] != '\0')
    {
        if (isalpha(str[ind]))
        {
            firstIndex = ind;
        }

        while (str[ind] != ' ' && str[ind] != '\0')
        {
            currStr[k] = str[ind];
            ind++;
            k++;
        }
        currStr[k] = '\0';
        strcpy(words[j], currStr);
        printf("%s ", words[j]);

        j++;
        k = 0;
        ind++;
    }
    
    return words;
    
}

char *getString(void)
{
    char *str = malloc(20);
    char c = 0;
    int i = 0;
    printf("Enter string: ");

    while ((c = getchar()) != '\n')
    {
        str[i] = c;
        i ++;
    }
    
    str[i] = '\0';
    return str;
}

char *filterChars(char *str)
{
    int i = 0;
    int j = 0;

    char *newStr = malloc(20);

    while (str[i] != '\0')
    {
        if (isalpha(str[i]) || isspace(str[i]))
        {
            newStr[j] = str[i];
            j++;
        }

        i++;
    }

    newStr[j] = '\0';
    
    return newStr;
}