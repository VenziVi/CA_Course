#include <stdio.h>

int main(){

    char n;

    printf("Insert char: ");
    scanf("%c", &n);

    if (n >= 65 && n < 91)
        printf("Uppercase");
    else if (n >= 97 && n < 123)
        printf("Lowercase");
    else
        printf("Not a letter");

}