#include <stdio.h>

typedef struct
{
    int id;
    int age;
    
} std;

int main()
{
    std students[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Enter id: ");
        scanf("%d", &students[i].id);
        printf("Enter age: ");
        scanf("%d", &students[i].age);
    }
    
    for (int i = 0; i < 3; i++)
    {
        printf("Id: %d, Age: %d \n", students[i].id, students[i].age);
    }
}