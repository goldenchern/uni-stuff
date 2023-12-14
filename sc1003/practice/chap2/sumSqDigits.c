#include <stdio.h>

int sumSqDigits1(int num);   
void sumSqDigits2(int num, int *result);   

int main()
{
   int num, result;

   printf("Enter a number: \n");
   scanf("%d", &num);
   printf("sumSqDigits1(): %d\n", sumSqDigits1(num));
   sumSqDigits2(num, &result);
   printf("sumSqDigits2(): %d\n", result);
   return 0;
}

int sumSqDigits1(int num) 
{
    int sum = 0, currentDigit;
    
    while (num != 0) {
        currentDigit = num % 10;
        sum += currentDigit * currentDigit;
        num /= 10;
    }
    
    return sum;
}

void sumSqDigits2(int num, int *result) 
{
    int sum = 0, currentDigit;
    
    while (num != 0) {
        currentDigit = num % 10;
        sum += currentDigit * currentDigit;
        num /= 10;
    }
    
    *result = sum;
}