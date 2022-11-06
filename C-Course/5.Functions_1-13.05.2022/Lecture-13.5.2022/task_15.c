// 15. Като се използва рекурсивна функция, да се напише програма за
// бързо повдигане на степен за едно цяло положително число n.

#include <stdio.h>

long stepen(int n, int k);

int main()
{   
    int n = 3, k = 10;

    printf("%i", stepen(n, k));
}

long stepen(int n, int k){

    if(k == 1) return n;
    
    if(k % 2 == 0) 
        return stepen(n, k / 2) * stepen(n, k / 2);
    else
        return n * stepen(n, k - 1);
    
}