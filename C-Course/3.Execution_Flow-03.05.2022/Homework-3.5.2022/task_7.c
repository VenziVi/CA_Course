#include<stdio.h>

int main(){
    
    int n, a1, c;

    printf("Enter N: ");
    scanf("%d", &n);
    printf("Enter first member: ");
    scanf("%d", &a1);
    printf("Enter const: ");
    scanf("%d", &c);

    if (a1 == 0 || c == 0)
    {
        return printf("First member or const is 0.");
    }
    

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            printf("%d, ", a1);
        
        a1 = a1 * c;

        if(i == n)
            printf("%d", a1);
        else
            printf("%d, ", a1);
    }
}