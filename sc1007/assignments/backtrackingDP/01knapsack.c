#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Create table
int **table;


int bottom_up_dp(int n, int *s, int *v, int C)
{
    // Value and capacity if ith item is included/excluded
    int v_include, v_exclude, c_include;

    // Populate table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= C; j++) {
            // Only first item is considered
            if (i == 1) {
                // Include if allowed
                if (s[i] <= j) {
                    table[i-1][j-1] = v[i];
                }
                continue;
            }

            // The first i items are considered
            // If capacity is 1, v_include = v_ith if allowed
            // Else v_include = max value without ith item + v_ith if fllowed
            v_exclude = table[i-2][j-1];
            if (j == 1) {
                v_include = (s[i] <= j) ? v[i] : 0;
            } else {
                c_include = j-s[i];
                v_include = (c_include-1 >= 0) ? table[i-2][c_include-1] + v[i] : 0;
            }

            // Record the greater value
            table[i-1][j-1] = (v_include > v_exclude) ? v_include : v_exclude;
        }   
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= C; j++) {
    //         printf("%d ", table[i-1][j-1]);
    //     }   
    //     printf("\n");
    // }

    return table[n-1][C-1];
}

 
int main ()
{
    int n,C;
    int function;
    int *s;
    int *v;
    int i,j;
    printf("Enter the number of items n:\n");
    scanf("%d",&n);
    printf("Enter the capacity C:\n");
    scanf("%d",&C);
    s = (int *) malloc(sizeof(int) * (n+1));
    v = (int *) malloc(sizeof(int) * (n+1));
    
    printf("Enter the sizes of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&s[i]);
        
    printf("Enter the values of items (as a list, separate by spacing:\n");
    for (i=1;i<=n;i++)
        scanf("%d",&v[i]);

    // Allocate memory for 2D array
    table = (int **) malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++) {
        table[i] = (int *) malloc(sizeof(int) * C);
    }

    // Initialise table elements
    for (i = 0; i < n; i++) {
        for (j = 0; j < C; j++) {
            table[i][j] = 0;
        }
    }
    
    printf("The maximum value is: %d \n", bottom_up_dp(n,s,v,C));
        
}