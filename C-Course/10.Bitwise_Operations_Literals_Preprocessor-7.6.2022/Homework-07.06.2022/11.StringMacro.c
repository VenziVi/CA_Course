//  Напишете макрос, който прави идентификатор на
// низ (стринг)

#include <stdio.h>

#define GREETING(str) ("Hello " #str ", how are you?")

int main()
{
    char greeting[] = GREETING(Ivan);
    printf("%s \n", greeting);

    return 0;
}