#include <stdio.h>

int main()
{
    int n = 1234, num, bull = 0, cow = 0, x, y, f, z;

    int a = n % 10,
        b = (n / 10) % 10,
        c = (n / 100) % 10,
        d = (n / 1000) % 10;

    do
    {
        printf("Enter number: ");
        scanf("%d", &num);

        x = num % 10;
        y = (num / 10) % 10;
        f = (num / 100) % 10;
        z = (num / 1000) % 10;

        if (a == x)
            cow++;
        else if (a == y || a == f || a == z)
            bull++;

        if (b == y)
            cow++;
        else if (b == x || b == f || b == z)
            bull++;

        if (c == f)
            cow++;
        else if (c == y || c == x || c == z)
            bull++;

        if (d == z)
            cow++;
        else if (d == y || d == f || d == x)
            bull++;

        printf("bull = %d \n", bull);
        printf("cow = %d \n", cow);

    } while (num != n);

    printf("Yess, number is: %d", n);
}