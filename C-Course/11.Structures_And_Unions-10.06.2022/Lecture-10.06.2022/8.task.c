#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point
{
    int x;
    int y;
    struct point *ptr;
};

int main()
{
    struct point point1;
    point1.x = 5;
    point1.y = 2;

    struct point point2;
    point2.x = 10;
    point2.y = 22;

    point1.ptr = &point2;
    point2.ptr = &point1;

    point1.ptr->x = 345;
    point2.ptr->x = 546;

    printf("%d, %d", point1.x, point2.x);

    return 0;
}