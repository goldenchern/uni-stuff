#include <stdio.h>

void printPattern(int height);

int main() 
{        
    int height;
    
    printf("Enter the height:\n");
    scanf("%d", &height);
    
    printf("The pattern is:\n");
    printPattern(height);
    
   return 0;  
}

void printPattern(int height) {
    
    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }
        
        for (int j = 0; j < i; j++) {
            printf("%d", (i + j) % 10);
        }
        
        if (i == 1) {
            printf("\n");
            continue;
        }
        
        for (int j = 0; j < i - 1; j++) {
            printf("%d", (2 * (i - 1) - j) % 10);
        }
        
        printf("\n");
    }
}