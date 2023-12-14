#include <stdio.h>
#include <math.h>

int reverseDigits(int num);

int main()
{
    int num, result=999;
    printf("Enter a number: \n");
    scanf("%d", &num);
    printf("reverseDigits(): %d\n", reverseDigits(num));
    return 0;
}

int reverseDigits(int num)
{
    int result = 0, power = 10, digit;

    do {
        digit = num % 10;
        result = result * power + digit;
        num /= 10;
    } while (num > 0);
    
    return result;
    
    // int numCopy = num, digits = 0;
    
    // while (numCopy != 0) {
    //     digits++;
    //     numCopy /= 10;
    // }
    
    // int result = 0, multiplier = pow(10, digits - 1);
    
    // while (num != 0) {
    //     result += (num % 10) * multiplier;
    //     multiplier /= 10;
    //     num /= 10;
    // }
    
    // return result;
}