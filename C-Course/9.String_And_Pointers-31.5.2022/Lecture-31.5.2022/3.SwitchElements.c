#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swapElements(char fStr[], char sStr[]);

int main()
{
    char fStr[5] = "Ivan";
    char sStr[5] = "Gogo";

    swapElements(fStr, sStr);

    printf("First string:  %s \n", fStr);
    printf("Second string: %s", sStr);

    return 0;
}

void swapElements(char fStr[], char sStr[])
{
    char temp = 0;
    size_t size = strlen(fStr);

    for (size_t i = 0; i < size; i++)
    {
        temp = fStr[i];
        fStr[i] = sStr[i];
        sStr[i] = temp;
    }
}