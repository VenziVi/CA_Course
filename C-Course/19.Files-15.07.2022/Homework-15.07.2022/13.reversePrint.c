// Задача 13. Напишете програма, която печата съдържанието на файл
// в обратен ред.Използвайте fseek, за да отидете накрая на файла.
// Използвайте ftell функцията, за да намерите позицията на указателя
// във файла. Принтирайте на екрана файла, обърнат в обратен ред.

#include <stdio.h>

int main()
{
    FILE *fptr;
    char ch = 0;

    fptr = fopen("8.task.txt", "r");

    if (fptr == NULL)
    {
        printf("Cannot open file!");
        return 1;
    }

    fseek(fptr, -sizeof(char), SEEK_END);
    
    while (ftell(fptr) > 0)
    {
        ch = fgetc(fptr);
        printf("%c", ch);
        fseek(fptr, -2*sizeof(char), SEEK_CUR);
    }

    ch = fgetc(fptr);
    printf("%c \n", ch);
    
    fclose(fptr);

    return 0;
}