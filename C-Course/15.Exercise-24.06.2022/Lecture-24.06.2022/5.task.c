#include "stack.h"

float calc(int a, int b, char op)
{
    if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }
    else if (op == '*')
    {
        return a - b;
    }
    else if (op == '/')
    {
        return a * 1. / b;
    }
    else
    {
        return 0;
    }
}

int main()
{
    stack numbers = NULL;
    stack operators = NULL;

    char *str = malloc(50);
    scanf("%s", str);

    int i = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        int n = 0;
        while (str[i] != '\0' && str[i] > '0' && str[i] <= '9')
        {
            n = n * 10 + str[i] - '0';
            i++;
        }

        push(&numbers, n);
        push(&operators, str[i]);
    }

    int b = pop(&numbers);
    int a = pop(&numbers);
    int op = pop(&operators);
    char op2 = pop(&operators);
    
    printf("%d %d %c", a, b, op2);
}