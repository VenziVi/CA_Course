//  Напишете макрос с един параметър, който печата
// съобщение, само при дефиниран макрос DEBUG. Ако DEBUG
// не е дефиниран, не печата нищо.

#include <stdio.h>

#define DEBUG 1
#if DEBUG 
#define PRINTMSG(msg) (printf(msg))
#else
#define PRINTMSG(msg)
#endif

int main()
{
    char str[] = "Stupid message.";

    PRINTMSG(str);

    return 0;
}