// Задача 1. Направете две функции и извикайте желаната функция с указател към функция, съобразно
// знака, подаден от командния ред:
// Пример: а.exe 20 + 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fnPlus(int nA, int nB);
int fnMinus(int nA, int nB);
int fnMulti(int nA, int nB);
int fnDiv(int nA, int nB);
int (*pfCalc) (int, int) = NULL;
void setFunction(char operator);

int main(int argc, char *argv[])
{
    int numA = 0;
    int numB = 0;
    char operator = 0;

    if (argc == 4)
    {
        sscanf(argv[1], "%d", &numA);
        sscanf(argv[3], "%d", &numB);
        sscanf(argv[2], "%c", &operator);
    }
    else
    {
        printf("INVALID INPUT.");
        return 1;
    }

    setFunction(operator);

    if (pfCalc != NULL)
    {
        printf("Result = %d", (*pfCalc)(numA, numB));
    }

    return 0;
}

void setFunction(char operator)
{
    switch (operator)
    {
    case '+':
        pfCalc = fnPlus;
        break;
    case '-':
        pfCalc = fnMinus;
        break;
    case 'x':
        pfCalc = fnMulti;
        break;
    case '/':
        pfCalc = fnDiv;
        break;
    
    default:
        printf("INVALID OPERATION.");
        break;
    }
}

int fnPlus(int nA, int nB)
{
    return  (nA + nB);
}

int fnMinus(int nA, int nB)
{
    return  (nA - nB);
}

int fnMulti(int nA, int nB)
{
    return  (nA * nB);
}

int fnDiv(int nA, int nB)
{
    return  (nA / nB);
}