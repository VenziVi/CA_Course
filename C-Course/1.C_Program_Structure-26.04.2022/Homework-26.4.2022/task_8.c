#include <stdio.h>

int main(){

    char line[7] = "******";

    printf("%s \n", line);
    printf("%12s \n", line);
    printf("%18s \n", line);
    printf("%24s", line);

    return 0;
}