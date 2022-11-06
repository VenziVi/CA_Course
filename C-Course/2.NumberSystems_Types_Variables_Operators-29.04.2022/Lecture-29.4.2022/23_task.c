#include <stdio.h>

int main(){

    int number;

    do
    {
        printf("Enter 4 digit number: ");
        scanf("%d", &number);
    } while ( number < 1000 || number > 10000);
    
    char count = 0;
    char currNum;
    int del = 1;

    for (char i = 0; i < 4; i++)
    {
        currNum = ((number / del) % 10);

        if (currNum != 0)
        {
           count++;
        }

        del *= 10;
    }

    printf("Result = %d \n", count);

    return 0;
}