// 16. Да се напише рекурсивна функция за намиране на максимален елемент
// в масив от цели числа. Да се напише програма, която извиква тази функция
// за да намери най-голямото число в даден масив.

#include <stdio.h>

int max(int *arr, int n);

int main(){   

    int arr[5] = {5,8,2,5,9};

    printf("%d", max(arr, 5));
    
}

int max(int *arr, int n){
    
    int num = arr[n - 1];

    if(n == 1)
        return arr[0];

    else
    {
        int maxN = max(arr, n - 1);
        if(num < maxN)
            num = maxN;
    }

    return num;
}