// В стек са записани няколко думи, чийто брой не е известен. Да се напише
// програма, която прочита дума, въведена от клавиатурата и проверавя дали
// тази дума е записана в стека

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
    char *word;
    struct node *next;
} node;

typedef node *stack;

bool push(stack *stackNode, char *word);
char *pop(stack *stackNode);
void printStack(stack *stackNode);
bool searchWordInStack(stack *stacknode, char searchedWord[]);

int main()
{
    stack myStack = NULL;
    const size_t testSize = 6;
    char testWords[][7] = {"ivan", "Gosho", "Stefan", "Peter", "Dimo", "Kiro"};
    char searchedWord[10] = "Stefan";

    for (size_t i = 0; i < testSize; i++)
    {
        (push(&myStack, testWords[i])) ?
            printf("%s is added successfully.\n", testWords[i]) :
            printf("Not enough memory!\n");
    }

    (searchWordInStack(&myStack, searchedWord)) ? 
        printf("\nWord %s has been found. \n", searchedWord) :
        printf("\nWord not fount! \n");

    printStack(&myStack);

    return 0;
}

bool searchWordInStack(stack *stacknode, char searchedWord[])
{
    char *popResult = NULL;

    while ((popResult = pop(stacknode)) != NULL)
    {
        if (strcmp(popResult, searchedWord) == 0)
        {
            return true;
        }
    }

    return false;
}

bool push(stack *stackNode, char *word)
{
    node *newNode = malloc(sizeof(node));

    if (newNode == NULL)
    {
        return false;
    }

    newNode->word = word;
    newNode->next = *stackNode;
    *stackNode = newNode;
    
    return true;
}

char *pop(stack *stackNode)
{
    char *result = NULL;
    node *tempNode = NULL;

    if (*stackNode == NULL)
    {
        return NULL;
    }

    result = (*stackNode)->word;
    tempNode = *stackNode;
    *stackNode = (*stackNode)->next;

    free(tempNode);
    return result;
}

void printStack(stack *stackNode)
{
    char *popResult = NULL;

    printf("Words left: ");
    while((popResult = pop(stackNode)) != NULL)
    {
        printf("%s \t", popResult);
    }
}