#include <stdio.h>

typedef int* intptr;

int main()
{
    int a = 555555;
    intptr ptr = &a;

    printf("%d \n", *ptr);
    printf("%p \n", ptr);
}