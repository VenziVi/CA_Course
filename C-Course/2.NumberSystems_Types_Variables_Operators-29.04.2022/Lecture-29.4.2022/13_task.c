#include <stdio.h>

int main(){

    int a = 13;
    int* pValue = NULL;

    pValue = &a;

    printf("address : %p \n", pValue);
    printf("value : %d \n", *pValue);

    return 0;
}