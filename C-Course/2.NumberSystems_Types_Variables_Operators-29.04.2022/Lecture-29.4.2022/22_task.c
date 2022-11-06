#include <stdio.h>

int main(){

    int number;

    do
    {
        printf("Enter 3 digit number: ");
        scanf("%d", &number);
    } while ( number < 100 || number > 1000);
    
    char a = number % 10;
    char b = (number / 10) % 10;
    char c = (number / 100) % 10;
    char count = 0;

    if (a == b && a == c && b == c)
    {
        count = 3;
    }
    else if (b == c || a == b || a == c)
    {
        count = 2;
    }
    
    printf("Result = %d \n", count);

    return 0;
}