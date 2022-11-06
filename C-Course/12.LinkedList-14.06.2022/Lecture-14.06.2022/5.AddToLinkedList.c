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

//add in the begining
    struct node *temp1;
    temp1 = malloc(sizeof(struct node));
    if (temp1 == NULL)
    {
        printf("Out of memory!");
        return -1;
    }

    temp1->num = -1;

    if (head == NULL)
    {
        head = temp1;
    }
    else
    {
        temp1->next = head;
        head = temp1;
    }
//----------------------------------------  
 
//Add in the end   
    struct node *temp2;
    struct node *ptr;
    temp2 = malloc(sizeof(struct node));

    if (temp2 == NULL)
    {
        printf("Out of memory!");
        return -1;
    }

    temp2->num = 999;
    temp2->next = NULL;

    if (head == NULL)
    {
        head = temp2;
    }
    else
    {
        ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp2;
    }
    
//--------------------------------------------    

    for (struct node *p = head; p != NULL; p = p->next)
    {
        printf("%d \n", p->num);
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