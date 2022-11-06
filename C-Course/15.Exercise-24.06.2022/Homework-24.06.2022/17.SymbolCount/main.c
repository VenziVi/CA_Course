// 17. Реализирайте стек, поддържащ операцията намиране на
// максимална сума сред елементите на стека.
// Напишете програма, четяща имена в стек и отпечатайте
// името при което се достигат 200 символа на имената, които
// са в стека. Тук на всяко име ще се съпоставя дължината му,
// т.е. брой символи в него. Понеже при долавяне на имена
// броят на символите ще се увеличава, то операцията max за
// такъв стек ще върне броят на символите в стека.

#include "stack.h"

int main()
{
    stack wordStack = NULL;
    int symbolsCount = 0;
    int command = 0;

    const int testSize = 6;
    char testWords[][10] = {"Ivan", "Georgi", "Stoqn", "Gotiniq", "random", "duma"};

    for (int i = 0; i < testSize; i++)
    {
        push(&wordStack, testWords[i]);
    }

    command = menu();
    
    if (command == -1)
    {
        symbolsCount = allSymbolsCount(&wordStack);
        printf("\nSymbol count: %d \n", symbolsCount);
    }
    else if (command > 0)
    {
        printCurrenrSymbolWord(&wordStack, command);
    }
    
    deinitStack(&wordStack);

    return 0;
}
