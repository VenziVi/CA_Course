#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *str;
    int num;

} key_t;

int main()
{
    key_t some;

    printf("Enter size: ");
    scanf("%d", &some.num);
    some.str = malloc(some.num);
    
    printf("Enter string: ");
    scanf("%s", some.str);

    printf("%s, %d", some.str, some.num);
}