// 8. Времето се задава във 12-часов формат AM или PM. Напишете функция, която по зададено
// време в такъв формат го конвертира във 24 -часов формат.
// 9. Note: - 12:00:00AM в 12-часов формат е 00:00:00 в 24-часов формат.
// - 12:00:00PM в 12-часов формат е 12:00:00 в 24-часов формат.
// Пример
// ● s = '12 : 01: 00PM'
// 8. Return '12:01:00'.
// ● s = '12 : 01: 00AM'
// 9. Return '00:01:00'.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *convertAMFormat(char input[]);
char *convertPMFormat(char input[]);

int main()
{
    char *convertdTime = NULL;
    char input[] = "01:25:34PM";

    char formatType = input[8];

    input[8] = '\0';

    if (formatType == 'P')
    {
        convertdTime = convertPMFormat(input);
    }
    else if (formatType == 'A')
    {
        convertdTime = convertAMFormat(input);
    }
    
    printf("%s", convertdTime);
}

char *convertAMFormat(char input[])
{
    char *time = strdup(input);
    char hh[3] = {input[0], input[1]};   

    if (strcmp(hh, "12") == 0)
    {
        time[0] = '0';
        time[1] = '0';
    }
    
    return time;
}

char *convertPMFormat(char input[])
{
    char *time = strdup(input);
    char hh[3] = {input[0], input[1]};
    int hour = atoi(hh);
    char secondDigit[1];

    if (hour > 0 && hour < 10)
    {
        hour = (hour + 12) % 10;
        time[0] = '1';
        itoa(hour, secondDigit, 10);
        time[1] = secondDigit[0];
    }
    else if (hour >= 10 && hour < 12)
    {
        hour = (hour + 12) % 10;
        time[0] = '2';
        itoa(hour, secondDigit, 10);
        time[1] = secondDigit[0];
    }
    
    return time;
}
