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
    head = malloc(sizeof(struct node));

    head->num = 1;
    head->next = NULL;

    struct node *curr;
    curr = malloc(sizeof(struct node));
    curr->num = 2;
    curr->next = NULL;

    head->next = curr;

    for (struct node *p = head; p != NULL; p = p->next)
    {
        printf("%d \n", p->num);
    }
}