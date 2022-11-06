// 18. Да се напише програма, която въвежда три числа и проверява дали те могат да
// бъдат страни на триъгълник.
// a<b+c и b<a+c и c<a+b
// a>0 b>0 c>0
// Ако са страни на триъгълник, да се определи вида на триъгълника -
// рамнобедрен, равностраннен или разностранен

#include <stdio.h>

int main(){

    int x, y, z;

    printf("Enter number x: ");
    scanf("%d", &x);
    printf("Enter number y: ");
    scanf("%d", &y);
    printf("Enter number z: ");
    scanf("%d", &z);

    if (x <= 0 || y <= 0 || z <= 0)
    {
        printf("NO");
    }
    else if (x < (y + z) && y < (x + z) && z < (x + y))
    {
        if (x == y && x == z && y == z)
        {
            printf("RS");           
        }
        else if (x == y || x == z || y == z)
        {
            printf("RB");
        }
        else
        {
            printf("RZS");
        }        
    }
    else
    {
        printf("NO");
    }
    
}