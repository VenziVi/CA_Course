#include <stdio.h>

int main(){
    int a, b, sum = 0;
    scanf("%d%d", &a, &b);

    do
    {
        sum += a;
        a++;
    } while (a <= b);

    printf("%d", sum);
}