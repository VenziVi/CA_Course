#include <stdio.h>
#include <stdlib.h>


#define MAX 6

int stack[MAX];
int top = 0;

int menu()
{
    int ch;
    //system("cls");
    printf("\e[1;1H\e[2J"); // system clear
    printf("\n ... Stack operations: ");
    printf("\n 1. push");
    printf("\n 2. pop");
    printf("\n 3. display");
    printf("\n 4. quit");
    printf("\n Enter your choise: ");

    scanf("%d ", &ch);
    return ch;

}

void push(int data)
{
    if (top == MAX)
    {
        return;
    }

    stack[top] = data;
    top = top + 1; 
}

void pop()
{
    if (top == 0)
    {
        return;
    }

    printf("number is %d \n", stack[--top]);
}

void display()
{
    if (top == 0)
    {
        return;
    }

    for (int i = 0; i < top; i++)
    {
       printf("\t %d", stack[i]);
    }
}

int main()
{
    int data = 5;
    int ch;

    do
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        
        default:
            break;
        }

        char c = getchar();

    } while (1);
    
}