#include <stdio.h>
#include <ctype.h>

void countCharacters(char str[], size_t *upper, size_t *lower, size_t *symbols);

int main()
{
    char str[] = "adAD dad$&fs fdCVs";
    size_t upper = 0;
    size_t lower = 0;
    size_t symbols = 0;

    countCharacters(str, &upper, &lower, &symbols);

    printf("Upper: %lu, lower: %lu, symbols = %lu ",
        (unsigned long)upper, (unsigned long)lower, (unsigned long)symbols);

    return 0;    
}

void countCharacters(char str[], size_t *upper, size_t *lower, size_t *symbols)
{
    size_t index = 0;

    while (str[index] != '\0')
    {
        if (isupper(str[index]))
        {
            (*upper)++;
        }
        else if (islower(str[index]))
        {
            (*lower)++;
        }
        else if (!isdigit(str[index]) && !isspace(str[index]))
        {
            (*symbols)++;
        }
        
        index++;
    }
}