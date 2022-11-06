#include <stdio.h>

int main(){

    unsigned int number;
    scanf("%d", &number);

    unsigned short int result = 0;

    unsigned char firstDigit, secondDigit, thirdDigit, fourthDigit;

    firstDigit = number % 10;
    secondDigit = (number / 10) % 10;
    thirdDigit = (number / 100) % 10;
    fourthDigit = (number / 1000) % 10;

    result = firstDigit + secondDigit + thirdDigit+ fourthDigit;

    printf("%d", result);

    return 0;
}