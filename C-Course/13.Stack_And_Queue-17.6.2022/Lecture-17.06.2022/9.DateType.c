#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int day : 5;
    int month : 5;
    int year;
} dateType;

bool checkData(dateType *date);
void printData(dateType *date);

int main()
{
    dateType date;

    if(checkData(&date) == false)
    {
        printf("INVALID DATE!");
        return 1;
    }

    printData(&date);

    return 0;    
}

bool checkData(dateType *date)
{
    int day = 0;
    int month = 0;
    int year = 0;

    printf("Enter day: ");
    scanf("%d", &day);
    printf("Enter month: ");
    scanf("%d", &month);
    printf("Enter year: ");
    scanf("%d", &year);

    if (month > 0 && month <= 12)
    {
        date->month = month;
    }
    else
    {
        return false;
    }
    

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 0 && day <= 30)
        {
            date->day = day;
        }
        else
        {
            return false;
        }
    }
    else if (month == 2)
    {
        if (day > 0 && day <= 28)
        {
            date->day = day;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (day > 0 && day <= 31)
        {
            date->day = day;
        }
        else
        {
            return false;
        }
    }
    
    if (year > 1900 && year < 2050)
    {
        date->year = year;
    }
    else 
    {
        return false;
    }
    
    return true;
}

void printData(dateType *date)
{

    printf("Date: ");

    if (date->day < 10)
    {
        printf("0%d/", date->day);
    }
    else
    {
        printf("%d/", date->day);
    }

    if (date->month < 10)
    {
        printf("0%d/", date->month);
    }
    else
    {
        printf("%d/", date->month);
    }

    printf("%d \n", date->year);
    
}