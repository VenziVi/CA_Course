#include <stdio.h>
#include <stdlib.h>

typedef struct dLNode{
    size_t value;
    struct dLNode *next;
    struct dLNode *prev;
} dLNode;

typedef struct node
{
    size_t value;
    struct node *next;
} node;

dLNode *createDoubleLinkedList(size_t size);
void printDoubleList(dLNode *start);
void deinitDoubleList(dLNode *startNode);
node *createList(size_t size);
size_t setInteger(char msg[]);
void printList(node *startNode);
void deinitList(node *startNode);