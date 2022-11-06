#include <stdio.h>

int main(){

    int number;

    do
    {
        printf("Enter 3 digit number: ");
        scanf("%d", &number);
    } while ( number < 100 || number > 1000);
    
    char c = number % 10;
    char b = (number / 10) % 10;
    char a = (number / 100) % 10;

    char min = 1;

    if(b < a)
    {
        min = 2;
        a = b;
    }
    if(c < a)
    {
        min = 3;
        a = c;
    }

    printf("Result = %d \n", min);

    return 0;
}