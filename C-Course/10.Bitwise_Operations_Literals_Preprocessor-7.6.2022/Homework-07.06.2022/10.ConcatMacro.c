// Напишете макрос, който свързва два
// идентификатора в един общ (конкатениране на
// идентификатори)

#include <stdio.h>

#define CONCAT(x, y) x##y

int main()
{
    printf("%d", CONCAT(20, 22));

    return 0;
}