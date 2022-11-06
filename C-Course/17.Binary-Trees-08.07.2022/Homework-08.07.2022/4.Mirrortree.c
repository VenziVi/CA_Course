//Задача 4. Ако е дадено двоично дърво, да се получи неговото огледално.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left; 
    struct node *right;
} node;

void inOrder(node *root);
node *createNode(int data);
void mirrorTree(node *root);

int main()
{
    node *root = createNode(1);
    root->left = createNode(3);
    root->right = createNode(2);
    root->right->left = createNode(5);
    root->right->right = createNode(4);

    printf("\nroot        : ");
    inOrder(root);

    mirrorTree(root);

    printf("\nmirror root : ");
    inOrder(root);

    return 0;
}

void mirrorTree(node *root)
{
    node* tempNode = NULL;

    if (root == NULL)
    {
        return;
    }
    else
    {
        mirrorTree(root->left);
        mirrorTree(root->right);

        tempNode = root->left;
        root->left = root->right;
        root->right = tempNode;
    }
}

node *createNode(int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}