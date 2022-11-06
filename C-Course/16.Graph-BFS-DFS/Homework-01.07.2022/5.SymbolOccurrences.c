#include <stdio.h>
#include <string.h>

void countOccurrences(char str[], char symbol, size_t *occurrences);

int main()
{
    char str[] = "a#AD dad$#fs fd#Vs";
    char symbol = '#';
    size_t occurrences = 0;

    countOccurrences(str, symbol, &occurrences);

    printf("%c --> %lu ", symbol, (unsigned long)occurrences);

    return 0;    
}

void countOccurrences(char str[], char symbol, size_t *occurrences)
{
    char* ptr = strchr(str, symbol);

    while (ptr != NULL)
    {
        ptr++;
        (*occurrences)++;
        ptr = strchr(ptr, symbol);
    }
}