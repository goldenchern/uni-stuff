#include <stdio.h>

int main() 
{
    int num, i, j;
    
    printf("Enter a number (between 1 and 9):\n");
    scanf("%d", &num);
    
    printf("Multiplication Table:\n   ");
    
    for (i = 1; i <= num; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (i = 1; i <= num; i++) {
        printf("%d ", i);
        
        for (j = 1; j <= i; j++) {
            printf("%d ", i * j);
        }
        
        printf("\n");
    }

   return 0;  
}
