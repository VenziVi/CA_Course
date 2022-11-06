// Задача 1. Да се напише програма, която създава калкулатор с оператор switch

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

    switch (operator)
    {
    case '+': printf("Result = %.2f", num1 + num2); break;
    case '-': printf("Result = %.2f", num1 - num2); break;
    case '/': printf("Result = %.2f", num1 / num2); break;
    case '*': printf("Result = %.2f", num1 * num2); break;
    deafult: printf("Operator must be '+', '-', '*' or '/'");
    }
    
    return 0;
}