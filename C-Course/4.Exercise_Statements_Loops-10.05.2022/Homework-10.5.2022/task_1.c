// Напишете C програма за броене на честотата на цифрите в дадено число.
// Input any number: 116540
// Frequency of 0 = 1
// Frequency of 1 = 2
// Frequency of 2 = 0
// Frequency of 3 = 0
// Frequency of 4 = 1
// Frequency of 5 = 1
// Frequency of 6 = 1
// Frequency of 7 = 0
// Frequency of 8 = 0
// Frequency of 9 = 0


#include <stdio.h>

int main(){

    int n, currNum; 
    char arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    printf("Enter number: ");
    scanf("%d", &n);

    while (n > 0)
    {
        currNum = n % 10;
        arr[currNum]++;
        n /= 10;
    }

    for (int i = 0; i < sizeof(arr); i++)
    {
        printf("Frequency of %d = %d \n", i, arr[i]);
    }
}