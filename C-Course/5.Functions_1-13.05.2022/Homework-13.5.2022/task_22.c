//22. Да се напише функция, която намира и отпечатва 
//лицето на кръг.

#include <stdio.h>
#include <math.h>
#define PI (3.141593)

void printCircleArea(float radius);

int main()
{
    float r;

    do
    {
        printf("Enter radius of circle: ");
        scanf("%f", &r);
    } while (r <= 0);

    printCircleArea(r);  
}

void printCircleArea(float r)
{
    double s =  PI * pow(r, 2);
    printf("S = %lf", s);
}