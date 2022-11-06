#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    unsigned int number;
    int year;

    do
    {
        printf("Enter 6 digit number: ");
        scanf("%d", &number);
    } while ( number < 100000 || number > 1000000);

    // int a, b, c, d;
    // a = (number / 100000) % 10;
    // b = (number / 1000) % 10;
    // c = (number / 10) % 10;
    // d = number % 10;

    // year = (a * 1000) + (b * 100) + (c * 10) + d;

    char str[7];
    char newStr[5];
    char j = 0;
    sprintf(str, "%d", number);

    for (char i = 0; i < strlen(str); i++)
    {
        if (i == 0 || i == 2 || i == 4 || i == 5)
        {
            newStr[j] = str[i];
            j++;
        }
    }
    
    year = atoi(newStr);

    if ((year % 4 == 0 &&
        year % 100 != 0) ||
        year % 400 == 0)
    {
        printf("Year %d is a leap-year \n", year);
    }
    else
    {
        printf("Year %d is not a leap-year \n", year);
    }
     
    return 0;
}