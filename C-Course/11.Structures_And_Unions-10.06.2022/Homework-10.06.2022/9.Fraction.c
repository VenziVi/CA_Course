// Задача 11. Създайте структура
// fraction (аритметична дроб) с член данни int n(nominator=числител)
// и int d (denominator=знаменател)
// С помощта на typedef struct създайте нов тип FRACTION
// и указател към него *FPTR
// Дефинирайте функциите
// FRACTION create(int numerator, int denominator);-създаване на дроб по дадени
// стойности на числител и знаменател
// FRACTION input(void);-създаване на дроб по стойности въведени от клавиатурата
// void print(FPTR); - отпечатване на дроб
// int gcd(int first_dividend, int second_dividend); - НОД
// FRACTION add(FPTR, FPTR); -събиране на две дроби
// FRACTION mult(FPTR, FPTR);-умножение на две дроби
// FRACTION divide(FPTR, FPTR);-деление на две дроби
// FRACTION subtract(FPTR, FPTR);-изваждане на две дроби

#include <stdio.h>

typedef struct fraction
{
    int n;
    int d;

} FRACTION;

int main()
{
    FRACTION *FPTR;
    
}

