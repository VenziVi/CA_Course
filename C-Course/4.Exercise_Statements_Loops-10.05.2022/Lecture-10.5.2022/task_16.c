// Задача 16. Да се напише програма, която намира Strong Numbers
// до дадено цяло число n.

#include <stdio.h>

int main(){

    int i, n, oldNum, sum = 0, temp;

    printf("Enter number: ");
    scanf("%d", &n);

    oldNum = n;

    while (n > 0)
    {
        int fact = 1;
        temp = n % 10;

        for ( i = 1; i <= temp; i++)
        {
            fact *= i;
        }
        
        sum += fact;
        n /= 10;
    }

    if (sum == oldNum)
    {
        printf("Number %d is a strong number.", oldNum);
    }
    else{
        printf("Number %d is NOT a strong number.", oldNum);
    }
}