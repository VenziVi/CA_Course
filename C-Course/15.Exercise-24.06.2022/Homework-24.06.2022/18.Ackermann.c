// 18. Функция на Акерман се дефинира чрез две цели стойности M и N,
// както следва:
// Akerman(0, N) = N+1
// Akerman(M, 0) = Akerman(M-1, 1)
// Akerman(M, N) = Akerman(M-1, Akerman(M, N-1))
// Напишете рекурсивна и итеративна функция за изчисляване на
// функцията на Акерман по зададени две стойности за M и N.

#include <stdio.h>

int ackermannRecursion(int M, int N);
int setNumber(char msg[]);

int main(){

    int result = 0;
    int M = setNumber("Enter M number: ");
    int N = setNumber("Enter N number: ");
        
    result = ackermannRecursion(M, N);

    printf("%d \n", result);

    return 0;
}

int ackermannRecursion(int M, int N)
{
    if (M == 0)
    {
        return N + 1;
    }
    else if ((M > 0) && (N == 0))
    {
        return ackermannRecursion(M - 1, 1);
    }
    else if ((M > 0) && (N > 0))
    {
        return ackermannRecursion(M - 1, ackermannRecursion(M, N - 1));
    }
}

int setNumber(char msg[])
{
    int value = 0;

    printf("%s", msg);
    scanf("%d", &value);

    return value;
}