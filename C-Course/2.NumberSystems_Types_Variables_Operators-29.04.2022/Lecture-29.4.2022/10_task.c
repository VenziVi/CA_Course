#include <stdio.h>
#include <stdbool.h>

int main(){

    int x = 10, y = 10, z = 30;

    int t = x == y + (z < y) != 20;

    printf("%d", t);

    return 0;
}