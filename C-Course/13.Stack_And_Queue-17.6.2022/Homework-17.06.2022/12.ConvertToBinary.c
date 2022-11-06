// Като използвате стек, напишете програма, която прочита едно
// цяло положително число и преобразува това число в двоична
// бройна система, т.е. записва го в двоичен вид

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_EMPTY CHAR_MAX

typedef struct node
{
    char value;
    struct node *next;
} node;

typedef node *stack;

bool push(stack *stackNode, char value);
size_t getValue(void);
size_t pop(stack *stackNode);
void convertToBinary(stack *stackNode, size_t number);
void printStack(stack *stacknode);

int main()
{
    stack myStack = NULL;
    size_t number = getValue();

    convertToBinary(&myStack, number);
    printStack(&myStack);

    return 0;
}

void convertToBinary(stack *stackNode, size_t number)
{
    char binary = 0;
    size_t numToConvert = number;
    while (numToConvert > 0)
    {
        binary = numToConvert % 2;
        push(stackNode, binary);
        numToConvert /= 2;
    }
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

size_t pop(stack *stackNode)
{
    char result = 0;
    node *tempNode = NULL;

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

void printStack(stack *stacknode)
{
    char popResult = 0;

    printf("Binary: ");
    while((popResult = pop(stacknode)) != STACK_EMPTY)
    {
        printf("%d", popResult);
    }
}

size_t getValue(void)
{
    size_t value = 0;

    printf("Enter value: ");
    scanf("%I64d", &value);

    return value;
}
