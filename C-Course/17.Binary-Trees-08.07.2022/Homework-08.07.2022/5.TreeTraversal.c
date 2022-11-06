// Задача 5. Да се напише рекурсивен вариант на функцията за обхождане на
// двоично дърво.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

node *createNode(int value);
void inorderTraversal(node *root);
void preorderTraversal(node* root);
void postorderTraversal(node* root);
node *insert(node *node, int value);
node *createTree(int *arr, int size);

int main()
{
    int fArr[] = {31, 35, 13, 28, 65, 42, 7, 2};
    int fArrSize = sizeof(fArr) / sizeof(int);
    node* root = createTree(fArr, fArrSize);


    printf("\nInorder: ");
    inorderTraversal(root);

    printf("\nPostorder: ");
    postorderTraversal(root);

    printf("\nPreorder: ");
    preorderTraversal(root);

    return 0;
}

node *insert(node *node, int value)
{
    if (node == NULL)
    {               
        return createNode(value);
    }

    if (value < node->data)
    {
        node->left = insert(node->left, value);
    }
    else
    {
        node->right = insert(node->right, value);
    }
    
    return node;
}

node *createNode(int value)
{
    struct node* newNode = malloc(sizeof(node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

node *createTree(int *arr, int size)
{
    node* root = NULL;

    for (int i = 0; i < size; i++)
    {
        root = insert(root, arr[i]);
    }

    return root;
}