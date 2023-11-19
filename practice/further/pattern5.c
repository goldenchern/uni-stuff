#include <stdio.h>

void printPattern(int height);

int main() 
{        
    int height;
    
    printf("Enter the height:\n");
    scanf("%d", &height);
    
    printPattern(height);

   return 0;  
}

void printPattern(int height) {
    
    printf("The pattern is:\n");
    
    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < height - i; j++) 
            printf(" ");
        
        for (int j = 0; j < 2 * i - 1; j++) {
            printf("%c", (i + j) % 2 ? '+' : '=');
        }
        
        printf("\n");
    }
}