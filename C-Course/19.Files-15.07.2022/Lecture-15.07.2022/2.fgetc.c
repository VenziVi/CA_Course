#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 1000

int main()
{
    FILE *fptr = NULL;
    char ch = 0;
    fptr = fopen("data\\file.txt", "r");

    if (fptr == NULL)
    {
        printf("Unable to open");
        return 1;
    }
    
    while ((ch = fgetc(fptr)) != EOF)
    {
        putchar(ch);
    }
    
    fclose(fptr);

    return 0;
}