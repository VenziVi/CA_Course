#include <stdio.h>

void dayDistance(int days, int startDistance, float inc){
    float result = 0;

    for (int i = 1; i <= days; i++)
    {
        if (i == 1)
            result = startDistance;
        if (i > 1)
            result += result * inc;

        printf("On %d day you ran %.2f km \n", i, result);
    }
}

int main(){
    float startDistance, inc, target, dayTarget, result = 0.;
    int days = 10, iDays, daysCount = 1;

    printf("Insert start distance: ");
    scanf("%f", &startDistance);

    printf("Insert increase distance: ");
    scanf("%f", &inc);

    printf("Insert days: ");
    scanf("%d", &iDays);

    printf("Insert target distance for day: ");
    scanf("%f", &dayTarget);

    printf("Insert target distance: ");
    scanf("%f", &target);
    printf("\n");

    inc = inc / 100;

    dayDistance(days, startDistance, inc);
    
    printf("\n");

    dayDistance(iDays, startDistance, inc);
    
    printf("\n");

    result = startDistance;

    while(result <= dayTarget){

        result += result * inc;
        daysCount++;
    }

    printf("On day %d you have ran %.2f km. \n", daysCount, result);
    printf("\n");

    result = startDistance;
    daysCount = 1;

    while(result <= target){

        result += startDistance + startDistance * inc;
        daysCount++;
    }

    printf("For %d you have ran %.2f km. \n", daysCount, result);
    printf("\n");
}