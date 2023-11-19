#include <stdio.h>
#include <stdlib.h>


int main() 
{
    const int MIN_HEIGHT = 1, MAX_HEIGHT = 10;

    int height, line, length;

    printf("Enter the height:\n");
    scanf("%d", &height);

    if (height < MIN_HEIGHT || height > MAX_HEIGHT)
        exit(1);
    
    printf("Pattern:\n");
    
    for (line = 0; line < height; line++) {

        for (length = 0; length <= line; length++)
            printf("%d", line % 3 + 1);
        
        printf("\n");
    }
}