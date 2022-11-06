#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define AVG(x, y) ((x + y) / 2.)
#define NUMBER(a, b) (b - a + 1)
#define SUM(a, b) ((a + b * NUMBER(a, b)))
#define AVG1(x, y) SUM(a, b) / NUMBER(a,b)
#define POW(x, y) ( pow(x, y) )
#define TOUPPER(x) ((x >= 'a' && x <= 'z') ? x + 'A' - 'a' : x)
//#define DISP((f), (x)) sqrt((double)(x))

int main()
{
    float a = 5;
    float b = 2;
    int x = 1;
    int y = 3;
    
    //printf("%f \n", AVG(a, b));

    //printf("%d \n", AVG1(x, y));

    //printf("%f \n", POW(2, 8));

    printf("%c", TOUPPER('w'));
}