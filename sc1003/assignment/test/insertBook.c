#include <stdio.h>

void shiftAndInsert(int newBook, int books[], int bookCount);


int main() {
    int i;
    int books[5] = {1, 3, 5}; // Initial values
    int bookCount = 3;
    int newBook;
    
    printf("Enter number:\n");
    scanf("%d", &newBook);
    
    shiftAndInsert(newBook, books, bookCount);
    
    for (i = 0; i < bookCount + 1; i++) {
        printf("%d ", books[i]);
    }
}


void shiftAndInsert(int newBook, int books[], int bookCount)
{
    int i;
    int insert = 0;
    
    if (bookCount == 0)
        books[0] = newBook;
    else {
        // find index to insert
        for (i = bookCount - 1; i >= 0; i--) {
            if (newBook > books[i]) { 
                insert = i + 1;
                // printf("%d\n", insert);
                break;
            }
        }
        
        // insert book into array at target index
        for (i = bookCount - 1; i >= insert; i--) {
            books[i + 1] = books[i];
        }
        books[insert] = newBook;
    }
}