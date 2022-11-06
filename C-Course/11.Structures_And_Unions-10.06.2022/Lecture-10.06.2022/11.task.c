#include <stdio.h>

typedef long long int ll_int;

int main()
{
    ll_int val = 33435354543543636;

    printf("%lld \n", val);
    printf("%d \n", sizeof(val));
    printf("%d \n", sizeof(ll_int));
}