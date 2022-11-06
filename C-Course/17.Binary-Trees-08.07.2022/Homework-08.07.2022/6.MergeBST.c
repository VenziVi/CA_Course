//Задача 6. Напишете функция за merge на две бинарни дървета - BST.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} node;

node *createNode(int value);
void inorder(node *root);
node *insert(node *node, int value);
int *setElementsInArray(node *root, int *size);
void setInorde(node *root, int *resultArr, int *capacity, int *size);
int *mergeArrays(int *firstArr, int firstArrSize, int *secondArr, int secondArrSize);
node *mergedTree(int *mergedArr, int mergedArrSize);
node *createTree(int *arr, int size);

int main()
{
    int fArr[] = {31, 35, 13, 28, 65};
    int fArrSize = sizeof(fArr) / sizeof(int);

    node* firstRoot = createTree(fArr, fArrSize);

    int sArr[] = {32, 12, 7, 48, 55, 82};
    int sArrSize = sizeof(sArr) / sizeof(int);

    node* secondRoot = createTree(sArr, sArrSize);

    printf("\nFirst tree: ");
    inorder(firstRoot);

    printf("\nSecond tree: ");
    inorder(secondRoot);

    int firstArrSize = 0;
    int* firstArr = setElementsInArray(firstRoot, &firstArrSize);
    
    int secondArrSize = 0;
    int* secondArr = setElementsInArray(secondRoot, &secondArrSize);

    int mergedArrSize = firstArrSize + secondArrSize;
    int* mergedArr = mergeArrays(firstArr, firstArrSize, secondArr, secondArrSize);

    node *mergeRoot = mergedTree(mergedArr, mergedArrSize);

    printf("\nMerged tree: ");
    inorder(mergeRoot);

    free(firstArr);
    free(secondArr);
    free(mergedArr);

    return 0;
}

node *mergedTree(int *mergedArr, int mergedArrSize)
{
    int middle = mergedArrSize / 2;
    node *mergeRoot = NULL;

    for (int i = middle; i >= 0; i--)
    {
        mergeRoot = insert(mergeRoot, mergedArr[i]);
    }

    for (int i = middle + 1; i < mergedArrSize; i++)
    {
        mergeRoot = insert(mergeRoot, mergedArr[i]);
    }
    
    return mergeRoot;
}

int *mergeArrays(int *firstArr, int firstArrSize, int *secondArr, int secondArrSize)
{
    int resultSize = firstArrSize + secondArrSize;
    int* resultArr = malloc(sizeof(int) * resultSize); 

    int firstIndex = 0;
    int secIndex = 0;
    int resultIndex = 0;

    while (firstIndex < firstArrSize && secIndex < secondArrSize)
    {
        if (firstArr[firstIndex] > secondArr[secIndex])
        {
            resultArr[resultIndex++] = secondArr[secIndex++];
        }
        else
        {
            resultArr[resultIndex++] = firstArr[firstIndex++];
        }
    }
    
    while (firstIndex < firstArrSize)
    {
        resultArr[resultIndex++] = firstArr[firstIndex++];
    }
    
    while (secIndex < secondArrSize)
    {
        resultArr[resultIndex++] = secondArr[secIndex++];
    }
    
    return resultArr;
}

int *setElementsInArray(node *root, int *size)
{
    int capacity = 3;
    int* resultArr = malloc(sizeof(int) * capacity);

    setInorde(root, resultArr, &capacity, size);

    return resultArr;
}

void setInorde(node *root, int *resultArr, int *capacity, int *size)
{
    if (root == NULL)
    {
        return;
    }

    if ((*size) == (*capacity))
    {
        (*capacity) *= 2;
        resultArr = realloc(resultArr, sizeof(int) * (*capacity));
    }
    
    setInorde(root->left, resultArr, capacity, size);

    resultArr[(*size)++] = root->data;

    setInorde(root->right, resultArr, capacity, size);
    
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

node *createTree(int *arr, int size)
{
    node* root = NULL;

    for (int i = 0; i < size; i++)
    {
        root = insert(root, arr[i]);
    }

    return root;
}