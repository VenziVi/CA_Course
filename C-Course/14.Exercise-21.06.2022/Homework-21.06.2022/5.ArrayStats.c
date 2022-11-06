// ● 5. Напишете функция, която по даден е масив от цели числа изчислява
// процента на неговите елементи, които са положителни, които са отрицателни и
// които са нула. Резултатът, който връща функцията да бъде масив от числа между 0
// и 1, даващи пропорцията на всеки вид числа.
// ● Програмата чете масива от числа, извиква горната функция и отпечатва като резултат
// процентите всеки на нов ред с 6 цифри след десетичната запетая.
// Example :
// 4. arr = [1,1,0, -1,-1]
// 5.
// There are n =5 elements, two positive, two negative and one zero. Their ratios are 2/5=0.400000 ,
// 2/5=0.400000 and 1/5 = 0.200000 . Results are printed as:
// 6. 0.400000
// 7. 0.400000
// 8. 0.200000

#include<stdio.h>
 
void positiveNegativeZero(int arr[], int len)
{
	float positiveCount = 0;
	float negativeCount = 0;
	float zeroCount = 0;
 
	for (int i = 0; i < len; i++) {
		if (arr[i] > 0) {
			positiveCount++;
		}
		else if (arr[i] < 0) {
			negativeCount++;
		}
		else if (arr[i] == 0) {
			zeroCount++;
		}
	}
 
	printf(" positive count: %.2f, negative count: %.2f, zero count: %.2f\n", positiveCount, negativeCount, zeroCount);
    printf(" positive vatio %.2f, negative vatio %.2f, zero vatio %.2f\n", positiveCount/len, negativeCount/len, zeroCount/len);
 
}
 
int main()
{
	// Test Case 1:
	int a1[] = { 2, -1, 5, 6, 0, -3 };
	int len=sizeof(a1)/sizeof(a1[0]);
	positiveNegativeZero(a1,len);
 
    printf("-----------------------------------------\n");
	// Test Case 2:
	int a2[] = { 4, 0, -2, -9, -7, 1 };
	len=sizeof(a2)/sizeof(a2[0]);
	positiveNegativeZero(a2,len);
}
 