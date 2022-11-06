#include <stdio.h>

int main(){

    unsigned short int ounces;
    printf("Enter ounces: ");
    scanf("%d", &ounces);

    unsigned short int cups = ounces / 8;

    if (ounces % 8 != 0)
    {
        cups ++;
    }
    
    printf("Your want %d cups.", cups);

    return 0;
}