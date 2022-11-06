#include "func.h"

int main()
{
    const size_t listSize = 7;
    dLNode *list = createDoubleLinkedList(listSize);

    printDoubleList(list);

    deinitDoubleList(list);
    return 0;
}