/*
Напишете следните функции:
● Функция, която проверявя дали едно число е просто
● Функция, която връща най-големия общ делител на две числа
● Функция, която използва горната функция и по даден като параметър
 масив от цели числа, връща НОД на елементите от масива
*/
 
#include<stdio.h>
 
int check_prime_number(int n)
{
    int flag = 0, i;
 
    if (n == 0 || n == 1){
        flag = 1;
    }
 
    for (i = 2; i <= n / 2; ++i) {
 
        if (n % i == 0) {
            flag = 1;
            break;
        }
    }
 
    // flag is 0 for prime numbers
    if (flag == 0)
        printf("%d is a prime number.", n);
    else
        printf("%d is not a prime number.", n);
}
 
int gcd(int x, int y){
    unsigned wk;
    if(x<y){ wk=x;x=y;y=wk; }
    while(y){
        wk = x%y;
        x=y;
        y=wk;
    }
    return x;
 
}
 
int gcd_a(int n, int a[n]){
    if(n==1) return a[0];
    if(n==2) return gcd(a[0], a[1]);
    int h = n / 2;
    return gcd(gcd_a(h, &a[0]), gcd_a(n - h, &a[h]));
}
 
int main()
{
    int num_1, num_2, num_3, arr[4];
    printf("Enter a number to check if it is prime (positive integer): \n");
    scanf("%d", &num_1);
    check_prime_number(num_1);
 
    printf("\n");
    printf("Enter two numbers to check GCD:\n");
    scanf("%d", &num_2);
    scanf("%d", &num_3);
    printf("GCD two nums: %d", gcd(num_2, num_3));
 
    printf("\n");
    int A[10]={112, 160, 180, 240, 288, 32, 480, 96, 60, 72};
    int size_A = sizeof(A)/sizeof(*A);
    for (int i = 0; i < size_A; i++)
    {
        printf("%d ", A[i]);
    }
    int gcd = gcd_a(size_A, A);
    printf(" --> GCD of the Array is: %d\n", gcd);
    return 0;
 
}