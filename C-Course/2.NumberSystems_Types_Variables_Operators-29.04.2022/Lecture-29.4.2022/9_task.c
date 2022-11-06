#include <stdio.h>
#include <stdbool.h>

int main(){

    int x = 10, y = 10;
    int t, f;

    t = x == y;
    f = x != y;

    printf("%d, %d", t, f);

    return 0;
}