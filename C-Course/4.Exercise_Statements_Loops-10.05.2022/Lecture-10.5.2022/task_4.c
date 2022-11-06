// Задача 4. Да се напише програма, която изчислява произведението от
// цифрите на цяло число, подадено на вход

#include <stdio.h>

int main(){

    int n, p = 1;

    printf("Enter number: ");
    scanf("%d", &n);

    while (n != 0)
    {
        p = p * (n % 10);
        n /= 10;
    }
    
    printf("Result = %d", p);
}