#include <stdio.h>
#include <math.h>

int fact(int n);


int main() 
{
    const int SERIES_LENGTH = 11;

    int term;
    float exponent, sum = 0;

    printf("Enter x:\n");
    scanf("%f", &exponent);

    for (term = 0; term < SERIES_LENGTH; term++) {
        sum += (pow(exponent, term) / fact(term));
    }

    printf("Result = %.2f\n", sum);

    return 0;
}


int fact(int n) 
{
    int i, result = 1;

    for (i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}