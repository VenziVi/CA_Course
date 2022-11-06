#include <stdio.h>

int FindSum(int n){

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 && (i / 2) % 2 != 0)
        {
            sum += i;
        }
    }

    return sum;
}

int main(){

    printf("a) Result = %d \n", FindSum(41));

    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    printf("b) Result = %d \n", FindSum(n));

    int sum = 0;
    int num = 0;

    while (sum <= 999)
    {
        if (num % 2 == 0 && (num / 2) % 2 != 0)
        {
            sum += num;
        }
        
        num++;
    }
    
    printf("c) Result = %d \n", num);
}
