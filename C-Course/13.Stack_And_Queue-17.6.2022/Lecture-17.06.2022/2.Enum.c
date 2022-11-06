#include <stdio.h>

enum bool {false, true};

int main()
{
    enum bool b = true;

    switch (b){
        case true:
            printf("True");
            break;
        case false:
            printf("False");
            break;
    }

    return 0;
}