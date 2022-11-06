#include <stdio.h>

int main(){

    unsigned short int number = 0;

    do
    {
        printf("Enter 3 digit number: ");
        scanf("%d", &number);
    } while ( number < 100 || number > 1000);
    
    char a = number % 10;
    char b = (number / 100) % 10;

    if (a == 0 || b == 0)
    {
        printf("One of sides is zero!");
    }
    else
    {
        printf("Result = %d \n", a * b);
    }
    
    return 0;
}