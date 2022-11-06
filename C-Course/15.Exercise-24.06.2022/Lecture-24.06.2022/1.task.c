#include "stack.h"

int main()
{
    stack myStack = NULL;
    stack secStack = NULL;
    push(&myStack, 5);
    push(&myStack, 15);
    push(&myStack, 25);

    push(&secStack, 64);
    push(&secStack, 85);
    push(&secStack, 25);

    int result = pop(&myStack);

    printf("result = %d \n", result);

    display(&myStack);
    printf("\n");
    display(&secStack);
    printf("\n");
}