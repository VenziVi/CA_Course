// Задача 10
// ● Да се напише програма, която проверява дали дадена кредитна карта от определен тип— VISA или
// MasterCard, има валиден номер. За валидиране на номера на кредитните карти, да се използва следното
// описание:
// ● Номерата на кредитните карти са 16-цифрени в групи по четири.
// ● Например, да проверим дали следната кредитна карта е валидна:
// ● 4 2 0 4 – 5 8 7 6 – 9 0 1 2 – 5 2 3 4
// ● 1) Обръщаме цифрите на номера и получаваме:
// ● 4 3 2 5 2 1 0 9 6 7 8 5 4 0 2 4
// ● 2) Удвояваме цифрите, стоящи на четна позиция, и получаваме:
// ● 4 6 2 10 2 2 0 18 6 14 8 10 4 0 2 8
// ● 3) Ако получим събираеми, по-големи от 9, ги разделяме на две отделни цифри. Събираме
// ● така получените цифри:
// ● 4 + 6 + 2 + 1 + 0 + 2 + 2 + 0 + 1 + 8 + 6 + 1 + 4 + 8 + 1 + 0 + 4 + 0 + 2 + 8 = 60
// ● 4) Ако сборът се дели на 10 без остатък, то кредитната карта е валидна. Ако номерът започва
// ● с 4, то типът ѝ е VISA, а ако има префикс 51–55, тя е MasterCard.

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

enum cardType {VISA, MasterCard, INVALID};

int *convertAndRevers(char cardNum[], int size);
int convertToInt(char num);
int creditCardNumberCalculation(int *number, int size);
enum cardType checkCardType(int number);

int main()
{
    const int cardNumberSize = 19;
    const int size = 16;
    int numCalculation = 0;
    enum cardType card;
    //char cardNumber[] = {"4204-5876-9012-5234"};
    char cardNumber[] = {"4111-1111-1111-1111"};

    int *intNumber = convertAndRevers(cardNumber, cardNumberSize);
    numCalculation = creditCardNumberCalculation(intNumber, size);
    card = checkCardType(numCalculation);
    
    printf("Card is: ");
    if (card == INVALID)
    {
        printf("INVALID");
    }
    else if(card == MasterCard)
    {
        printf("MasterCard");
    }
    else if (card == VISA)
    {
        printf("VISA");
    }
    
    free(intNumber);
    return 0;
}

enum cardType checkCardType(int number)
{
    if (number % 10 != 0)
    {
        return INVALID;
    }
    else if ((number / 10) <= 4)
    {
        return VISA;
    }
    else
    {
        return MasterCard;
    }
    
}

int creditCardNumberCalculation(int *number, int size)
{
    int sum = 0;
    int currNum = 0;

    for (int i = 1; i <= size; i+=2)
    {
        number[i] *= 2;
    }
    
    for (int i = 0; i < size; i++)
    {
        currNum = number[i];

        if (number[i] > 9)
        {
            sum += (currNum % 10);
            sum += (currNum / 10);
        }
        else
        {
            sum += currNum;
        }
    }
    
    return sum;
}

int *convertAndRevers(char cardNum[], int size)
{
    int *intNumber = malloc(sizeof(int) * 16);
    int convertedIndex = 0;
    char currentNum = 0;

    for (int i = size; i >= 0; i--)
    {
        currentNum = cardNum[i];

        if (isdigit(currentNum))
        {
            intNumber[convertedIndex] = convertToInt(currentNum);
            convertedIndex++;
        }
    }

    return intNumber;
}

int convertToInt(char num)
{
    char number[] = {num};
    int result = atoi(number);

    return result;
}