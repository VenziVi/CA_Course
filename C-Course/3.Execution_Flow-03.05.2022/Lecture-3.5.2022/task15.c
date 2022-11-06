#include <stdio.h>

int main(){
    for (int i = 13; i <= 19; i++)
    {
        printf("%d \t", i);
    }
    
    int n, sum = 0;
    scanf("%d", n);
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

     printf("%d \t", n);
}