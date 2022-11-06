// Задача 12. Да се напише програма, която по дадено цяло положително
// число, проверява дали е число на Armstrong, т.е. Сумата от кубовете на
// отделните цифри са равни на числото, например, такова е числото
// 153 = 13+53+33.
// Input a number: 153
// 153 is an Armstrong number

#include <stdio.h>

int main(){
    int n, r, sum = 0, temp;

    printf("Input a number: \n");
    scanf("%d", &n);

    for(temp=n; n !=0; n=n/10)
    {
        r = n % 10;
        sum = sum + r * r * r;
    }

    if(sum == temp)
        printf("%d is an Armstrong number.\n", temp);
    else
        printf("%d is not Armstrong number.\n", temp);
}