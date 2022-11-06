#include <stdio.h>

void printWhole(void)
{
    char downSign = 0;
    char upSign = 0;
    char spaceCounter = 5;

    for (char k = 0; k < 5; k++)
    {
        for (char i = spaceCounter; i > 0; i--)
        {
            printf("  ");
        }
        for (char l = 1 + upSign; l >= 1 ; l--)
        {
            printf("# ");
        }
        printf("\n");
        upSign += 2;
        spaceCounter--;
        
    }

    for (char i = 6; i >= 1; i--)
    {
        for (char s = 0; s < 6 - i; s++)
        {
            printf("  ");
        }
        for (char j = 11 - downSign; j >= 1; j--)
        {
            printf("# ");
        }

        downSign += 2;
        printf("\n");
    }
}

void printUp(){
    char signCounter = 0;
    char spaceCounter = 5;

    for (char k = 0; k < 6; k++)
    {
        for (char i = spaceCounter; i > 0; i--)
        {
            printf("  ");
        }
        for (char l = 1 + signCounter; l >= 1 ; l--)
        {
            printf("# ");
        }

        signCounter += 2;
        spaceCounter--;

        printf("\n");
    }
}

void printDown(){
     char signCounter = 0;

    for (char i = 6; i >= 1; i--)
    {
        for (char s = 0; s < 6 - i; s++)
        {
            printf("  ");
        }
        for (char j = 11 - signCounter; j >= 1; j--)
        {
            printf("# ");
        }

        signCounter += 2;

        printf("\n");
    }
}


int main()
{
    printDown();

    printf("\n");

    printUp();

    printf("\n");

    printWhole();

    return 0;
}
