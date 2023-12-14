#include <stdio.h>

#define BASIC_PAY_RATE 6
#define BASE_TAX_RATE 0.1

int main() 
{        
    int hours;
    float grossPay, tax;
    
    printf("Enter hours of work:\n");
    scanf("%d", &hours);
    
    if (hours <= 40)
        grossPay = BASIC_PAY_RATE * hours;
    else {
        grossPay = BASIC_PAY_RATE * 40 + BASIC_PAY_RATE * 1.5 * (hours - 40);
    }
    
    printf("Gross pay=%.2f\n", grossPay);
    printf("Tax=%.2f\n", tax);
    printf("Net pay=%.2f\n", grossPay - tax);

   return 0;  
}