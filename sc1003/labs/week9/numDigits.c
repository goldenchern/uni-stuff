#include <stdio.h>

int numDigits1(long num);
void numDigits2(long num, int *result);


int main()
{
    long number;
    int result = 0;
        
    printf("Enter the number: \n");
    scanf("%ld", &number);
    
    printf("numDigits1(): %d\n", numDigits1(number));    
    numDigits2(number, &result);
    printf("numDigits2(): %d\n", result);  
    
    return 0;
}


int numDigits1(long num)
{
    int count = 0;
    
    do {
        num /= 10;
        count++;
    } while (num != 0);
    
    return count;
}


void numDigits2(long num, int *result)
{
    do {
        num /= 10;
        *result += 1;
    } while (num != 0);
}