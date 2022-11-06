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

    fptr = fopen("program.bin", "rb");

    if (fptr == NULL)
    {
        printf("Cannot open file!");
        return 1;
    }

    for (n = 1; n < 5; n++)
    {
        fread(&num, sizeof(struct threeNum), 1, fptr);
        printf("%d %d %d \n", num.n1, num.n2, num.n3);
    }
    
    fclose(fptr);

    return 0;

}