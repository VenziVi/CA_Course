// 9. Функция, проверяваща дали едно число e точен квадрат. Програма,
// която чете число и отпечатва резултата от извикването на функцията.
// 10. Функция, която връща най-големия точен квадрат в
// даден интервал (a, b). Програма, която чете a и b и отпечатва резултата
// от извикването на функцията.

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isSqr();
int maxSqr();

int main(){   

    int a, b, result;
    printf("Enter numbers: ");
    scanf("%d", &a);
    printf("Enter numbers: ");
    scanf("%d", &b);

    result = maxSqr(a, b);
    printf("%d", result);
}

int maxSqr(int a, int b){
    int max = 0 ;

    for (int i = a; i <= b; i++)
    {   
        if(isSqr(i)){

            if (sqrt(i) > max)
            {
                max = sqrt(i);
            }     
        }
    }
    return max;
}

bool isSqr(int a){

    if ((sqrt(a) * sqrt(a)) == a)
    {
       return 1;
    }  
    return 0;
}