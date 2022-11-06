// Задача 6. Да се напише програма, която изчислява печалба или загуба при
// продажбата на една стока. На вход се подават стойността на стоката и цената
// на продажбата на стоката.

#include <stdio.h>

int main(){

    int cost, sell, amt;

    printf("Enter cost price: ");
    scanf("%d", &cost);

    printf("Enter sell price: ");
    scanf("%d", &sell);

    amt = abs(sell - cost);

    if (sell > cost)
    {
        printf("Profit = %d", amt);
    }
    else if (sell < cost)
    {
        printf("Loss = %d", amt);
    }
    else{
        printf("No profit no loss.");
    }
}