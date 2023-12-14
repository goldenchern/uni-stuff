#include <stdio.h>

int digitPos1(int num, int digit);
void digitPos2(int num, int digit, int *result);


int main()
{
    int number, digit, result = 0;

    printf("Enter the number: \n");
    scanf("%d", &number);
    printf("Enter the digit: \n");
    scanf("%d", &digit);  

    printf("digitPos1(): %d\n", digitPos1(number, digit));            
    digitPos2(number, digit, &result);           
    printf("digitPos2(): %d\n", result);    

    return 0;
}


int digitPos1(int num, int digit)  
{
    int ones, position = 0;
    
    do {
        ones = num % 10;
        num /= 10;
        position++;
        
        if (digit == ones) {
            return position;
        }
    } while (num != 0);
    
    return 0;
}


void digitPos2(int num, int digit, int *result)  
{
    int ones, position = 0;
    
    do {
        ones = num % 10;
        num /= 10;
        position++;

        if (digit == ones) {
            *result = position;
            return;
        }
    } while (num != 0);
    
    *result = 0;
}
