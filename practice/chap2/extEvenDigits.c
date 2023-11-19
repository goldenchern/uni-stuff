	/*edit*/
#include <stdio.h>

#define INIT_VALUE 999

int extEvenDigits1(int num);
void extEvenDigits2(int num, int *result);

int main()
{
   int number, result = INIT_VALUE;
   
   printf("Enter a number: \n");
   scanf("%d", &number);
   printf("extEvenDigits1(): %d\n", extEvenDigits1(number));        
   extEvenDigits2(number, &result);
   printf("extEvenDigits2(): %d\n", result);
   return 0;
}

int extEvenDigits1(int num) 
{  
    int newNumber = 0, currentDigit, multiplier = 1;
    
    while (num != 0) {
        currentDigit = num % 10;
        if (currentDigit % 2 == 0) {
            newNumber += currentDigit * multiplier;
            multiplier *= 10;
        }
        num /= 10;
    }
    
    return (newNumber == 0) ? -1 : newNumber;
}

void extEvenDigits2(int num, int *result) 
{  
    int currentDigit, multiplier = 1;
    *result = 0;
    
    while (num != 0) {
        currentDigit = num % 10;
        if (currentDigit % 2 == 0) {
            *result += currentDigit * multiplier;
            multiplier *= 10;
        }
        num /= 10;
    }
    
    *result = (*result == 0) ? -1 : *result;
}