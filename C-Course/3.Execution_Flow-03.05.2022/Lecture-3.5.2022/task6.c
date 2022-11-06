#include <stdio.h>

int main(){
    int day;

    printf("Enter day 1-7: ");
    scanf("%d", &day);

    switch (day)
    {
        case 1: printf("M"); break;
        case 2: printf("T"); break;
        case 3: printf("W"); break;
        case 4: printf("Ts"); break;
        case 5: printf("F"); break;
        case 6: printf("S"); break;    
        case 7: printf("Su"); break;
        default: printf("Enter day...");
    }
}