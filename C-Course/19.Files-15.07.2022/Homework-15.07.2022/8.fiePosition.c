// Задача 8. Намерете позицията си във файла, като използвате:
// long ftell(FILE *pfile);
// Преместете се няколко пъти напред и назад на различни позиции.

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

    fseek(fptr, 13, SEEK_CUR);

    printf("%ld\n", ftell(fptr));

    fseek(fptr, -7, SEEK_CUR);

    printf("%ld\n", ftell(fptr));
    
    fclose(fptr);

    return 0;
}