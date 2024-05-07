#include <stdio.h>
#include <stdlib.h>

int waysToScore(int n, int* score)
{
    int *table = malloc(sizeof(int) * (n+1));
    for (int i = 0; i <= n; i++) {
        table[i] = 0;
    }

    table[0] = 1;

    for (int i = 1; i <= n; i++) {
        if (i-score[0] >= 0) table[i] += table[i-score[0]];
        if (i-score[1] >= 0) table[i] += table[i-score[1]];
        if (i-score[2] >= 0) table[i] += table[i-score[2]];
    }

    table[0] = 0; // Is this correct?
    return table[n];
}

 
void main ()
{
    int n;

    int score[3] = {3,5,10}; 

    printf("Enter the value of N: ");
    scanf("%d",&n);


    printf("The number of ways to reach to a score of %d is: %d \n",n, waysToScore(n,score));
}
