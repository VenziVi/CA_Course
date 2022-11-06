#include <stdio.h>
#include <string.h>
#include <ctype.h>

size_t countWords(char *str);

int main()
{
    char str[] = "abra kad a bra";
    size_t wordsCount = countWords(str);

    printf("%lu ", (unsigned long)wordsCount);
}

size_t countWords(char *str)
{
    size_t wordCount = 0;
    size_t len = strlen(str);
    size_t lettersCount = 0;

    for (size_t i = 0; i < len; i++)
    {
        if (isalpha(str[i]))
        {
            lettersCount++;
        }

        if(isspace(str[i]) || i == len - 1)
        {
            if (lettersCount > 2)
            {
                wordCount++;
                lettersCount = 0;
            }
        }
    }
    
    return wordCount;
}