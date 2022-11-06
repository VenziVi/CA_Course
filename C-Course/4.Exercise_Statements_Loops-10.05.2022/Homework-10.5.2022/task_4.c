// а се състави програма на C, чрез която се въвеждат естествени числа от интервала
// [1..50].
// Програмата да преустановява работата си при въвеждане на 2 последователни числа,
// които са равни.
// Програмата да извежда
// броя на въведените числа и тяхната средна стойност.
// Пример:
// 1,2,3,4,5,5
// Изход:
// брой 6, средна стойност 3.33333.

#include <stdio.h>

int main(){

    int n, count = 0, lastNum;
    float sum = 0.0;

    printf("Enter number between 1 and 50: ");
    scanf("%d", &n);

    while (n >= 1 && n <= 50)
    {
        count++;
        sum += n;

        if (n == lastNum)
            break;
        
        lastNum = n;
        printf("Enter number between 1 and 50: ");
        scanf("%d", &n);
    }
    
    printf("Count = %d, average = %f", count, sum / count);
}