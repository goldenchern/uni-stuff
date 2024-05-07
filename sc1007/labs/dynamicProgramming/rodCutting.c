#include <stdio.h>
#include <stdlib.h>

//memory
int *r;

int cr_recursive(int *p, int n)
{
    int max_value = -1, div_value;

    // Base case
    if (n == 0) {
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        div_value = cr_recursive(p, n-i) + p[i];
        if (div_value > max_value) {
            max_value = div_value;
        }
    }

    return max_value;
}

int cr_top_down_dp(int *p, int n)
{
    int max_value = -1, div_value;

    // Base case
    if (n == 0) {
        return 0;
    }
    
    // Retrieve the max value
    if (r[n] != -1) {
        return r[n];
    }

    // Memoization
    for (int i = 1; i <= n; i++) {
        div_value = cr_top_down_dp(p, n-i) + p[i];
        if (div_value > max_value) {
            max_value = div_value;
        }
    }
    r[n] = max_value;

    return max_value;
}

int cr_bottom_up_dp(int *p, int n)
{
    int div_value;
    
    // Base case
    r[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            div_value = r[i-j] + p[j];
            if (div_value > r[i]) {
                r[i] = div_value;
            }
        }
    }

    return r[n];
}
 
void main ()
{
    int n;      //length of rod
    int function;
    int i;
    int *p;     //price list
    
    int price_list[10] = {0,1,5,8,9,10,17,17,20,24}; //declare one more value to cover the index 0;
    
    n = sizeof(price_list) / sizeof(int) - 1;
    p = price_list;
    
    
    //allocate the memory array
    r = malloc(sizeof(int) * (n+1));
    
    printf("Choose a function (1 for recursive, 2 for top-down DP, 3 for bottom-up DP, 0 to stop): \n");
    scanf("%d",&function);
    while (function != 0)
    {
        if (function == 1)
        {
            printf("The maximum value is: %d \n", cr_recursive(p,n));
        }
        else if (function == 2)
        {
            //set all memory elements to -1
            for (i=0; i<=n; i++)
                r[i] = -1;
                
            printf("The maximum value is: %d \n", cr_top_down_dp(p,n));
        }
        else if (function == 3)
        {
            //set all memory elements to -1
            for (i=0; i<=n; i++)
                r[i] = -1;
                
            printf("The maximum value is: %d \n", cr_bottom_up_dp(p,n));
        }
        printf("Choose a function (1 for recursive, 2 for top-down DP, 3 for bottom-up DP, 0 to stop): \n");
        scanf("%d",&function);
    }
}