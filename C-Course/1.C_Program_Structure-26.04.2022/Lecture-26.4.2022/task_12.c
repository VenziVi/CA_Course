#include <stdio.h>

int main(){

    int n1, n2, n3;

    scanf("%d \n", &n1);
    scanf("%d \n", &n2);
    scanf("%d", &n3);

    int min;

    if (n1 < n2 && n1 < n3)
    {
        if (n2 < n3)
        {
            printf("%d %d %d", n1, n2, n3);
        }
        else
        {
            printf("%d %d %d", n1, n3, n2);
        }
        
    }
    else if (n2 < n3 && n2 < n1)
    {
        if (n1 < n3)
        {
            printf("%d %d %d", n2, n1, n3);
        }
        else
        {
            printf("%d %d %d", n2, n3, n1);
        }
        
    }
        else if (n3 < n2 && n3 < n1)
    {
        if (n2 < n1)
        {
            printf("%d %d %d", n3, n2, n1);
        }
        else
        {
            printf("%d %d %d", n3, n1, n2);
        }
        
    }
  
    return 0;
}