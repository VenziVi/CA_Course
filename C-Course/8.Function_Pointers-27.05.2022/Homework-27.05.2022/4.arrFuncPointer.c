// Задача 3. Направете масив от указатели към функции по следния начин:
// void add(){...}
// void fun2(){...}
// void fun3(){...}
// void (*func_ptr[3])() = {fun1, fun2, fun3};
// Направете меню, с което да питате потребителя коя от горните функции иска да
// използва – събиране, изваждане, умножение и деление.
// След това попитайте за числата, които да участват в тази операция,
// и извикайте функцията, която да извърши желаната операция.

#include <stdio.h>

void addition(float fNum, float sNum);
void subtraction(float fNum, float sNum);
void multiplying(float fNum, float sNum);
void division(float fNum, float sNum);
void (*func_ptr[4])(float fNum, float sNum) = {addition, subtraction, multiplying, division};
int setFunction(char operator);
char setOperator(void);
float setValue(char *str);

int main()
{
    char operator = setOperator();
    float fNum = setValue("Enter first number: ");
    float sNum = setValue("Enter second number: ");
    int index = -1;

    index = setFunction(operator);

    if (index >= 0 && index < 4)
    {
        (func_ptr[index])(fNum, sNum);
    }
    else
    {
        printf("Invalid operatiron");
    }
}

int setFunction(char operator)
{
    switch (operator)
    {
    case '+':
        return 0;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 3;
        break;
    
    default:
        return -1;
        break;
    }
}

float setValue(char *str)
{
    int num = 0;

    printf("%s", str);
    scanf("%d", &num);

    return num;
}

char setOperator(void){
    char op = 0;

    printf("Enter operator(\'+\', \'-\', \'*\', \'/\',): ");
    scanf("%c", &op);

    return op;
}

void addition(float fNum, float sNum)
{
    printf("Result = %.2f \n", (fNum + sNum));
}

void subtraction(float fNum, float sNum)
{
    printf("Result = %.2f \n", (fNum - sNum));
}

void multiplying(float fNum, float sNum)
{
    printf("Result = %.2f \n", (fNum * sNum));
}

void division(float fNum, float sNum)
{
    printf("Result = %.2f \n", (fNum / sNum));
}