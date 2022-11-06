// Задача 5. Да се напише програма, която намира корен квадратен от едно
// цяло число, подадено на вход

#include <stdio.h>
#include <math.h>

int main(){

    double num, root;

    printf("Enter number: ");
    scanf("%lf", &num);

    root = sqrt(num);

    printf("Square root of %.2lf = %.2lf", num, root);
}