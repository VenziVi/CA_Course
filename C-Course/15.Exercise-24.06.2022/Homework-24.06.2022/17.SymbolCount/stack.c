#include "stack.h"

bool push(stack *stackNode, char *word)
{
    node *newNode = malloc(sizeof(node));

    if (newNode == NULL)
    {
        return false;
    }

    newNode->word = word;
    newNode->next = NULL;

    if (*stackNode == NULL)
    {
        *stackNode = newNode;
        return true;
    }
    
    newNode->next = *stackNode;
    *stackNode = newNode;
    
    return true;
}

char* pop(stack *stackNode)
{
    node *tempNode = NULL;
    char *popResult = NULL;

    if (*stackNode == NULL)
    {
        return NULL;
    }

    popResult = (*stackNode)->word;

    tempNode = *stackNode;
    *stackNode = (*stackNode)->next;

    free(tempNode);
    return popResult;
}

void printStack(stack *stacknode)
{
    node *tempNode = *stacknode;

    while (tempNode != NULL)
    {
        printf("%s ", tempNode->word);
        tempNode = tempNode->next;
    }
    printf("\n");
}

void deinitStack(stack *stackNode)
{
    node *tempNode = *stackNode;
    node *nextNode = NULL;

    while (tempNode != NULL)
    {
        nextNode = tempNode->next;
        free(tempNode);
        tempNode = nextNode;
    }
}

char* maxSymbolWord(stack *stackNode, int maxSymbols)
{
    int symbolsCount = 0;
    char *popedWord = NULL;
    int index = 0;

    while (symbolsCount < maxSymbols)
    {
        popedWord = pop(stackNode);

        if (popedWord == NULL)
        {
            return NULL;
        }

        while (popedWord[index] != '\0')
        {
            symbolsCount++;
            index++;
        }
        
        index = 0;
    }
    
    return popedWord;
}

int allSymbolsCount(stack *stackNode)
{
    int symbolsCount = 0;
    char *popedWord = pop(stackNode);
    int index = 0;

    while (popedWord != NULL)
    {
        while (popedWord[index] != '\0')
        {
            symbolsCount++;
            index++;
        }
        
        index = 0;
        popedWord = pop(stackNode);
    }

    return symbolsCount;
}

void printCurrenrSymbolWord(stack *stackNode, int command)
{
    int symbol = command;
    char *word = maxSymbolWord(stackNode, symbol);

    if (word == NULL)
    {
        printf("NOT ENOUGH WORDS!");
    }
    else
    {
        printf("\nSymbol %d is at word: %s \n", symbol, word);
    }
}

int menu(void)
{
    int function = 0;
    int symbol = 0;

    printf("\nChoose function: ");
    printf("\n 1 --> all symbols count");
    printf("\n 2 --> current symbol position \n");
    scanf("%d", &function);

    if (function == 1)
    {
        return -1;
    }
    else if (function == 2)
    {
        printf("Enter symbol position: ");
        scanf("%d", &symbol);

        return symbol;
    }
    else
    {
        printf("INVALID OPERATION!");
    }
    
    return 0;
}