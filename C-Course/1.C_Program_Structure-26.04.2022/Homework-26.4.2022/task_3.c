#include <stdio.h>

int main(){

    unsigned int earthDays;

    printf("Enter earth days: ");
    scanf("%d", &earthDays);

    unsigned int jupiterYears = earthDays / 4333;

    if (earthDays % 4333 == 0)
    {
        printf("%d days are equal to %d jupiter years.",earthDays, jupiterYears);
    }
    else
    {
        float jupiterDays = ((earthDays - (jupiterYears * 4333)) * 24) / 10.;
        printf("%d days are equal to %d jupiter years and %.1f jupiter days.",earthDays, jupiterYears, jupiterDays);
    }

    return 0;
}