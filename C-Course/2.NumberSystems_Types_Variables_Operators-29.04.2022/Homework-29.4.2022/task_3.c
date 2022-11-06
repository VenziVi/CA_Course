#include <stdio.h>
#include <string.h>

int main()
{
    char caravanCount = 3;
    char camperCount = 3;
    double caravanPrice = 90.;
    double camperPrice = 100.;
    char vehicle[4];

    const char CARAVANA[4] = "car";
    const char CEMPER[4] = "cem";

    char quantity = 0;
    double totalPrice = 0.0;

    do
    {
        printf("If you want caravan enter %s, for camper enter %s: ", CARAVANA, CEMPER);
        scanf(" %s", &vehicle);

    } while (strcmp(vehicle, CARAVANA) != 0 && strcmp(vehicle, CEMPER) != 0);

    do
    {
        printf("Enter quantity between 1 and 3: ");
        scanf("%d", &quantity);
    } while (quantity < 1 || quantity > 3);

    totalPrice = (strcmp(vehicle, CARAVANA) == 0) ? quantity * caravanPrice : quantity * camperPrice;

    printf("Total price: %.2lf", totalPrice);

    return 0;
}