#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node* next;
};

int main()
{
    struct node *head;
    struct node *curr;
    struct node *previous;

    head = malloc(sizeof(struct node));
    head->num = 0;
    head->next = NULL;
    curr = head;

    for (int i = 0; i < 3; i++)
    {
        previous = curr;
        curr = malloc(sizeof(struct node));
        curr->num = i + 1;
        curr->next = NULL;
        previous->next = curr;
    }
    

    for (struct node *p = head; p != NULL; p = p->next)
    {
        printf("%d \n", p->num);
    }
}