#include <stdio.h>

int main()
{
    int listPrice, category;

    printf("Please enter the list price:\n");
    scanf("%d", &listPrice);

    printf("Please enter the category:\n");
    scanf("%d", &category);

    float discountedPrice = listPrice * 0.9;
    float over100k = discountedPrice - 100000;
    float luxuryTax = 0;

    if (over100k > 0) {
        luxuryTax = over100k * 0.1;
    }

    float gst = discountedPrice * 0.03;
    int coe;

    switch (category) {
        case 1:
            coe = 70000;
            break;
        case 2:
            coe = 80000;
            break;
        case 3:
            coe = 23000;
            break;
        case 4:
            coe = 600;
    }

    printf("Total price is $%.2f\n", discountedPrice + luxuryTax + gst + coe);

    return 0;  
}