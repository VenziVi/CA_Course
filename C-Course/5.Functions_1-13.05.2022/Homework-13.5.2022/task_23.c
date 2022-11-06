// 23. Да се напише функция с име isTriangle, която по дадени три цели
// числа определя дали съществува триъгълник със страни тези числа.

#include <stdio.h>
#include <stdbool.h>

bool isTriangle(int sideA, int sideB, int sideC);

int main()
{
    int a, b, c;

    printf("Enter size of side a: ");
    scanf("%d", &a);
    printf("Enter size of side b: ");
    scanf("%d", &b);
    printf("Enter size of side c: ");
    scanf("%d", &c);

    (isTriangle(a, b, c)) ? 
        printf("Triangle.") :
        printf("NOT a triangle.");
}

bool isTriangle(int a, int b, int c)
{
    if (a < (b + c) && b < (a + c) && c < (a + b))
    {
        return true;
    }

    return false;
}
