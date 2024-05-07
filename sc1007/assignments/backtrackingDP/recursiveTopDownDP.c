#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Create table
int *table;


int top_down_dp(int n)
{
    // Sanity check
    if (n < 0) {
        return -1;
    }
    
    // Base cases
    if (n == 0) {
        table[0] = 0;
        return 0;
    } else if (n == 1) {
        table[1] = 1;
        return 1;
    } else if (n == 2) {
        table[2] = 2;
        return 2;
    }

    // Check if values have been calculated before
    if (table[n-1] == -1) {
        table[n-1] = top_down_dp(n-1);
    } 
    if (table[n-2] == -1) {
        table[n-2] = top_down_dp(n-2);
    }
    if (table[n-3] == -1) {
        table[n-3] = top_down_dp(n-3);
    }

    // Calculate and store result
    table[n] = table[n-1] + 2 * table[n-2] - 3 * table[n-3];
    return table[n];
}


 
int main ()
{
    int n;
    int function;
    int i;
    printf("Enter the value of n:\n");
    scanf("%d",&n);

    // Allocate memory dynamically
    table = (int *) malloc(sizeof(int) * n);

    // Initialise table elements
    for (i = 0; i < n; i++) {
        table[i] = -1;
    }
    
    printf("The value of F(%d) is: %d \n", n, top_down_dp(n));

    // Free allocated memory
    free(table); 
}