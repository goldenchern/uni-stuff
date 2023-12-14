#include <stdio.h>

void reverseAr1D(int ar[], int size);


int main()
{
    int ar[10];
    int size, i;
    
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    for (i = 0; i <= size-1; i++)
        scanf("%d", &ar[i]);
        
    reverseAr1D(ar, size);
    printf("reverseAr1D(): ");
    if (size > 0) {
        for (i = 0; i < size; i++)
            printf("%d ", ar[i]);
    }
    
    return 0;
}


void reverseAr1D(int ar[], int size)
{
    int index, temp;
    
    for (index = 0; index < size/2; index++) {
        temp = ar[index];
        ar[index] = ar[size-index-1];
        ar[size-index-1] = temp;
    }
} 