#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool validateDate(int *datArr)
{
    int size = 6;

    int day = datArr[5] + (datArr[4] * 10);
    int month = datArr[3] + (datArr[2] * 10);
    int year = (datArr[1] + (datArr[0] * 10)) + 1900;

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day <= 0 || day > 30)
        {
            return false;
        }
    }
    else if (month == 2)
    {
        if (day <= 0 || day > 28)
        {
            return false;
        }
    }
    else
    {
        if (day <= 0 || day > 31)
        {
            return false;
        }
    }
    
    if (year <= 1900 || year > 1999)
    {
        return false;
    }

    return true;
}
    

bool checkID(int *idArr, int size)
{
    int checkArr[] = {2, 4, 8, 5, 10, 9, 7, 3, 6};
    int date[6] = {0};
    int sum = 0;
    int result = 0;

    for (int i = 0; i < size - 1; i++)
    {
        sum += idArr[i] * checkArr[i];
        if (i < 6)
        {
            date[i] = idArr[i];
        }
    }

    result = sum / 11;

    validateDate(date);
}

int main()
{
    int idNum[10] = {0};

    printf("Enter ID: ");
    for (int i = 0; i < 10; i++)
    {
        scanf(" %d", &idNum[i]);
    }

    checkID(idNum, 10);
    
}