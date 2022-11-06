// Запишете в осем последователни байта в паметта със стойност
// 0xBB(1011 1011) и разпечатайте съдържанието на горните байтове, ако типът е:
// double, signed long long, unsigned long long

#include <stdio.h>

int main()
{
    double num = 0xBB;
    char *ptr = (char *)&num;

    for (int i = 0; i < sizeof(num); i++)
    {
        printf("Address: %p, Value: %02hhX \n", ptr, (unsigned char)*ptr);
        ptr++;
    }

    printf("\n");

    long long int num1 = 0xBB;
    char *ptr_i = (char *)&num1;

    for (int i = 0; i < sizeof(num1); i++)
    {
        printf("Address: %p, Value: %02hhX \n", ptr_i, (unsigned char)*ptr_i);
        ptr_i++;
    }

    printf("\n");

    unsigned long long int num2 = 0xBB;
    char *ptr_u = (char *)&num2;

    for (int i = 0; i < sizeof(num2); i++)
    {
        printf("Address: %p, Value: %02hhX \n", ptr_u, (unsigned char)*ptr_u);
        ptr_u++;
    }
}