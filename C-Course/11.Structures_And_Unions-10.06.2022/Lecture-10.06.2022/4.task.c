#include <stdio.h>

struct distance
{
    float km;
    float m;
    float cm;
} distance, distance1, distanceRes;

float menu(char msg[])
{
    float res = 0;
    printf("%s \n", msg);
    scanf("%f", &res);
    return res;
}

int main()
{
    distance.km = menu("Enter km: ");
    distance.m = menu("Enter m: ");
    distance.cm = menu("Enter cm: ");

    distance1.km = menu("Enter km: ");
    distance1.m = menu("Enter m: ");
    distance1.cm = menu("Enter cm: ");

    distanceRes.km = (distance.km + distance1.km);
    distanceRes.m = (distance.m + distance1.m);
    distanceRes.cm = (distance.cm + distance1.cm);

    printf("Km = %f \n", distanceRes.km);
    printf("M = %f \n", distanceRes.m);
    printf("Cm = %f \n", distanceRes.m);

}