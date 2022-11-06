#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};

void push();
void pop();
void display();

typedef struct stack node;
node *start = NULL;
node *top = NULL;

node *createNode()
{
    node *temp = NULL;
    temp = malloc(sizeof(node));

    printf("Enter data: \n");
    scanf("%d", &temp->data);

    temp->next = NULL;
    return temp;
}


void push(node *newNode)
{
    node *temp = NULL;
    if (newNode == NULL)
    {
        printf("Stack overflow..");
        return;
    }

    if (start == NULL)
    {
        start = newNode;
        top = newNode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        top = newNode;
    }

    printf("\n\n\t Data pushed into stack.");  
}

void pop()
{
    node *temp = NULL;

    if (top == NULL)
    {
        printf("\n\n\t stack underflow..");
        return;
    }

    temp = start;

    if (start->next == NULL)
    {
        printf("\n\n\t Popped element = %d", top->data);
        start = NULL;
        free(top);
        top = NULL;
    }
    else
    {
        while (temp->next != top)
        {
            temp = temp->next;
        }
        
        temp->next = NULL;
        printf("\n\n\t Popped element = %d", top->data);
        free(top);
        top = temp;
    }
}

void display()
{
    node *temp = NULL;

    if (top == NULL)
    {
        printf("\n\n\t Stack is empty!");
    }
    else
    {
        temp = start;
        printf("%d \n", temp->data);
        while (temp != top)
        {
            temp = temp->next;
            printf("%d \n", temp->data);
        }
    }
}

char menu()
{
    char ch;
    //system("clear");
    printf("\n ... Stack operations: ");
    printf("\n 1. push");
    printf("\n 2. pop");
    printf("\n 3. display");
    printf("\n 4. quit");
    printf("\n Enter your choise: ");
    ch = getchar();
    return ch;
}

int main()
{
    char ch;
    node *newNode = NULL;

    do
    {
        ch = menu();
        switch (ch)
        {
        case '1':
            newNode = createNode();
            push(newNode);
            break;
        case '2':
            pop();
            break;
        case '3':
            display();
            break;
        case '4':
            exit(0);
            break;
        
        default:
            break;
        }

        char c = getchar();

    } while (1);
}