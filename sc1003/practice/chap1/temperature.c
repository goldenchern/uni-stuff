#include <stdio.h>

/*custom header*/
float farenheitToCelsius(int temp);

/*end_edit*/

int main() {
    /*edit*/
    int temperature;

    do {
        printf("Enter the temperature in degree F:\n");
        scanf("%d", &temperature);

        if (temperature != -1) {
            printf("Converted degree in C: %.2f\n", farenheitToCelsius(temperature));
        }
    } while (temperature != -1);

    /*end_edit*/

    return 0;
}

float farenheitToCelsius(int temp) {
    return (5.0 / 9 * (temp - 32));  // Use 5.0 to force floating-point division
}
