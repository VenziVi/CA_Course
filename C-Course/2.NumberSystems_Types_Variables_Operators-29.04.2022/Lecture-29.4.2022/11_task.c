#include <stdio.h>

int main(){

    int counter = 0;

    while (++counter < 3)
    {
        printf("%d \n", counter);
        printf("++c %d \n", ++counter);
        printf("--c %d \n", --counter);
        printf("c++ %d \n", counter++);
        printf("c-- %d \n", counter--);
    }

    return 0;
}