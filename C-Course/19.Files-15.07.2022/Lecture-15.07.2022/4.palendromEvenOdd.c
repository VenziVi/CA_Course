#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isprimeNum(int value)
{
    if (value == 0 || value == 1)
    {
        return false;
    }
    
    for (int i = 2; i <= value / 2; i++)
    {
        if (value % i== 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    FILE *fptr = NULL;
    FILE *Pfptr = NULL;
    FILE *Efptr = NULL;
    FILE *Ofptr = NULL;
    fptr = fopen("numbers.txt", "w");

    if (fptr == NULL)
    {
        printf("Cannot open file!");
        return 1;
    }

    for (int i = 0; i < 1000; i++)
    {
        fprintf(fptr, "%d ", i);
    }
    fclose(fptr);

    fptr = fopen("numbers.txt", "r");
    Pfptr = fopen("prime.txt", "w");
    Efptr = fopen("even.txt", "w");
    Ofptr = fopen("odd.txt", "w");
    
    if (fptr == NULL)
    {
        printf("Cannot open file!");
        return 1;
    }
    int value = 0;

    while(fscanf(fptr, "%d", &value) > 0)
    {
        if (isprimeNum(value))
        {
            fprintf(Pfptr, "%d ", value);
        }
        if (value % 2 == 0)
        {
            fprintf(Efptr, "%d ", value);
        }
        else
        {
            fprintf(Ofptr, "%d ", value);
        }
    }

    fclose(fptr);
    fclose(Pfptr);
    fclose(Efptr);
    fclose(Ofptr);

    printf("File created and saved. \n");
    return 0;
}