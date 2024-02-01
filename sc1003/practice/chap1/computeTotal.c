#include <stdio.h>

int main() 
{     
    int lines, elements, i, j;
    int temp, total;
    
    printf("Enter number of lines:\n");
    scanf("%d", &lines);
    
    for (i = 1; i <= lines; i++) {
        printf("Enter line %d:\n", i);
        total = 0;
        
        scanf("%d", &elements);
        
        for (j = 0; j < elements; j++) {
            scanf("%d", &temp);
            total += temp;
        }
        
        printf("Total: %d\n", total);
    }

   return 0;
}