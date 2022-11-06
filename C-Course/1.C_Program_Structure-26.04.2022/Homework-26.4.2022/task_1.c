#include <stdio.h>

int main(){

    float weight;
    printf("Enter your weight: ");
    scanf("%f", &weight);

    float moonWeight = (weight / 9.81) * 1.622;

    printf("Your moon weight is: %.3f kg", moonWeight);

    return 0;
}