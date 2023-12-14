#include <stdio.h>
#include <ctype.h>

int main() 
{
    char c;

    printf("Enter a character:\n");
    scanf("%c", &c);
    
    if (isupper(c))
        printf("Upper case letter\n");
    else if (islower(c))
        printf("Lower case letter\n");
    else if (isdigit(c))
        printf("Digit\n");
    else
        printf("Other character\n");

   return 0;  
}