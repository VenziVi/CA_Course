#include <stdio.h>
#include <stdlib.h>

struct node{
    int position;
    struct node* next;
};

int main()
{
    struct node *head;
    struct node *curr;
    struct node *previous;
    struct node *ptr;
    struct node *ptr_print;

    head = malloc(sizeof(struct node));
    head->position = 0;
    head->next = NULL;
    curr = head;

    for (int i = 0; i < 9; i++)
    {
        previous = curr;
        curr = malloc(sizeof(struct node));
        curr->position = i + 1;
        curr->next = NULL;
        previous->next = curr;
    }

    ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = head;

    ptr_print = head;
    for (int i = 0; i < 10; i++)
    {
        printf("%d \n", ptr_print->position);
        ptr_print = ptr_print->next;
    }

    int pos = 1;

    struct node *prev;
    for (struct node *p = head; p != NULL; p = p->next)
    {
        
        printf("Curr position = %d \n", p->position);

        if (pos % 2 == 0)
        {
            struct node *ptr;

            ptr = p;
            p = p->next;
            prev->next = p;

            printf("Deleted -> %d \n", ptr->position);
            free(ptr);
        }   
        prev = p;
        pos++;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%d \n", ptr_print->position);
        ptr_print = ptr_print->next;
    }
    
}