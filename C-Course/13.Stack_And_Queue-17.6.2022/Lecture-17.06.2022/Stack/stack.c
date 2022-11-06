#include "stack_.h"

stackPtr stackNewPtr = NULL;

int main()
{
    char option;
    int value;

    printf("\n Choose options: \n");
    printf("1. PUSH \n");
    printf("2. POP \n");
    printf("3. EXIT \n");


    while (1)
    {
        option = getchar();

        switch (option)
        {
        case '1':
            printf("Enter value: \n");
            scanf("%d", &value);
            push(&stackNewPtr, value);
            printValue(stackNewPtr);
            break;
        case '2':
            if (!checkEmpty(stackNewPtr))
            {
                pop(&stackNewPtr);
            }
            printValue(stackNewPtr);
            break;
        case '3':
            exit(0);

        }
    }
    
}