// 11. Функция, която проверява, дали един символ е латинска буква.
// Програма, която чете символи от клавиатурата, докато бъде въведена
// цифрата 0 и извежда броят на въведените букви.

#include <stdio.h>
#include <stdbool.h>

bool isLetter(char x);

int main(){   

    char x;
    int count = 0;

    while ((x = getchar()) != 48)
    {
        if(isLetter(x))
            count++;
    }
    
    printf("%d letters was entered. \n", count);

}

bool isLetter(char x){

    if ((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
    {
        return 1;
    }
    return 0;
}