#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee
{
    int id;
    char name[20];
    int age;
    struct employee *boss;
};

int main()
{
    struct employee boss = {1, "Pavel", 30};

    struct employee employees[5];
    
    for (int i = 0; i < 5; i++)
    {
        employees[i].id = i + 1;
        printf("Enter name: ");
        scanf("%s", employees[i].name);
        printf("Enter grade: ");
        scanf("%d", &employees[i].age);

        employees[i].boss = &boss;
        
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("ID: %d, Name: %s, Age: %d, Boss: %s \n", employees[i].id, employees[i].name, employees[i].age, employees[i].boss->name);
    }

}