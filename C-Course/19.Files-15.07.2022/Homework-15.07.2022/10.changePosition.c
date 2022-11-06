// Задача 10. Изместете позицията си във файла 7 байта след
// началото, ползвайки fseek.
// int fseek(FILE *pfile, long offset, int original);

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr = NULL;

    fptr = fopen("8.task.txt", "r");

    if (fptr == NULL)
    {
        printf("Cannot open file!");
        return 1;
    }

    printf("%ld\n", ftell(fptr));

    fseek(fptr, 7, SEEK_CUR);

    printf("%ld\n", ftell(fptr));

    fclose(fptr);

    return 0;
}