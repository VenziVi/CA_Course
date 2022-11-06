#include <stdio.h>

int main(){

    unsigned int number = 0;

    do
    {
        printf("Enter 6 digit number: ");
        scanf("%d", &number);
    } while ( number < 100000 || number > 1000000);

    char x = 0, y = 0;
    char currNum;
    int del = 1;

    for (char i = 0; i < 6; i++)
    {
        currNum = ((number / del) % 10);

        if (currNum % 2 == 0)
        {
            y += currNum;
        }
        else
        {
            x += currNum;
        }

        del *= 10;
    }

    if (x == 0 || y == 0)
    {
        printf("One of the sides is 0.");
    }
    else
    {
        printf("Result = %d \n", x * y);
    }
    
    return 0;
}