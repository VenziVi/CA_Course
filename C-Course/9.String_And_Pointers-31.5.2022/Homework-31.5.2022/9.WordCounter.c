//9) Напишете C програма за броене на срещания на дума в даден низ с помощта на цикъл.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * getString(char message[]);
bool isEmpty(char str[]);
int findOccurrence(char mainStr[], char word[]);

int main()
{
    char *mainStr = getString("Enter string: ");
    char *word = getString("Enter searched word: ");
    int occurrenceCount = 0;

    if (isEmpty(mainStr))
    {
        printf("String is empty!");
        return -1;
    }

    if (isEmpty(word))
    {
        printf("Searched string is empty!");
        return -1;
    }

    occurrenceCount = findOccurrence(mainStr, word);
    printf("%d", occurrenceCount);

    free(mainStr);
    free(word);

    return 0;
}

//Return the number of occurrences of a word in a string
int findOccurrence(char mainStr[], char word[])
{
    int mainLen = strlen(mainStr);
    int wordLen = strlen(word);
    bool isMatch = true;
    int count = 0;
    int index = 0;

    for (int i = 0; i < mainLen; i++)
    {
        isMatch = true;
        if (mainStr[i] == word[0] && (i == 0 || isspace(mainStr[i - 1])))
        {
            index = i + 1;

            for (int j = 1; j < wordLen; j++)
            {
                if (word[j] != mainStr[index++])
                {
                    isMatch = false;
                    break;
                }
            }
            
            if (isMatch && (isspace(mainStr[i + wordLen]) || mainStr[i + wordLen] == '\0'))
            {
                count++;
            }
        }
    }
    
    return count;
}

//Read and set the string dynamically
char * getString(char message[])
{
    size_t size = 20;
    char *inputStr = malloc(size);
    size_t length = 0;
    char ch;

    printf("%s", message);

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
