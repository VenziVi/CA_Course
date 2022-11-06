#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

void readFile(FILE *fptr)
{
    char ch = 0;
    while ((ch = fgetc(fptr)) != EOF)
    {
        putchar(ch);
    }
}

int main()
{
    FILE *fptr = NULL;
    char filePath[100];
    char dataToAppend[BUFFER_SIZE];

    printf("Enter file path: ");
    scanf("%s", filePath);

    fptr = fopen(filePath, "a");

    if (fptr == NULL)
    {
        printf("Cannot open file!");
        return 1;
    }
    printf("Enter something: ");

    fflush(stdin);
    fgets(dataToAppend, BUFFER_SIZE, stdin);

    fputs(dataToAppend, fptr);

    fptr = freopen(filePath, "r", fptr);

    readFile(fptr);

    fclose(fptr);

    return 0;
}
