// 14. Като се използва рекурсивна функция, да се реши задачата за
// Ханойските кули.
// Дадени са n броя диска. Числото n се въвежда от клавиатурата.
// Задачата е да се преместят всички дискове от колче A на колче C, като
// колче B се използва за помощно

#include <stdio.h>

void hanoi(int n, char start, char end, char help);

int main()
{   
    int n;

    printf("Enter number: ");
    scanf("%d", &n);
    
    hanoi(3, 'A', 'C', 'B');
}

void hanoi(int n, char start, char end, char help){

    if (n == 1)
        printf("Move A --> C \n");
    if (n == 2)
    {
        printf("Move A --> B \n");
        printf("Move A --> C \n");
        printf("Move B --> C \n");
    }
    else
    {
        hanoi(n - 1, start, help, end);
        printf("Move A --> C \n");
        hanoi(n - 1, help, end, start);
    }
}