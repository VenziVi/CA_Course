#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
     struct node *prev;
}TDList;

int main()
{
    TDList *start = NULL;
    TDList *current = NULL;
    TDList *temp = NULL;

    current = (TDList*)malloc(sizeof(TDList));

    if (current == NULL)
    {
        printf("No enought memory.");
        return 1;
    }

    if (start == NULL)
    {
        current->val = 0;
        current->next = NULL;
        current->prev = NULL;
        start = current;
    }
    else
    {
        temp = start;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
    
        current->val = 0;
        current->next = NULL;
        current->prev = temp;
        temp->next = current;
    }

    for (TDList *p = start; p != NULL; p = p->next)
    {
        printf("%d \n", p->val);
    }

}