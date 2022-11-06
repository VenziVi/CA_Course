// Задача 17. Да се напише програма, която чете координатите на една точка
// в равнината и определя в кой квадрант е точката

#include <stdio.h>

int main(){

    int x, y;

    printf("Enter number x: ");
    scanf("%d", &x);
    printf("Enter number y: ");
    scanf("%d", &y);

    if (x > 0)
    {
        if (y > 0)
        {
            printf("Quadrant 1");
        }
        else
        {
            printf("Quadrant 4");
        }
    }
    else 
    {
        if (y > 0)
        {
            printf("Quadrant 2");
        }
        else
        {
            printf("Quadrant 3");
        }
    } 
}