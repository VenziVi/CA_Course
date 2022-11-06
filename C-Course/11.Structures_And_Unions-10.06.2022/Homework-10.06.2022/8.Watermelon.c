// Задача 10.
// Създайте структура диня с два елемента - диаметър и дебелина на кората заделете
// динамично с malloc() за масив от А на брой дини от сорт мелон и попълнете данните
// за диаметър между 15 и 140 см с функцията rand(), за всяка една диня в масива и
// дебелина на кората между 0.5 и 3.5 см. Създайте структура диня с два елемента -
// диаметър и дебелина на кората заделете динамично с malloc() за масив от В на брой
// дини от сорт пъмпкин и попълнете данните за диаметър между 35 и 95 см с
// функцията rand(), за всяка една диня в масива и дебелина на кората между 0.3 и 0.9
// см. Намерете средната големина на динята и средната дебелина на кората и ги
// съпоставете с тези от втория масив. Изведете на екрана купчината от кой сорт е по
// добре да се купи.
// Изход: По-добре е да се купят ... дини с диаметър ... сантиметра и кора с дебелина D
// см вместо ... дини с диаметър ... см и дебелина на кората D1 см.

#include <stdio.h>
#include <stdlib.h>

struct watermelon
{
    int diameter;
    float thickness;
};

void setSizes(struct watermelon variety[], int size, char varType);
float findAvg(struct watermelon variety[], int size, char parameter);
int setCount(char msg[]);

int main()
{
    const int melonCount = setCount("Enter melon count: ");
    const int pumpkinCount = setCount("Enter pumpkin count: ");

    char diameter = 'd';
    char thickness = 't';
    char melonType = 'm';
    char pumpkinType = 'p';
    float melonAvgDiameter = 0;
    float melonAvgThickness = 0;
    float pumpkinAvgDiameter = 0;
    float pumpkinAvgThickness = 0;

    struct watermelon *melon = malloc(sizeof(struct watermelon) * melonCount);
    struct watermelon *pumpkin = malloc(sizeof(struct watermelon) * pumpkinCount);

    setSizes(melon, melonCount, melonType);
    setSizes(pumpkin, pumpkinCount, pumpkinType);

    melonAvgDiameter = findAvg(melon, melonCount, diameter);
    melonAvgThickness = findAvg(melon, melonCount, thickness);
    pumpkinAvgDiameter = findAvg(pumpkin, pumpkinCount, diameter);
    pumpkinAvgThickness = findAvg(pumpkin, pumpkinCount, thickness);

    printf("Avg melon diameter: %.2f \n", melonAvgDiameter);
    printf("Avg melon thickness: %.2f \n", melonAvgThickness);
    printf("Avg pumpkin diameter: %.2f \n", pumpkinAvgDiameter);
    printf("Avg pumpkin thickness: %.2f \n", pumpkinAvgThickness);

    if (melonAvgThickness < pumpkinAvgThickness)
    {
        printf("Better buy melons.");
    }
    else
    {
        printf("Better buy pumpkins.");
    }

    free(melon);
    free(pumpkin);
    
    return 0;
}

float findAvg(struct watermelon variety[], int size, char parameter)
{
    float total = 0;

    for (int i = 0; i < size; i++)
    {
        if (parameter == 'd')
        {
            total += variety[i].diameter;
        }
        else if (parameter == 't')
        {
            total += variety[i].thickness;
        }
    }

    return (total / size);
    
}

void setSizes(struct watermelon variety[], int size, char varType)
{
    int melonMinDiameter = 15;
    int melonMaxDiameter = 140;
    int melonMinThickness = 1;
    int melonMaxThickness = 3;
    int pumpkinMinDiameter = 35;
    int pumpkinMaxDiameter = 95;
    int pumpkinMinThickness = 1;
    int pumpkinMaxThickness = 2;

    for (int i = 0; i < size; i++)
    {
        if (varType == 'm')
        {
            variety[i].diameter = (rand() % (melonMaxDiameter - melonMinDiameter + 1)) + melonMinDiameter;
            variety[i].thickness = ((rand() % (melonMaxThickness - melonMinThickness + 1)) + melonMinThickness) / (0.23 + i + 1);
        }
        else if (varType == 'p')
        {
            variety[i].diameter = (rand() % (pumpkinMaxDiameter - pumpkinMinDiameter + 1)) + pumpkinMinDiameter;
            variety[i].thickness = ((rand() % (pumpkinMaxThickness - pumpkinMinThickness + 1)) + pumpkinMinThickness) / (0.23 + i + 1);
        }
    }
}

int setCount(char msg[])
{
    int count = 0;
    printf("%s", msg);
    scanf("%d", &count);
    return count;
}