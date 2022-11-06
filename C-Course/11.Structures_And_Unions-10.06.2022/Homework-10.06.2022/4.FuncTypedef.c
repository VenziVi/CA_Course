// Задача 4. Дефинирайте тип указател към функция, която изпълнява определена
// операция върху две целочислени променливи. Дефинирайте функции, които
// изпълняват операциите +, -, *, /. Използвайте новия тип, за да извикате всяка една
// от функциите.

#include <stdio.h>

typedef int (*calc)(int a, int b);

int addition(int nA, int nB);
int subtraction(int nA, int nB);
int multiplication(int nA, int nB);
int division(int nA, int nB);
calc setFunction(char operator);

int main()
{
    int a = 35;
    int b = 5;
    char operators[5] = {'*', '/', '#', '+', '-'};

    for (int i = 0; i < 5; i++)
    {
        calc func = setFunction(operators[i]);

        if (func == NULL)
        {
            printf("INVALID OPERATOR! \n");
        }
        else
        {
            printf("%d %c %d = %d \n", a, operators[i], b, func(a, b));
        }
    }
    
    return 0;
}

calc setFunction(char operator)
{
    switch (operator)
    {
    case '/':
        return division;
    case '+':
        return addition;
    case '-':
        return subtraction;
    case '*':
        return multiplication;
        break;
    
    default:
        return NULL;
        break;
    }
}


int addition(int nA, int nB)
{
    return  (nA + nB);
}

int subtraction(int nA, int nB)
{
    return  (nA - nB);
}

int multiplication(int nA, int nB)
{
    return  (nA * nB);
}

int division(int nA, int nB)
{
    return  (nA / nB);
}