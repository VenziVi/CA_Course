#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int num;
    char ch;
    struct node* next;
};

int main()
{
    struct node *head;
    struct node *curr;
    struct node *previous;

    head = malloc(sizeof(struct node));
    head->num = 0;
    head->ch = 'A';
    head->next = NULL;
    curr = head;

    for (int i = 0; i < 3; i++)
    {
        previous = curr;
        curr = malloc(sizeof(struct node));
        curr->num = i + 1;
        curr->ch = head->ch + i + 1;
        curr->next = NULL;
        previous->next = curr;
    }
    
    bool isExists = false;

    for (struct node *p = head; p != NULL; p = p->next)
    {
        if (p->ch == 'H')
        {
            printf("%d ,%c \n", p->num, p->ch);
            isExists = true;
        }
    }

    if (!isExists)
    {
        printf("Element doesn't exists.");
    }
    
    curr = head;
    struct node * temp;
    while (curr)
    {
        temp = curr;
        curr = curr->next;
        free(temp);
    }

    return 0;
}