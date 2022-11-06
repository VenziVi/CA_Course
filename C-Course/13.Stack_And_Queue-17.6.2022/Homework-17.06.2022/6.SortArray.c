// Дадени с два стека с числа и числата в тях са сортирани във низходящ
// ред отдолу нагоре.Да се напише програма на C, която слива двата стека в
// сортиран масив

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_EMPTY INT_MIN

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef node *stack;

bool push(stack *stackNode, int value);
int pop(stack *stackNode);
void printArray(int arr[], int size);
void setStack(stack *stack, const int arr[], int size);
void setSortedArray(int arr[], int size, stack *firstStack, stack *secondStack);


int main()
{
    stack firstStack = NULL;
    stack secondStack = NULL;

    const int stackSize = 6;
    const int arrSize = 12;
    int arr[12] = {0};

    const int firstStackData[] = {5, 9, 12, 14, 19, 25};
    const int secondStackData[] = {2, 6, 15, 17, 21, 23};

    setStack(&firstStack, firstStackData, stackSize);
    setStack(&secondStack, secondStackData, stackSize);

    setSortedArray(arr, arrSize, &firstStack, &secondStack);

    printArray(arr, arrSize);
    
    return 0;
}

void setSortedArray(int arr[], int size, stack *firstStack, stack *secondStack)
{
    int firstNum = pop(firstStack);
    int secondNum = pop(secondStack);

    for (int i = 0; i < size; i++)
    {
        if (firstNum > secondNum)
        {
            arr[i] = firstNum;
            firstNum = pop(firstStack);
        }
        else
        {
            arr[i] = secondNum;
            secondNum = pop(secondStack);
        }
    }
}

bool push(stack *stackNode, int value)
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

int pop(stack *stackNode)
{
    node *tempNode = NULL;
    int result = 0;

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

void setStack(stack *stack, const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        (push(stack, arr[i])) ?
            printf("%d pushed in stack successfully! \n", arr[i]):
            printf("Not enough memory! \n");
    }
}

void printArray(int arr[], int size)
{
    printf("\nSorted array: ");

    for (int i = 0; i < size; i++)
    {
        printf("%d \t", arr[i]);
    }

    printf("\n");
}