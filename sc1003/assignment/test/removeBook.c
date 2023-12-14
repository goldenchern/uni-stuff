#include <stdio.h>

void shiftAndReplace(int books[], int bookCount, int targetIndex);


int main() {
    int i;
    int books[5] = {1, 2, 3}; // Initial values
    int bookCount = 3;
    int targetIndex;
    
    printf("Remove index:\n");
    scanf("%d", &targetIndex);
    
    shiftAndReplace(books, bookCount, targetIndex);
    
    for (i = 0; i < bookCount - 1; i++)
        printf("%d ", books[i]);
}


void shiftAndReplace(int books[], int bookCount, int targetIndex)
{
    int i;

    if (targetIndex != bookCount - 1) {
        for (i = targetIndex + 1; i < bookCount; i++)
            books[i - 1] = books[i];
    }
}