// Задача 11. Да се напише програма, която по дадено цяло положително
// число, проверява дали е перфектно, т.е. Дали е равно на сумата от
// делителите си, които са по-малки от числото.

#include <stdio.h>

int main(){

    int i, n, sum = 0;

    printf("Enter number: ");
    scanf("%d", &n);

    for ( i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }

    if (sum == n)
        printf("Number %d is a perfect number.", n);
    else
        printf("Number %d is NOT a perfect number.", n);
}
