// Задача 9. Представете служителите във фирма в
// структура с членове: пореден номер, име, презиме, фамилия, позиция,
// трудов стаж в години, заплата в лева, указател към структурата, описващ
// неговия началник. Напишете програма, която въвежда 10 служителя, които
// се съхраняват в масив от описаните структури. След като въведете всички
// служители, задайте началник за всеки от тях. В решението трябва да се
// използва динамично заделяне на памет и typedef.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct emp_s
{
    int id;
    char firstName[10];
    char secondName[10];
    char lastName[10];
    char role[20];
    int experience;
    float salary;
    struct emp_s *boss;
} emp_s;

typedef emp_s *emp_arr;

emp_s* setEmployees(int size);
int findBoss(emp_s employees[], int size);
void setEmployeeBoss(emp_s employees[], int size, int bossId);
void printEmployeesInfo(emp_s employees[], int size);

int main()
{
    int const size = 5;
     
    emp_arr employees = setEmployees(size);

    int bossId = findBoss(employees, size);

    setEmployeeBoss(employees, size, bossId);

    printEmployeesInfo(employees, size);

    free(employees);

    return 0;
}

emp_s* setEmployees(int size)
{
    char furstNamesTest[5][10] = {{"Ivan"}, {"Stoqn"}, {"Gosho"}, {"Kiro"}, {"Peter"}};
    char secNameTest[5][10] = {{"Stoqnov"}, {"Ivanov"}, {"Georgiev"}, {"Dimov"}, {"Welkov"}};
    char lastNameTest[5][10] = {{"Ganchev"}, {"Milev"}, {"Gydev"}, {"Nikolov"}, {"Nqkoisi"}};
    char roleTest[5][20] = {{"zetq"}, {"Skatavka"}, {"nistho ne pravi"}, {"Shef4e"}, {"moje poveche"}};
    int expTest[5] = {10, 5, 3, 20, 21};
    int salaryTest[5] = {1200, 1324, 980, 3000, 1500};

    emp_s *employees = malloc(sizeof(emp_s) * size);

    for (int i = 0; i < size; i++)
    {
        employees[i].id = i + 1;
        strcpy(employees[i].firstName, furstNamesTest[i]);
        strcpy(employees[i].secondName, secNameTest[i]);
        strcpy(employees[i].lastName, lastNameTest[i]);
        strcpy(employees[i].role, roleTest[i]);
        employees[i].experience = expTest[i];
        employees[i].salary = salaryTest[i];
    }

    return employees; 
}

void setEmployeeBoss(emp_s emp[], int size, int bossId)
{
    for (int i = 0; i < size; i++)
    {
        emp[i].boss = &emp[bossId - 1];
    }
}

int findBoss(emp_s employees[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(employees[i].role, "Shef4e") == 0)
        {
            return employees[i].id;
        }
    }

    return 0;
}

void printEmployeesInfo(emp_s employees[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("First name: %s \nSecond name: %s \nLast name: %s \nRole: %s \nExperience: %d \nSalary: %.2f \nBoss Id: %d \n",
            employees[i].firstName, 
            employees[i].secondName,
            employees[i].lastName, 
            employees[i].role,
            employees[i].experience, 
            employees[i].salary, 
            employees[i].boss->id);
            
        printf("\n");
    }
}