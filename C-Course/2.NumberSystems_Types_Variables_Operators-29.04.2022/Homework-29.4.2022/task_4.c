#include <stdio.h>
#include <string.h>

int main()
{
    float tomatoPrice = 4.50,
          flourPrice = 1.80,
          yogurtPrice = 0.50,
          icecreamPrice = 0.60,
          candyPrice = 1.50,
          lollipopPrice = 0.15;

    float totalPrice = 0.;
    char product[9];
    const char ADDPRODUCT[8] = "You buy";

    printf("Insert product name: ");
    scanf("%s", &product);

    while (strcmp(product, "end") != 0)
    {

        if (strcmp(product, "tomato") == 0)
        {
            printf("%s tomato.\n", ADDPRODUCT);
            totalPrice += tomatoPrice;
        }
        else if (strcmp(product, "flour") == 0)
        {
            printf("%s flour.\n", ADDPRODUCT);
            totalPrice += flourPrice;
        }
        else if (strcmp(product, "yogurt") == 0)
        {
            printf("%s yogurt.\n", ADDPRODUCT);
            totalPrice += yogurtPrice;
        }
        else if (strcmp(product, "icecream") == 0)
        {
            printf("%s icecream.\n", ADDPRODUCT);
            totalPrice += icecreamPrice;
        }
        else if (strcmp(product, "candy") == 0)
        {
            printf("%s candy.\n", ADDPRODUCT);
            totalPrice += candyPrice;
        }
        else if (strcmp(product, "lollipop") == 0)
        {
            printf("%s lollipop.\n", ADDPRODUCT);
            totalPrice += lollipopPrice;
        }
        else
        {
            printf("%s doesn't exist.\n", product);
        }

        printf("Insert product name: ");
        scanf("%s", &product);
    }

    printf("Total price: %.2f lv.", totalPrice);

    return 0;
}