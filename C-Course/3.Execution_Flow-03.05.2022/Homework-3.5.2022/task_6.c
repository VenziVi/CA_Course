#include<stdio.h>

int main(){
    
    int n, a1, d, r;

    printf("Enter N: ");
    scanf("%d", &n);
    printf("Enter first member: ");
    scanf("%d", &a1);
    printf("Enter difference: ");
    scanf("%d", &d);

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            printf("%d, ", a1);
        
        a1 = a1 + d;

        if(i == n)
            printf("%d", a1);
        else
            printf("%d, ", a1);
    }
}