#include <stdio.h>
#include <stdbool.h>

int main(){
    printf("bool =%d bytes\n", sizeof(bool));
    printf("char =%d bytes\n", sizeof(char));
    printf("int =%d bytes\n", sizeof(int));
    printf("short int =%d bytes\n", sizeof(short int));
    printf("long int =%d bytes\n", sizeof(long int));
    printf("long long int =%d bytes\n", sizeof(long long int));

    printf("unsigned char =%d bytes\n", sizeof(unsigned char));
    printf("unsignet int =%d bytes\n", sizeof(unsigned int));

    printf("long double =%d bytes\n", sizeof(long double));
    printf("double =%d bytes\n", sizeof(double));
    printf("float =%d bytes\n", sizeof(float));

    int x = 5;
    float y = 12.5;
    x = (int) y;

    printf("%d", x);

    return 0;
}