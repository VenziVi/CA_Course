// Задача 7. Да се построи наредено двоично дърво за
// търсене чрез последователно добавяне на следните
// върхове:

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node* left;
    struct node* right;
} node;

node* createNode(int value)
{
    node* newNode = malloc(sizeof(node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inorderedTraversal(node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    inorderedTraversal(root->left);
    printf("%d ", root->value);
    inorderedTraversal(root->right);
}

node* insertElement(node* node, int value)
{
    if (node == NULL)
    {               
        return createNode(value);
    }

    if (value < node->value)
    {
        node->left = insertElement(node->left, value);
    }
    else
    {
        node->right = insertElement(node->right, value);
    }
    
    return node;
}

int main()
{
    int fArr[13] = {7, 14, 28, 35, 65, 12, 18, 42, 81, 64, 61, 4, 13};
    int fArrSize = sizeof(fArr) / sizeof(int);

    node* rootA = NULL;

    for (int i = 0; i < fArrSize; i++)
    {
        rootA = insertElement(rootA, fArr[i]);
    }

    int sArr[13] = {12, 7, 14, 81, 42, 18, 61, 4, 64, 35, 13, 28, 65};
    int sArrSize = sizeof(sArr) / sizeof(int);

    node* rootB = NULL;

    for (int i = 0; i < sArrSize; i++)
    {
        rootB = insertElement(rootB, fArr[i]);
    }

    printf("\na: ");
    inorderedTraversal(rootA);

    printf("\nb: ");
    inorderedTraversal(rootB);

    return 0;
}