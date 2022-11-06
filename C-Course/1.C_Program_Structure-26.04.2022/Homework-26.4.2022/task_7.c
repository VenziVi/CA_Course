#include <stdio.h>

int main(){

    int number;

do
{
    printf("Enter number: ");
    scanf("%d", &number);

} while (number < 2 || number >= 12);

    printf("Your number is between 2 and 12.");

    return 0;
}