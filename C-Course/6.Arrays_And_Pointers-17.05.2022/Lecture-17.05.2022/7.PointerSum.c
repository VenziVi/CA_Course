//7. Напишете програма, която събира две числа, използвайки указатели.

#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    int *p_a = &a;
    int *p_b = &b;

    printf("Enter number a: ");
    scanf("%d", p_a);

    printf("Enter number b: ");
    scanf("%d", p_b);

    int sum = 0;

    sum = *p_a + *p_b;

    printf("Sum = %d", sum);
}