#include <stdio.h>

struct student
{
    char firstName[10];
    int age;
    struct student *next;
};

int main()
{
    struct student student1 = {"Ivan", 22};

    struct student student2 = {"Georgi", 21};

    student1.next = &student2;

    printf("%s \n", student1.next->firstName);

    printf("%d", sizeof(student1));
}