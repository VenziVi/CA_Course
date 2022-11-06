#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point
{
    int x;
    int y;
};

struct point* makePoint(int x, int y)
{
    struct point *p = malloc(sizeof(struct point));
    p->x = x;
    p->y = y;

    return p;
}

int main()
{
    struct point* pointA = makePoint(4, 8);

    printf("%d \n", pointA->y);

    free(pointA);
    return 0;
}