#include <stdio.h>

int main(){

    int number = 0;

    do
    {
        printf("Enter 3 digit number: ");
        scanf("%d", &number);
    } while ( number < 100 || number > 1000);
    
    int a = number % 10;
    int b = (number / 100) % 10;

    int result = a * b;

    printf("result = %d \n", result);

    return 0;
}