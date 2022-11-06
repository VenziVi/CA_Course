#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    unsigned int number;

    do
    {
        printf("Enter 6 digit number: ");
        scanf("%d", &number);
    } while ( number < 100000 || number > 1000000);
    
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
    
    int year = atoi(newStr);

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