#include <stdio.h>

int main(){
    int a, b, c, d, f;

    scanf("%d%d%d%d%d", &a, &b, &c, &d, &f);

    float grade = (a + b + c + d + f) / 5.;

    if (grade < 40)
        printf("F");
    else if (grade >= 40 && grade < 60)
        printf("E");
    else if (grade >= 60 && grade < 70)
        printf("D");
    else if (grade >= 70 && grade < 80)
        printf("c");
    else if(grade >= 80 && grade < 90)
        printf("B");
    else 
        printf("A");
}