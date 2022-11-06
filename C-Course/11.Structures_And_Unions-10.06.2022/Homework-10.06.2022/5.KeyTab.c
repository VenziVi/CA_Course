// Задача 7.
// Напишете масив от структури наречен key_tab[ ], като използвате тази,
// дефинирана в горното упражнение - потребителски тип key_t, която
// съдържа символен низ и число. Инициализирайте масива с всички
// ключови думи на С, като заделяте паметта за всяка ключова дума
// динамично. Принтирайте масива.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int length;
    char *word;

} key_t;

typedef key_t *key_tab;

int main()
{
    const int testSize = 32;
    char test[32][10] = {{"auto"}, {"const"}, {"double"}, {"float"}, {"int"}, {"short"},
                        {"struct"}, {"unsigned"}, {"breack"}, {"continue"}, {"else"}, {"for"},
                        {"long"}, {"signed"}, {"switch"}, {"void"}, {"case"}, {"defaut"},
                        {"enum"}, {"goto"}, {"register"}, {"seizeof"}, {"typedef"}, {"volatile"},
                        {"char"}, {"do"}, {"extern"}, {"if"}, {"return"}, {"static"}, {"union"}, {"while"}};

    key_tab arr = malloc(sizeof(key_t));
    int size = 0;

    for (int i = 0; i < testSize; i++)
    {
        size = strlen(test[i]);
        arr = realloc(arr, sizeof(key_t) * (i + 1));

        arr[i].length = size;
        arr[i].word = malloc(size + 1);
        strcpy(arr[i].word, test[i]);
    }


    for (int i = 0; i < testSize; i++)
    {
        printf("%d -> Word: %s, Size: %d \n", i + 1, arr[i].word, arr[i].length);
    }
    
    for (int i = 0; i < testSize; i++)
    {
        free(arr[i].word);
    }
    
    free(arr);
    return 0;
}