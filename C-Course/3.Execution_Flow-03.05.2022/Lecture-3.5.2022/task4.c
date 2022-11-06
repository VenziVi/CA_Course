#include <stdio.h>

int main(){

    int m;
    scanf("%d", &m);

    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 9 || m == 11)
        printf("31 days");
    else if (m == 2)
        printf("28 days");
    else
        printf("30 days");
}