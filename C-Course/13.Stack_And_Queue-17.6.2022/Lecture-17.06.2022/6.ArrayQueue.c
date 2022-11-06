#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int queue[MAX];
int front = 0, rear = 0, size = 0;

void enqueue(int data)
{
    if (size == MAX)
    {
        printf("FULL \n");
        return;
    }
    else
    {
        queue[rear] = data;
        rear = (rear + 1) % MAX;
        size++;
        printf("Data inserted. \n");
    }   
}

void dequeue()
{
    if (rear == front)
    {
        printf("Empty");
        return;
    }
    else
    {
        printf("Deleted %d \n", queue[front]);
        front = (front + 1) % MAX;
        size--;
    }
}

void display()
{
    int i = 0;
    if (front == rear)
    {
        printf("Empty \n");
        return;
    }
    else
    {
        //???????????????????????????????
        if (rear < front)
        {
            for (int i = rear; i < front; i++)
            {
                printf("%d \t", queue[i]);
            }
        }
        else
        {
            for (int i = front; i < rear; i++)
            {
                printf("%d \t", queue[i]);
            }
        }

        printf("\n");
    }
}

char menu()
{
    char ch;
    //system("clear");
    printf("\n ... Queue operations: ");
    printf("\n 1. Enqueue");
    printf("\n 2. Dequeue");
    printf("\n 3. Display");
    printf("\n 4. Quit");
    printf("\n Enter your choise: ");
    ch = getchar();
    return ch;
}

int main()
{
    char ch;
    int data = 0;

    do
    {
        ch = menu();
        switch (ch)
        {
        case '1':
            printf("enter data: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case '2':
            dequeue();
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