// Използвайте динамична реализация на стек за въвеждане на поредица от цели положителни
// числа и нейното извеждане върху екрана в обратен ред. За край на поредицата от
// клавиатурата се въвежда 0.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    size_t value;
    struct node *next;
} node;

typedef node *stack;


bool push(stack *myStack, size_t value);
size_t pop(stack *myStack);
size_t getValue(void);
char menu(void);
void pushInStack(stack *stacknode);
void printStack(stack *stackNode);


int main()
{
    stack myStack = NULL;
    char operation = menu();

    while (operation != '0')
    {
        if (operation == '1')
        {
            pushInStack(&myStack);
        }
        else if (operation == '2')
        {
            printStack(&myStack);
        }

        operation = menu();
    }
    
    printStack(&myStack);
    return 0;
}

void pushInStack(stack *stacknode)
{
    size_t value = getValue();

    (push(stacknode, value)) ?
        printf("%I64d is added successfully.\n", value) :
        printf("Not enough memory!\n");
}

bool push(stack *myStack, size_t value)
{
    node *newNode = malloc(sizeof(node));

    if (newNode == NULL)
    {
        return false;
    }

    newNode->value = value;
    newNode->next = *myStack;
    *myStack = newNode;

    return true;
}

size_t pop(stack *myStack)
{
    size_t result = 0;
    node *tempNode = NULL;

    if (*myStack == NULL)
    {
        return 0;
    }

    result = (*myStack)->value;

    tempNode = *myStack;
    *myStack = (*myStack)->next;
    free(tempNode);

    return result;
}

size_t getValue(void)
{
    size_t value = 0;

    printf("Enter value: ");
    scanf("%I64d", &value);

    return value;
}

char menu(void)
{
    char operation = 0;

    printf("\nSelect: 1 --> Push, 2 --> Print, 0 --> Quit \n");

    scanf(" %c", &operation);

    return operation;
}

void printStack(stack *stackNode)
{
    size_t popResult = 0;

    printf("\nStack: ");

    while ((popResult = pop(stackNode)) != 0)
    {
        printf("%I64d \t", popResult);
    }

    printf("\n");
}
