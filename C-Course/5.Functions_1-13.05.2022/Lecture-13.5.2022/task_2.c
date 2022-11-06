// 2. Да се напише функция, връщаща максималното от две числа.
// Програмата ще чете 3 числа и извежда максималното от тези 3 числа,
// като използва написаната функция. Задачата да се направи по два
// начина — с оператор if и с тернарен оператор.

#include <stdio.h>

int findMax();

int main(){
    
    int a, b;

    printf("Enter numbers: ");
    scanf("%d", &a);

    printf("Enter numbers: ");
    scanf("%d", &b);

    printf("%d", findMax(a, b));
}

int findMax(int a, int b){
    return (a >= b)? a : b;
}

