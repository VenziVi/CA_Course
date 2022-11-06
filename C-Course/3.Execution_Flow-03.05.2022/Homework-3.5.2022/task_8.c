#include<stdio.h>
#include<math.h>

int main()
{
    long int n;
    double sum = 0., pi;
 
    printf("Enter number: ");
    scanf("%ld", &n);

    for(int i = 0; i < n; i++)
    {
        sum += pow(-1, i) / (2 * i + 1);
    }

    pi = 4 * sum;

    printf("PI = %.6lf", pi);
}
