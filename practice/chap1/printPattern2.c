#include <stdio.h>
int main() 
{
    int height;
    
    printf("Enter the height:\n");
    scanf("%d", &height);
    
    printf("The pattern is:\n");
    
    int isA;
    
    for (int i = 0; i < height; i++) {
        
        if (i % 2 == 0) 
            isA = 1;
        else 
            isA = 0;
            
        for (int j = 0; j < i + 1; j++) {
            if (isA) {
                printf("A");
                isA = 0;
            } else {
                printf("B");
                isA = 1;
            }
        }
            
        printf("\n");
    }

   return 0;
}