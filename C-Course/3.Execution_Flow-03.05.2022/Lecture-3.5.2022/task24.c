#include <stdio.h>

int main()
{
    int tab = 0, s = 0;
    char c;

    while((c = getchar()) != EOF){

        if (c == '\t')
            tab++;

        if(c == ' ')
            s++;
    }

    printf("%d \n %d", tab, s);
}