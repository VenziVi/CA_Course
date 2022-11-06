// 1) Напишете C програма за намиране на дължината на низ с помощта на цикъл, без да
// използвате вградена библиотечна функция strlen() .

#include <stdio.h>
#include <stdlib.h>

char * getString(void);
int findLen(char str[]);

int main()
{
    char *myStr = getString();
    int strLength = findLen(myStr);
    printf("String: %s \nlength = %d \n", myStr, strLength);

    free(myStr);

    return 0;
}

//Counting the length of the string
int findLen(char str[])
{
    int result = 0;

    for (int i = 0; (str[i] != '\0'); i++)
    {  
        result++;
    }
    
    return result;
}

//Read and set the string dynamically
char * getString(void)
{
    size_t size = 20;
    char *inputStr = malloc(size);
    size_t length = 0;
    char ch;

    printf("Enter string: ");

    while ((ch = getchar()) != '\n')
    {   
        if (length >= size - 1)
        {
            inputStr = realloc(inputStr, size * 2);
            size *= 2;
        }
        
        inputStr[length++] = ch;
    }

    inputStr[length] = '\0';
    return inputStr;
}