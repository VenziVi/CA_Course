#include <stdio.h>

int main(){
    int a, num;
    scanf("%d", &a);

    do
    {
        a /= 10;
        num ++;
    } while (a > 0);

    printf("%d", num);
}