// ● 7. Дадени са два правоъгълника със страни успоредни на координатните оси. Да се намерят:
// сумата от лицата им, лицето на обединението и сечението им.
// Вход. На всеки от редовете на стандартния вход ще бъде зададена по една двойка
// правоъгълници с осем цели неотрицателни числа – координати на горния ляв и долния десен
// ъгъл на единия и другия правоъгълник.
// Ограничения. Всички числа са по-малки или равни на 100.
// Изход. За всяка двойка правоъгълници, на един ред на стандартния изход програмата трябва да
// изведе 3 числа — сумата от лицата на двата правоъгълника, лицето на обединението и лицето
// на сечението им.


#include <stdio.h>
#include <math.h>

typedef struct point
{
    int x;
    int y;
} point;

int overlappinArea(point l1, point r1, point l2, point r2);

int main()
{
    point l1 = {0, 1};
    point l2 = {0, 2};
    point r1 = {1, 0};
    point r2 = {2, 0};

    int overlap = overlappinArea(l1, r1, l2, r2);
    printf("%d", overlap);
}

int overlappinArea(point l1, point r1, point l2, point r2)
{
    int area1 = abs(l1.x - r1.x) * abs(l1.y - r1.y);
    int area2 = abs(l2.x - r2.x) * abs(l2.y - l2.y);

    int xDist = fmin(r1.x, r2.x) - fmax(l1.x, l2.x);
    int yDist = (fmin(r1.y, r2.y) - fmax(l1.y, l2.y));

    int areaI = 0;

    if (xDist > 0 && yDist > 0)
    {
        areaI = xDist * yDist;
    }
    
    return (area1 + area2 - areaI);
}