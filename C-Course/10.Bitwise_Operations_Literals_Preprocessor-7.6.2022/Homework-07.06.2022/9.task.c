// Напишете макрос с променлив брой параметри,
// който
// извиква printf със префикс “TRACE: ”

#include <stdio.h>

#define PRINTARGS(format, args...) fprintf(stderr,"TRACE: " format , ## args)

 int main()
 {
     PRINTARGS("%d, %.2f, %s", 5, 7.21, "Ivan");
 }