#include <stdio.h>


int main() 
{
    float average, sum = 0;
    int current_num;
    int lines, line_count, num_count = 0;
    
    printf("Enter number of lines:\n");
    scanf("%d", &lines);
    
    for (line_count = 1; line_count <= lines; line_count++) {
        printf("Enter line %d (end with -1):\n", line_count);
        
        scanf("%d", &current_num);
        while (current_num != -1) {
            num_count++;
            sum += current_num;
            scanf("%d", &current_num);
        }

        average = sum / num_count;
        printf("Average = %.2f\n", average);
        num_count = sum = 0;
    }
   
   return 0;
}