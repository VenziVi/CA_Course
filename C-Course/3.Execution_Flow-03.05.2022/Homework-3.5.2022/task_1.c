#include <stdio.h>

void printMounts(int mounts, double money, double interest){

    double result = 0;

    for (int i = 1; i <= mounts; i++)
    {
        if (i == 1)
        {
            result = money;
        }
        
        result += result * interest;
        printf("Mount %d: %.2lf \n", i, result);
    }
}

int main(){
    double money, interest, total, result = 0.;
    int years = 5, nYears, mounts, vMounts = 0;

    printf("Enter money to insert: ");
    scanf("%lf", &money);

    printf("Enter interest: ");
    scanf("%lf", &interest);

    printf("Enter years: ");
    scanf("%d", &nYears);

    printf("Enter wanted total earn: ");
    scanf("%lf", &total);
    printf("\n");

    interest = interest / 100;

    mounts = 5 * 12;

    printMounts(mounts, money, interest);
    printf("\n");

    mounts = nYears * 12;

    printMounts(mounts, money, interest);
    printf("\n");

    result = money;

    while (result <= total)
    {
        vMounts++;
        result += result * interest;
        printf("Mount %d: %.2lf \n", vMounts, result);
    }
    
    int totalYears = (vMounts % 12 == 0) ? vMounts / 12 : vMounts / 12 + 1;
    printf("You need %d years to earn %.2lf lv. \n", totalYears, total);
    printf("\n");
}