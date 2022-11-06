// Задача 9. Направете същото ползвайки fgetpos().
// int fgetpos(FILE *pfile, fpos_t *position);

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr = NULL;
    fpos_t position;
    char   buffer[20];

    fptr = fopen("8.task.txt", "r");

    if (fptr == NULL)
    {
        printf("Cannot open file!");
        return 1;
    }

    fgetpos(fptr, &position);
    printf("%zu\n", position);

    fread(buffer, sizeof(char), 8, fptr);

    fgetpos(fptr, &position);
    printf("%zu\n", position);
    
    fclose(fptr);

    return 0;
}