#include <stdio.h>

int main(){

    char years;
    unsigned long long int sec;

    printf("Insert year: ");
    scanf("%d", &years);

    sec = years * 31556926;

    printf("%d years have %ld seconds.", years, sec);
    
    return 0;
}