#include <stdio.h>
#include <math.h>
#include <string.h>

int hexStrToDec(char *hex);

int main()
{
   int num;
   char hex[100];
   
   printf("Enter a hexadecimal number: \n"); 
   scanf("%s",&hex);
   num=hexStrToDec(hex);
   printf("hexStrToDec(): %d\n", num);
   return 0;
}

int hexStrToDec(char *hex)
{   
    int result = 0;
    char currentDigit;
    
    for (int i = strlen(hex) - 1, j = 0; i >= 0; i--, j++) {
        currentDigit = hex[i];
        
        if (currentDigit >= '0' && currentDigit <= '9')
            result += pow(16, j) * (currentDigit - '0');
        else if (currentDigit >= 'A' && currentDigit <= 'F')
            result += pow(16, j) * (currentDigit - 'A' + 10);
    }
    
    return result;
}