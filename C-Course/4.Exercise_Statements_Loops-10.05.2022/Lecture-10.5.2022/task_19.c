// 19. На един остров спрели N броя пирати. Там имало една маймуна. На острова
// имало кокосови орехи. Пиратите ги обрали и решили да си ги поделят на сутринта.
// През нощта един от тях се събудил и решил да даде един на маймуната и да вземе от
// останалите половината от орехите, като при нечетен брой, взема по-малката половина.
// После станал друг пират и той постъпил по същия начин. Така се изредили всички
// пирати. На сутринта си разделили по равно по m орехи и дали 1 на маймуната.
// Да се напише програма, която чете числата N и m и извежда по колко ореха е имало
// първоначално.

#include <stdio.h>

int main(){

    int m, n, allCoco = 0;

    printf("Enter pirates count: ");
    scanf("%d", &n);
    printf("Enter coconuts per pirate on the morning: ");
    scanf("%d", &m);

    allCoco = m * n + 1;

    for (int i = 1; i <= n; i++)
    {
        allCoco *= 2;
        allCoco += 1;
    }

    printf("There was %d coconuts in the beginning.", allCoco);
}