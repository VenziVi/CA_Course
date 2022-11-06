#include <stdio.h>

void arrPr(int *arr, int n);

int main(){   

    int arr[5] = {5,8,2,5,9};

    arrPr(arr, 5);
}

void arrPr(int *arr, int n){

    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
}