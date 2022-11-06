#include <stdio.h>

int main(){

    float a = 1.3;
    if (a == 1.300000)
    {
        printf("Equal \n");
    }
    else
    {
        printf("Not equal \n");
    }
    
    printf("%f", a);
    return 0;
}