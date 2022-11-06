// Задача 14. Да се напише програма, която по дадено цяло положително число
// n, отпечатва първите n реда от триъгълника на Паскал.

#include <stdio.h>

int main() {

   int r, n = 1, i, j;

   printf("Enter rows: ");
   scanf("%d", &r);

   for (i = 0; i < r; i++) 
   {     
      for (j = 0; j <= i; j++) 
      {
         if (j == 0 || i == 0)
            n = 1;
         else
            n = n * (i - j + 1) / j;
         printf("%d", n);
      }
      printf("\n");
   }
}