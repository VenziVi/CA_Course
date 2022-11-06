#include <stdio.h>

int main(){

    unsigned short int number = 0;

    do
    {
        printf("Enter 3 digit number: ");
        scanf("%d", &number);
    } while ( number < 100 || number > 1000);
    
    char a = (number / 10) % 10;
    char b = (number / 100) % 10;

    char side = (a <= b) ? b : a;

    printf("Result = %d \n", side * side);
    
    return 0;
}