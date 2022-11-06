#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[20];
    float grade;
};

int main()
{
    struct student students[5];
    
    for (int i = 0; i < 5; i++)
    {
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter grade: ");
        scanf("%f", &students[i].grade);
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("Name: %s, Grade: %f \n", students[i].name, students[i].grade);
    }

}