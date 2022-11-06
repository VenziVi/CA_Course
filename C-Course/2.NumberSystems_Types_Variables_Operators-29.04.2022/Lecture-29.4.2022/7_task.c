#include <stdio.h>

int main(){

    char c, d;

    printf("Enter charcters: ");

    scanf("%c", &c);
    scanf(" %c", &d);
    printf("%c, %c\n",c, d);

    return 0;
}