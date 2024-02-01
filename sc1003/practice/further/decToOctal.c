#include <stdio.h>
#include <math.h>

int decToOctal(int number);

int main()
{
    int number;
    
    printf("Enter a decimal number:\n");
    scanf("%d", &number);
    
    printf("The equivalent octal number: %d", decToOctal(number));

   return 0;  
}

int decToOctal(int number) {
    int result = 0, multiplier = 1;
    
    while (number != 0) {
         result += multiplier * (number % 8);
         multiplier *= 10;
         number /= 8;
    }
    
    return result;
}