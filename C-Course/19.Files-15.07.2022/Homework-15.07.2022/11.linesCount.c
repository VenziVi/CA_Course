// Задача 11. Напишете програма, която да намери общия брой на
// редовете в текстови файл. Създайте файл, който съдържа няколко
// реда текст. Внимавайте къде се позиционирате файла. Отворете
// файла. Използвайте променлива, която да брои броя на редовете.

#include <stdio.h>

int main()
{
    FILE *fptr = NULL;
    size_t linesCount = 1;
    char ch = 0;

    fptr = fopen("8.task.txt", "r");

    if (fptr == NULL)
    {
        printf("Cannot open file!");
        return 1;
    }

    while((ch = fgetc(fptr)) != EOF)
    {
        if (ch == '\n')
        {
            linesCount++;
        }
    }

    printf("%zu\n", linesCount);

    fclose(fptr);

    return 0;
}