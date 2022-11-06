// Задача 16. Напишете стандартната програма за Linux cat , която приема
// като аргументи от командния ред имена на файлове и изкарва
// съдържанието им на стандартния изход. Ако на програмата не са
// подадени никакви аргументи, то тя да изкара съдържанието подадено от
// стандартния вход на стандартния изход.


#include <stdio.h>

void printFile(FILE *fptr)
{
    char ch = 0;

    if (fptr == NULL)
    {
        printf("Cannot open file!");
    }
     else
    {
        while ((ch = fgetc(fptr)) != EOF)
        {
            printf("%c", ch);
        }
    }
}

void readFiles(char* argv[], int count)
{
    FILE *fptr = NULL;

    for (int i = 1; i < count; i++)
    {
        printf("---File %d content: \n", i);

        fptr = fopen(argv[i], "r");

        printFile(fptr);

        fclose(fptr);
        printf("\n");
    }
}

void readInput(void)
{
    char path[260];
    printf("Enter file path: ");
    scanf("%s", path);

    FILE *fptr = NULL;

    fptr = fopen(path, "r");

    printFile(fptr);

    fclose(fptr);
    printf("\n");
}

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        readFiles(argv, argc);
    }
    else
    {
        readInput();
    }

    return 0;
}