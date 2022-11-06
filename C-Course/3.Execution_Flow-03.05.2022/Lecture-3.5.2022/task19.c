#include <stdio.h>

int main()
{
    int n = 0;
    while (n < 13){
        n++;
        if (n == 5)
        {
            continue;
        }
        printf("%d \n", n);
    }
}