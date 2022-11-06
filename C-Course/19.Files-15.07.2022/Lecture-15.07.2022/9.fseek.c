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

    fseek(fptr, -sizeof(struct threeNum), SEEK_END);

    printf("%ld\n", ftell(fptr));
    
    for (n = 1; n < 5; n++)
    {
        fread(&num, sizeof(struct threeNum), 1, fptr);
        printf("n1: %d  n2: %d  n3: %d \n", num.n1, num.n2, num.n3);
        fseek(fptr, -2*sizeof(struct threeNum), SEEK_CUR);
    }
    
    fclose(fptr);

    return 0;

}