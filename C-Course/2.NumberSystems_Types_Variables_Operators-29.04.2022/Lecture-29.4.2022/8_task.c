#include <stdio.h>

int main(){

    float num1;
    float num2;
    char operator;

    printf("Enter first value: ");
    scanf("%f", &num1);

    printf("Enter second value: ");
    scanf("%f", &num2);

    printf("Enter operation: ");
    scanf("%s", &operator);

    if (operator == '+')
    {
        printf("%.2f", num1 + num2);
    }
    else if (operator == '-')
    {
        printf("%.2f", num1 - num2);
    }
    else if (operator == '*')
    {
        printf("%.2f", num1 * num2);
    }
    else if (operator == '/')
    {        
        printf("%.2f", num1 / num2);
    }
    else 
    {
        printf("Operator must be '+', '-', '*' or '/'");
    }

    return 0;
}
