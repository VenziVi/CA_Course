// Задача 4. Домашно
// Напишете програма, която чете текстов файл с думи и отпечатва тези
// от тях, които са палиндроми – четени отпред-назад и обратно са
// еднакви.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalendrom(char str[])
{
    int length = strlen(str);
    int i = length - 1;
    int j = 0;

    if (length == 1)
    {
        return true;
    }

    while (i >= (length / 2))
    {
        if (str[i] != str[j])
        {
            return false;
        }

        i--; j++;
    }

    return true;
}

int main()
{
    FILE *fptr;
    fptr = fopen("words.txt","r");

    if(fptr == NULL)
    {
      printf("Cannot open file!");
      return 1;
    }

    char word[20] = {0};

    while (fscanf(fptr, "%s", word) > 0)
    {
        if(isPalendrom(word))
        {
            printf("%s \n", word);
        }
    }
   
    fclose(fptr);

    return 0;
}
