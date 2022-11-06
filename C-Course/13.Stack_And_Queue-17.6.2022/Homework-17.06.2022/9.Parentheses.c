// Като използвате стек, напишете програма, която проверява
// дали в едни аритметичен израз, записан чрез стринг, на всяка
// отваряща скоба отговаря затваряща. Проверете за трите вида
// скоби ( ), [ ], { } .

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_EMPTY CHAR_MIN

typedef struct node
{
    char ch;
    struct node *next;
} node;

typedef node *stack;

bool push(stack *stackNode, char data);
char pop(stack *stacknode);
bool checkAreBalancedParentheses(stack *stackNode);

int main()
{
    stack myStack = NULL;
    const size_t testSize = 6;
    const size_t testCount = 5;
    const char test[][6] = {
        {'(', '{', '[', ']', '}', ')'}, //balanced
        {'(', ')', '[', ']', '{', '}'}, //balanced
        {'(', '}', '{', ']', '}', ')'}, // not
        {'(', '(', '[', ']', '}', ')'}, // not
        {')', '{', '[', ']', '}', ')'}  // not
    };

    for (size_t i = 0; i < testCount; i++)
    {

        for (size_t j = 0; j < testSize; j++)
        {
            if (push(&myStack, test[i][j]) == false)
            {
                printf("Not enough memory!\n");
            }
        }

        (checkAreBalancedParentheses(&myStack)) ? 
            printf("\nParentheses are balanced!\n") :
            printf("\nParentheses are NOT balanced!\n");        

    }

    return 0;
}

bool checkAreBalancedParentheses(stack *StackNode)
{
    char popResult = 0;
    int oc = 0;
    int cc = 0;
    int ok = 0; 
    int ck = 0; 
    int os = 0; 
    int cs = 0;  

    while ((popResult = pop(StackNode)) != STACK_EMPTY)
    {
        switch (popResult)
        {
        case '(':
            oc++;
            break;
        case ')':
            cc++;
            break;
        case '{':
            ok++;
            break;
        case '}':
            ck++;
            break;
        case '[':
            os++;
            break;
        case ']':
            cs++;
            break;
        default:
            break;
        }

        if (cc < oc || ck < ok || cs < os)
        {
            return false;
        }
    }
    
    if (oc == cc && ok == ck && os == cs)
    {
        return true;
    }
    
    return false;
}

bool push(stack *stackNode, char data)
{
    node *newNode = malloc(sizeof(node));

    if (newNode == NULL)
    {
        return false;
    }

    newNode->ch = data;
    newNode->next = *stackNode;
    *stackNode = newNode;
    
    return true;
}

char pop(stack *stacknode)
{
    char result = 0;
    node *tempNode = NULL;

    if (*stacknode == NULL)
    {
        return STACK_EMPTY;
    }
    
    result = (*stacknode)->ch;
    tempNode = *stacknode;
    *stacknode = (*stacknode)->next;

    free(tempNode);
    return result;
}
