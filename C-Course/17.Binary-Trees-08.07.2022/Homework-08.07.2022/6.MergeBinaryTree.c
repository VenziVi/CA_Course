#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left; 
    struct node *right;
} node;

void inorder(node *root);
node *createNode(int data);
node *mergeBinaryTrees(node *firstRoot, node *secondRoot);

int main()
{
    node *firstRoot = createNode(1);
    firstRoot->left = createNode(5);
    firstRoot->right = createNode(3);
    firstRoot->left->left = createNode(8);

    printf("\nfirstRoot : ");
    inorder(firstRoot);

    node *secondRoot = createNode(7);
    secondRoot->left = createNode(11);
    secondRoot->right = createNode(4);
    secondRoot->right->right = createNode(22);

    printf("\nsecondRoot: ");
    inorder(secondRoot);

    node *mergedRoot = mergeBinaryTrees(firstRoot, secondRoot);

    printf("\nmergedRoot: ");
    inorder(mergedRoot);

    return 0;
}

node *mergeBinaryTrees(node *firstRoot, node *secondRoot)
{
    if (firstRoot == NULL)
    {
        return secondRoot;
    }

    if (secondRoot == NULL)
    {
        return firstRoot;
    }

    node *newNode = malloc(sizeof(node));

    newNode->data = firstRoot->data + secondRoot->data;
    newNode->left = mergeBinaryTrees(firstRoot->left, secondRoot->left);
    newNode->right = mergeBinaryTrees(firstRoot->right, secondRoot->right);
    
    return newNode;
}

node *createNode(int data)
{
    node *newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}