//  Запишете в четири последователни байтове в паметта със стойност
// 0xAA(10101010) и разпечатайте съдържанието на горните байтове, ако типът е: float,
// signed int, unsigned int

#include <stdio.h>

int main()
{
    int num = 0xAABCDA;
    char *ptr = (char *)&num;

    for (int i = 0; i < sizeof(num); i++)
    {
        printf("Address: %p, Value: %02hhX\n", ptr, (unsigned char)*ptr);
        ptr++;
    }

    printf("\n");

    float num1 = 0xAA;
    char *ptr_f = (char *)&num1;

    for (int i = 0; i < sizeof(num1); i++)
    {
        printf("Address: %p, Value: %02hhX\n", ptr_f, (unsigned char)*ptr_f);
        ptr_f++;
    }

    printf("\n");

    unsigned int num2 = 0xAA;
    char *ptr_u = (char *)&num2;

    for (int i = 0; i < sizeof(num2); i++)
    {
        printf("Address: %p, Value: %02hhX\n", ptr_u, (unsigned char)*ptr_u);
        ptr_u++;
    }
    
}
