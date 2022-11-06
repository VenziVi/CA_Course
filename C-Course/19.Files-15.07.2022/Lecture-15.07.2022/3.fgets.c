#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 1000

int main()
{
    FILE *fptr = NULL;
    char buffer[DATA_SIZE];

    int totalRead = 0;
    fptr = fopen("data\\file.txt", "r");

    if (fptr == NULL)
    {
        printf("Unable to open");
        return 1;
    }
    
    while (fgets(buffer, DATA_SIZE, fptr) != NULL)
    {
        
    }
    
    fclose(fptr);

    return 0;
}