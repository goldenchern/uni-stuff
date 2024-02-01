#include <stdio.h>
#include <math.h>

int binaryToDec(int number);

int main() 
{        
    int number;
    
    printf("Enter a binary number:\n");
    scanf("%d", &number);
    
    printf("The equivalent decimal number: %d", binaryToDec(number));

    return 0;  
}

int binaryToDec(int number) {
    int result = 0, exponent = 0;
    
    while (number != 0) {
        result += (number % 10) * pow(2, exponent++);
        number /= 10;
    }
    
    return result;
}