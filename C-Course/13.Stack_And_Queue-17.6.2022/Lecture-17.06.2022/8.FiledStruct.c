#include <stdio.h>
#include <string.h>

struct task 
{
    int num;
    int bitNum : 1;
    int bitNum2 : 2;

    union
    {
        int val;
        char str[10];
    };
};

int main()
{
    struct task myStruct;

    myStruct.num = 5;
    myStruct.bitNum = 1;
    myStruct.bitNum2 = 2;

    myStruct.val = 12;
    strcpy(myStruct.str, "Ivan");

    printf("%d \n", sizeof(myStruct));
    printf("%d \n", myStruct.num);
    printf("%d \n", myStruct.bitNum);
    printf("%d \n", myStruct.bitNum2);
    printf("%d \n", myStruct.val);
    printf("%s \n", myStruct.str);
}