#include <stdio.h>

int main()
{
    int count = 0;
    char c;

    while((c = getchar()) != EOF){
        count++;
    }

    printf("%d\n", count);
}