#include <stdio.h>

int main(){
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    while (n <= 10 )
    {
        printf("%d \n", n);
        n++;
    }
}