// Задача 12. Напишете програма, която да обръща всички символи в
// текстов файл. Запишете резултата в друг временен файл. След това
// преименувайте новия файл с името на оригиналния файл и изтрийте
// временното име. Отпечатайте съдържанието на резултатния файл на
// стандартния изход с главни букви.

#include <stdio.h>

int main()
{
    FILE *fptr = NULL;
    FILE *Sfptr = NULL;
    char ch = 0;

    fptr = fopen("8.task.txt", "r");
    Sfptr = fopen("12.out.txt", "w");

    if (fptr == NULL || Sfptr == NULL)
    {
        printf("Cannot open file!");
        return 1;
    }

    fseek(fptr, -sizeof(char), SEEK_END);
    
    while (ftell(fptr) > 0)
    {
        ch = fgetc(fptr);
        fputc(ch, Sfptr);
        fseek(fptr, -2*sizeof(char), SEEK_CUR);
    }

    ch = fgetc(fptr);
    fputc(ch, Sfptr);
    
    fclose(fptr);
    fclose(Sfptr);

    return 0;
}