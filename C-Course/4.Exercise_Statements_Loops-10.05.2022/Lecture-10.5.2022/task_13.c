// Задача 13. Да се напише програма, която по дадено цяло положително
// число, проверява дали това е просто или не е.
// Едно число се нарича просто, ако се дели само на 1 и на себе си, т.е. Няма
// други делители.

#include <stdio.h>

int main(){

    int i, n;
    int isSimple = 0;

    printf("Enter number: ");
    scanf("%d", &n);

    for ( i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            isSimple = 1;
            break;
        }
    }
    
    if (isSimple == 0)
        printf("Number %d is a simple number.", n);
    else
        printf("Number %d is NOT a simple number.", n);
}