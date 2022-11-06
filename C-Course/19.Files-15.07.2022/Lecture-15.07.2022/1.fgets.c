#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 1000

int main()
{
    char data[DATA_SIZE];

    FILE *fptr = NULL;

    fptr = fopen("data/file.txt", "w");

    if (fptr == NULL)
    {
        printf("Cannot open file!");
        return 1;
    }
    
    printf("Enter content: ");
    fgets(data, DATA_SIZE, stdin);

    fputs(data, fptr);

    fclose(fptr);

    printf("File created and saved. \n");
    return 0;
}