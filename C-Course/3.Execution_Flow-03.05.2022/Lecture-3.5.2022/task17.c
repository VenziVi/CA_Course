#include <stdio.h>

int main(){
    int n; 
    double sum = 1;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            sum *= i;
        }
    }
    printf("%.2lf", sum);
}