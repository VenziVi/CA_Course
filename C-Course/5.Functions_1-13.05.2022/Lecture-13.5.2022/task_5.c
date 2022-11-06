// 5. Функция, която отпечатва едно цяло десетично число в двоична
// бройна система — чрез 0 и 1

#include <stdio.h>

void printBinary();

int main(){   

    int num;

    printf("Enter number: ");
    scanf("%d", &num);
    printBinary(num);
}

void printBinary(int num){

    int bin[8];

    while (num != 0)
    {
        for (int i = 0; i < 8; i++)
        {
            bin[i] = num % 2;
            num /= 2;
        }
    }

    for (int i = 7; i >= 0; i--)
    {
        printf("%d", bin[i]);
    }
}
