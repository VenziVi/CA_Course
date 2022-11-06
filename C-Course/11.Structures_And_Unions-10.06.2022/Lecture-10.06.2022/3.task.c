#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct car
{
    char make[20];
    char model[20];
};

char* menu(char msg[])
{
    char * result = malloc(20);
    printf("%s \n", msg);
    scanf("%s", result);
    return result;
}

int main()
{
    char* make = menu("Enter make: ");
    char* model = menu("Enter model: ");

    struct car car1;

    struct car* carPtr = &car1;

    strcpy(carPtr->make, make);
    strcpy(carPtr->model, model);

    printf("%s \n", car1.make);
    printf("%s \n", car1.model);

}

