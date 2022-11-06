#include <stdio.h>

int main(){

    int a, b, c;

    scanf("%d \n", &a);
    scanf("%d \n", &b);
    scanf("%d", &c);

    int min;

    if (a <= b && a <= c)
    {
        if (b < c)
        {
            printf("%d %d %d", a, b, c);
        }
        else
        {
            printf("%d %d %d", a, c, b);
        }
        
    }
    else if (b <= c && b <= a)
    {
        if (a < c)
        {
            printf("%d %d %d", b, a, c);
        }
        else
        {
            printf("%d %d %d", b, c, a);
        }
        
    }
    else if (c <= b && c <= a)
    {
        if (b < a)
        {
            printf("%d %d %d", c, b, a);
        }
        else
        {
            printf("%d %d %d", c, a, b);
        }
        
    }
  
    return 0;
}