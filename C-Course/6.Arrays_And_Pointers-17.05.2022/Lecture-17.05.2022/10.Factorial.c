// 10. Напишете програма, която да изчисли факториeл на дадено число,
// използвайки указатели.

#include <stdio.h>

int fact(int *num);

int main()
{
    int num = 0;
    int *p_num = &num;

    printf("Enter number: ");
    scanf("%d", p_num);

    printf("Factorial = %d", fact(p_num));
    return 0;
}

int fact(int *num)
{
    int fact = 1;

    for (int i = 1; i <= *num; i++)
    {
        fact *= i;
    }
    
    return fact;
}