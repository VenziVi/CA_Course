#include <stdio.h>

int main(){
    
    int a;
    scanf("%d", &a);

    int b = (a == 1) ? 2 : 0;

    printf("a value is %d \n", a);
    printf("b value is %d \n", b);


    int max = (a >= b) ? a : b;

    printf("max value is %d \n", max);

    return 0;
}