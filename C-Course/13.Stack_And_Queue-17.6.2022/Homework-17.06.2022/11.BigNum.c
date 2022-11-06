// Напишете програма, която въвежда едно голямо цяло число,
// записано в масив и като използвате стек и опашка запишете
// това число в обратен ред, четено отзад напред

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_EMPTY CHAR_MIN

typedef struct node
{
    char value;
    struct node *next;
} node;

typedef node *stack;

node *createNode(char value);
bool push(stack *stackNode, char value);
char pop(stack *stackNode);
char *readNumber(void);
void printStack(stack *stackNode);

int count;

int main()
{
    stack myStack = NULL;
    char *numArr = readNumber();

    for (int i = 0; i < count; i++)
    {
        (push(&myStack, numArr[i])) ?
            printf("%c pushed in stack successfully! \n", numArr[i]):
            printf("Not enough memory! \n");
    }

    printStack(&myStack);

    free(numArr);
    return 0;
}

bool push(stack *stackNode, char value)
{
    node *newNode = malloc(sizeof(node));

    if (newNode == NULL)
    {
        return false;
    }
    
    newNode->value = value;
    newNode->next = *stackNode;
    *stackNode = newNode;
    
    return true;
}

char pop(stack *stackNode)
{
    node *tempNode = NULL;
    char result = 0;

    if (*stackNode == NULL)
    {
        return STACK_EMPTY;
    }

    result = (*stackNode)->value;
    tempNode = *stackNode;
    *stackNode = (*stackNode)->next;

    free(tempNode);
    
    return result;
}

void printStack(stack *stackNode)
{
    char popResult = 0;

    printf("Result: ");
    while ((popResult = pop(stackNode)) != STACK_EMPTY)
    {
        printf("%c", popResult);
    }
}

char *readNumber(void)
{
    char *arr = malloc(20);
    count = 0;
    char num = 0;

    printf("Enter number: ");

    while ( (num = getchar()) != '\n')
    {
        arr[count++] = num;
    }
    
    return arr;
}
