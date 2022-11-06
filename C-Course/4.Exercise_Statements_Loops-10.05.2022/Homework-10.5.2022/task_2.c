// Да се състави програма на C, която при въвеждане на естествено число от интервала
// [10 - 30000] извежда цифрите му в морзовата азбука.
// Цифрите на числото се извеждат отдясно-наляво
// Входни данни: х - естествено число.
// Цифрите в морзовата абука се изписват както следва:
// 0: "----- ";
// 1: ".... "
// 2: "...- "
// 3: "..-- "
// 4: "..--- "
// 5: ".---- "
// 6: "-... "
// 7: "--.. "
// 8: "---.. "
// 9: "----. "
// За целта използвайте цикъл и оператор switch

#include <stdio.h>

int main(){

    int n, currNum;

    do
    {
        printf("Insert number: ");
        scanf("%d", &n);
    } while (n < 10 || n > 30000);

    while (n > 0)
    {
        currNum = n % 10;

        switch (currNum)
        {
        case 0: printf("----- "); break;
        case 1: printf(".... "); break;
        case 2: printf("...- "); break;
        case 3: printf("..-- "); break;
        case 4: printf("..--- "); break;
        case 5: printf(".---- "); break;
        case 6: printf("-... "); break;
        case 7: printf("--.. "); break;
        case 8: printf("---.. "); break;
        case 9: printf("----. "); break;
        }

        n /= 10;
    }
}