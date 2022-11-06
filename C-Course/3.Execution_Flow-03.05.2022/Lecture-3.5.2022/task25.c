#include <stdio.h>

int main()
{
    char c;
    int s = 0;

    while((c = getchar()) != EOF){

        if (c != ' ')
            s = 0;
        
        if (s == 0)
            putchar(c);

        if (c == ' ')
            s = 1;
    }
}