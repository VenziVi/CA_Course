#include <stdio.h>

int main(){

    int number = 0;

    do
    {
        printf("Enter 3 digit number: ");
        scanf("%d", &number);
    } while ( number < 100 || number > 1000);
    
    int a = number % 10;
    int b = (number / 10) % 10;
    int c = (number / 100) % 10;
    int count = 0;

    if (a == b && a == c && b == c)
    {
        count = 3;
    }
    else if (b == c || a == b || a == c)
    {
        count = 2;
    }
    
    printf("result = %d \n", count);

    return 0;
}