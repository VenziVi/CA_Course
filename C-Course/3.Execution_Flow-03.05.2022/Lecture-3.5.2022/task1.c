#include <stdio.h>

int main(){
    int n;

    printf("Enter 1, 2 or 3: ");
    scanf("%d", &n);

    if (n == 1)
    {
        printf("Hello");
    }
    else if (n == 2)
    {
        printf("Poem");
    }
    else{
        printf("Hidden message");
    }
    
}