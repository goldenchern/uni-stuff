#include <stdio.h>
#include <math.h>

int decToBinary(int number);

int main()
{
    int number;
    
    printf("Enter a decimal number:\n");
    scanf("%d", &number);
    
    printf("The equivalent binary number: %d", decToBinary(number));

   return 0;  
}

int decToBinary(int number) {
    int result = 0, multiplier = 1;
    
    while (number != 0) {
        result += multiplier * (number % 2);
        multiplier *= 10;
        number /= 2;
    }
    
    return result;
}