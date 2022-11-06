// 11. Обичате да ядете бонбони, нали. Искате винаги да имате N бонбона в
// себе си. Всеки час можете да си купите по един бонбон, да изядете по един
// бонбон, който имате, или да удвоите всички бонбони. За колко най-малко
// часа може да постигнете това?
// Например:
// Ако N е 1, отговорът би бил 0 (нищо за правене, вече имате 1).
// Ако N е 2, отговорът би бил 1 (бихте могли или да купите нов бонбон, или да
// удвоите тези, които имате).
// Ако N е 7, отговорът би бил 4 (добавяте 1 в първия час, удвоявате двата
// втория, удвоявате четирите третия и изяждате един през четвъртия час).
// Ако N е 19, отговорът би бил 6: добавяте (стават 2), удвоявате (стават 4),
// добавяте (стават 5), удвоявате (стават 10), удвоявате (стават 20), изяждате
// (стават 19).

#include <stdio.h>

int countHours(int wanted, int candys);

int main()
{
    int hours = 0;
    int wanted = 19;
    int candies = 1;

    hours = countHours(wanted, candies);

    printf("hours: %d", hours);  
    return 0;
}

int countHours(int wanted, int candies)
{
    int hours = 0;

    while (wanted > candies)
    {
        if (wanted % 2 == 0)
        {
            hours ++;
            wanted /= 2;
        }
        else
        {
            hours++;
            wanted--;
        }    
    }

    return hours;
}