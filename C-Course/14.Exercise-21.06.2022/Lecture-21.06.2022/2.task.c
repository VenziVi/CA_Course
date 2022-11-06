#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *countChars(char *str)
{
    char *arr = malloc(30);

    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        arr[str[i] - 97]++;
    }
    
    return arr;
}

int main()
{
    char str[10];
    char *arr = NULL;
    printf("Enter string: ");
    scanf("%s", &str);

    printf("%s \n", str);

    arr = countChars(str);

    for (int i = 0; i < 30; i++)
    {
        printf("%d \n", arr[i]);
    }
    
}