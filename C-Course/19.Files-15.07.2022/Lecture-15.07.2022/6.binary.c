#include <stdio.h>
#include <stdlib.h>

struct threeNum
{
    int n1, n2, n3;
};

int main()
{

    int n;
    struct threeNum num;
    FILE *fptr;

    fptr = fopen("program.bin", "wb");

    if (fptr == NULL)
    {
        printf("Cannot open file!");
        return 1;
    }

    for (n = 1; n < 5; n++)
    {
        num.n1 = n;
        num.n2 = 5 * n;
        num.n3 = 5 * n + 1;

        fwrite(&num, sizeof(struct threeNum), 1, fptr);
    }
    
    fclose(fptr);

    return 0;

}