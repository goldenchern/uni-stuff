#include <stdio.h>
int main()
{
    int height;
    
    printf("Enter the height:\n");
    scanf("%d", &height);
    
    int k;
    
    printf("The pattern is:\n");
    
    for (int i = 1; i <= height; i++) {
        k = i;
        for (int j = 0; j < i; j++, k++) {
            printf("%d", k % 10);
        }
        printf("\n");
    }
    
   return 0;
}