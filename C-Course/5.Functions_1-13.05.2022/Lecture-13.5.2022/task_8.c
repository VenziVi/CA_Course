// 8. Функция, пресмятаща n!=1*2*3*...*n
// long factoriel( int n)
// Програма, която за въведено едноцифрено число k, пресмята и
// отпечатва

#include <stdio.h>

long fact();

int main(){   

    int k;
    printf("Enter number: ");
    scanf("%d", &k);

    long sum = 0;

    for (int i = 1; i <= k; i++)
    {
        sum += fact(i);
    }
    
    printf("%i", sum);
}

long fact(int num){

    long fact = 1;

    for (int i = 1; i <= num; i++)
    {
        fact = fact * i;
    }
    
    return fact;
}
