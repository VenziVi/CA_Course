// Задача 8. Направете структура struct rect, която съдържа в
// себе си две точки. Създайте обект от тип тази структура наречен
// screen. Използвайте функцията makepoint за да зададете начална точка
// на екрана (0, 0) и крайна точка (15, 15). Запълнете пространството
// между тях с тирета.

#include <stdio.h>
#include <stdlib.h>

struct point
{
    int x;
    int y;
};

struct rect
{
    struct point startPoint;
    struct point endPoint;
};

struct point makePoint(int x, int y);

int main()
{
    struct rect screen;

    screen.startPoint = makePoint(0, 0);
    screen.endPoint = makePoint(15, 15);

    printf("%d, %d", screen.startPoint.x, screen.endPoint.y);
    
}

struct point makePoint(int x, int y)
{
    struct point *p = malloc(sizeof(struct point));
    p->x = x;
    p->y = y;

    return *p;
}