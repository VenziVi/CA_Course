// Задача 14. Напишете програма, която премахва ред с определен
// номер от зададен файл. Реда, който трябва да се премахне да бъде
// въведен от потребителя. Принтирайте началния и резултатния
// файлове.

#include <stdio.h>

int main()
{
    int line = 0;
    printf("Enter number of line: ");
    scanf("%d", &line);

    int linesCount = 1;
    FILE *fptr = NULL;
    FILE *Sfptr = NULL;
    char ch = 0;

    fptr = fopen("8.task.txt", "r");
    Sfptr = fopen("14.out.txt", "w");

    if (fptr == NULL || Sfptr == NULL)
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

        if (linesCount != line)
        {
            fputc(ch, Sfptr);
        }
    }
    
    fclose(fptr);
    fclose(Sfptr);

    return 0;
}