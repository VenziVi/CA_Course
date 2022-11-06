#include <stdio.h>

struct company
{
    struct employee
    {
        char name[20];
        int age;
    }employee1;
    char address[30];
};

int main()
{
    struct company CDC = {{"Ivan", 32}, "Plovdiv"};

    printf("%s \n", CDC.employee1.name);
    printf("%d \n", CDC.employee1.age);
    printf("%s \n", CDC.address);

}