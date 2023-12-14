#include <stdio.h>
#include <math.h>

int octToDec(int number);

int main()
{      
    int number;
    
    printf("Enter an octal number:\n");
    scanf("%d", &number);
    
    printf("The equivalent decimal number: %d", octToDec(number));

    return 0;  
}

int octToDec(int number) {
    int result = 0, exponent = 0;
    
    while (number != 0) {
        result += (number % 10) * pow(8, exponent++);
        number /= 10;
    }
    
    return result;
}