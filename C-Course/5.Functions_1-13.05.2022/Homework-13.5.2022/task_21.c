// 21. Да се напише функция, която намира и връща лицето на
// правоъгълник.

#include <stdio.h>

float findRectangleArea(float sideA, float sideB);

int main()
{
    float a, b;
  
    do
    {
        printf("Enter size of side a: ");
        scanf("%f", &a);
    } while (a <= 0);

    do
    {
        printf("Enter size of side b: ");
        scanf("%f", &b);
    } while (b <= 0);
    

    printf("S = %f", findRectangleArea(a, b));
}

float findRectangleArea(float a, float b)
{
    return (a * b);
}