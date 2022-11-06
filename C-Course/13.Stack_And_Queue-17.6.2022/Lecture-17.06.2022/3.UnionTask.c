#include <stdio.h>
#include <string.h>

union task
{
    int num;
    char str[10];
};

enum myEnum {num, str};

void printUTask(union task *myUnion, enum myEnum en);

int main()
{
    union task myTaskUnion;
    myTaskUnion.num = 5;
    strcpy(myTaskUnion.str, "Ivan");

    printUTask(&myTaskUnion, num);
    return 0;
}

void printUTask(union task *myUnion, enum myEnum en)
{
    if (en == num)
    {
        printf("%d \n", myUnion->num);
    }
    else
    {
        printf("%s \n", myUnion->str);
    }
}