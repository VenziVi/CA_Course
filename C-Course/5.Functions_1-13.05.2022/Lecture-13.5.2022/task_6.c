// 6. Да се напише програма, която използва функция, проверяваща дали
// едно число е цяло.

#include <stdio.h>
#include <stdbool.h>

bool isInt(float n);

int main(){   

    float n;

    printf("Enter number: ");
    scanf("%f", &n);

    (isInt(n)) ? printf("Number is Integer.") : printf("Number is not integer.");
}

bool isInt(float n){

    if (n == (int)n)
        return true;
    
    return false;
}