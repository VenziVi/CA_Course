#include <stdio.h>

int main(){

    int number = 0;

    do
    {
        printf("Enter 3 digit number: ");
        scanf("%d", &number);
    } while ( number < 100 || number > 1000);
    
    int c = number % 10;
    int b = (number / 10) % 10;
    int a = (number / 100) % 10;

    int min = 1;

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

    printf("result = %d \n", min);

    return 0;
}