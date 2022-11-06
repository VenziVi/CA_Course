#include <stdio.h>

int main(){
    int n, x;

    printf("Enter number: ");
    scanf("%d", &n);

    x = n % 10;

    if (x == 0 || x == 5)
    {
        printf("Number %d se deli na 5", n);
    }
    else
    {
        printf("Ne se deli na 5");
    }
}