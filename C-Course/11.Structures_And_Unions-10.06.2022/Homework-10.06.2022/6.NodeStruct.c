// Задача 8. Напишете собствен тип за структура node, съдържаща
// един член от тип int и един указател към тип самата структура. Заделете
// динамично памет за масив от 10 елемента от тази структура с malloc. За
// всеки елемент от масива попълнете цялото число с неговия пореден номер.
// Принтирайте резултатите.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *ptr;

} node;

int main()
{
    const int size = 10;

    node *numbers = malloc(sizeof(node) * size);

    for (int i = 0; i < size; i++)
    {
        numbers[i].num = i;
        numbers[i].ptr = &numbers[i];
    }

    for (int i = 0; i < size; i++)
    {
        printf("Num: %d, ptr: %p \n", 
                numbers[i].num,
                numbers[i].ptr);
    }
    
    free(numbers);
    return 0;
}