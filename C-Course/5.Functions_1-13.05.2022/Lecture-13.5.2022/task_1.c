// 1. Да се напише програма с 4 функции, предназначени за събиране,
// изваждане, умножение и деление на 2 реални числа.
// Програмата да чете стойности на 2 реални числа и да пресметне сумата,
// разликата, произведението и частното на тези две числа.

#include <stdio.h>

float multiply(float a, float b);
float sum(float a, float b);
float subtraction(float a, float b);
float divine(float a, float b);


int main(){
    float a, b;

    printf("Enter number a: ");
    scanf("%f", &a);
    printf("Enter number b: ");
    scanf("%f", &b);

    printf("%f \n", multiply(a, b));
    printf("%f \n", sum(a, b));
    printf("%f \n", subtraction(a, b));
    printf("%f \n", divine(a, b));

}

float multiply(float a, float b){
    return a * b;
}

float sum(float a, float b){
    return a + b;
}

float subtraction(float a, float b){
    return a - b;
}

float divine(float a, float b){
    return a / b;
}