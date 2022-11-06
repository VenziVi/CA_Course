// Задача 3. Напишете програма, която калкулира разликата на
// два времеви периода, изразени във векове, години, месеци, дни,
// минути, секудни. Принтирайте изходните периоди и резултата.

#include <stdio.h>
#include <stdlib.h>

struct timePeriod
{
    int centuries;
    int years;
    int mounths;
    int days;
    int hours;
    int min;
    int sec;
};

struct timePeriod *findDifference(struct timePeriod *first, struct timePeriod *seconf);

int main()
{
    struct timePeriod firstPeriod = {10, 55, 8, 25, 12, 35, 43};
    struct timePeriod secondPeriod = {5, 28, 7, 10, 5, 24, 33};
    struct timePeriod *diffrence = findDifference(&firstPeriod, &secondPeriod);

    printf("Centurys: %d, years: %d, mounths: %d, days: %d, hours: %d, min: %d, sec: %d",
            diffrence->centuries,
            diffrence->years,
            diffrence->mounths,
            diffrence->days,
            diffrence->hours,
            diffrence->min,
            diffrence->sec);

    free(diffrence);
    return 0;
}

struct timePeriod *findDifference(struct timePeriod *first, struct timePeriod *second)
{
    struct timePeriod *diffrence = malloc(sizeof(struct timePeriod));

    diffrence->centuries = first->centuries - second->centuries;
    diffrence->years = first->years - second->years;
    diffrence->mounths = first->mounths - second->mounths;
    diffrence->days = first->days - second->days;
    diffrence->hours = first->hours - second->hours;
    diffrence->min = first->min - second->min;
    diffrence->sec = first->sec - second->sec;

    return diffrence;
}