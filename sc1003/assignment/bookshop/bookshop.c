#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 5

typedef struct 
{
    int bookID;
    char title[40];
    char author[40];
    double price;
    int quantity; 
} Book;


// Main functions
void listBooks(Book books[], int bookCount);
void addBook(Book books[], int *ptBookCount); // Call by reference as count is updated
void removeBook(Book books[], int *ptBookCount);
void findBook(Book books[], int bookCount);
void updateBook(Book books[], int bookCount);


// Helper functions for interface
void printMenu();
void getChoice(int *choice);

// Helper function for addBook()
Book getNewBook();
void shiftAndInsert(Book newBook, Book books[], int bookCount);

 // Helper functions for removeBook()
void shiftAndReplace(Book books[], int bookCount, int targetIndex);

// Other helper functions
void getTargetDetails(char title[], char author[]);
void printBook(Book book);
int findMatch(Book books[], int bookCount, char title[], char author[]);
int matchString(char s1[], char s2[]);



int main() 
{
    Book books[MAX];
    int bookCount = 0;
    int choice;
    
    printMenu();
    
    while (1) 
    {
        getChoice(&choice);
        
        if (choice == 6)
            break;
        
        switch (choice) {
            case 1:
                listBooks(books, bookCount);
                break;
            case 2:
                addBook(books, &bookCount);
                break;
            case 3:
                removeBook(books, &bookCount);
                break;
            case 4:
                findBook(books, bookCount);
                break;
            case 5:
                updateBook(books, bookCount);
                break;
            default:
                printf("Invalid choice.\n");
        }
            
    }
}


// Main functions
void listBooks(Book books[], int bookCount)
{
    int i;
    
    printf("listBooks():\n");
    
    if (bookCount == 0)
        printf("The bookshop is empty\n");
    else {
        // Display details of each book
        for (i = 0; i < bookCount; i++) {
            printBook(books[i]);
        }
    }
}


void addBook(Book books[], int *ptBookCount)
{
    int i;
    int bookCount = *ptBookCount;
    Book newBook;
    
    printf("addBook():\n");

    newBook = getNewBook();
    
    // printf("%d, %s, %s, %.2lf, %d\n", newBook.bookID, newBook.title, newBook.author, newBook.price, newBook.quantity);
    
    // Check for duplicate ID
    for (i = 0; i < bookCount; i++) {
        if (books[i].bookID == newBook.bookID) {
            printf("The bookID has already existed! Unable to addBook()\n");
            return;
        }
    }
    
    // Check if max capacity is reached
    if (bookCount == MAX) {
        printf("The bookshop is full! Unable to addBook()\n");
        return;
    }

    // Add book into array (in ascending order of id)
    shiftAndInsert(newBook, books, bookCount);
    
    // Update book count
    (*ptBookCount)++;
    
    printf("The book has been added successfully\n");
}


void removeBook(Book books[], int *ptBookCount)
{
    int i, targetIndex;
    int bookCount = *ptBookCount;
    char title[40], author[40];

    printf("removeBook():\n");

    // Prompt for details of target book (& can be removed)
    // printf("Enter the target book title:\n");
    // scanf(" %[^\n]", &title);
    
    // printf("Enter the target author name:\n");
    // scanf(" %[^\n]", &author);

    getTargetDetails(title, author);

    // Check if array is empty
    if (bookCount == 0) {
        printf("The bookshop is empty\n");
        return;
    }

    // Attempt to find index of target book
    targetIndex = findMatch(books, bookCount, title, author);

    // No matching book found
    if (targetIndex == -1) {
        printf("The target book is not in the bookshop\n");
        return;
    }

    printf("The target book is removed\n");

    // Display details of deleted book
    printBook(books[targetIndex]);

    // Remove target book from array
    shiftAndReplace(books, bookCount, targetIndex);

    // Update book count
    (*ptBookCount)--;
}


// Design can be improved
void findBook(Book books[], int bookCount)
{
    char title[40], author[40];
    int targetIndex;

    printf("findBook():\n");

    // // Prompt for details of target book
    // printf("Enter the target book title:\n");
    // scanf(" %[^\n]", &title);
    
    // printf("Enter the target author name:\n");
    // scanf(" %[^\n]", &author);

    getTargetDetails(title, author);

    // Attempt to find index of target book
    targetIndex = findMatch(books, bookCount, title, author);

    // Array empty or no matching book found
    if (targetIndex == -1) {
        printf("The target book is not found\n");
        return;
    }

    printf("The target book is found\n");

    // Display details
    printBook(books[targetIndex]);
}


void updateBook(Book books[], int bookCount) 
{
    char title[40], author[40];
    int price, quantity, targetIndex;
    
    printf("updateBook():\n");

    // // Prompt for details of target book
    // printf("Enter the target book title:\n");
    // scanf(" %[^\n]", &title);
    
    // printf("Enter the target author name:\n");
    // scanf(" %[^\n]", &author);

    getTargetDetails(title, author);

    // Attempt to find index of target book
    targetIndex = findMatch(books, bookCount, title, author);

    // Array empty or no matching book found
    if (targetIndex == -1) {
        printf("The target book is not in the bookshop\n");
        return;
    }

    printf("Enter updated book price:\n");
    scanf("%lf", &books[targetIndex].price);
    
    printf("Enter updated quantity:\n");
    scanf("%d", &books[targetIndex].quantity);

    printf("The target book is updated\n");

    // Display details of updated book
    printBook(books[targetIndex]);
}


// Helper functions
void printMenu()
{
    // Multi-line string literal
    char *menu = 
        "NTU BOOKSHOP MANAGEMENT PROGRAM:\n"
        "1: listBooks()\n"
        "2: addBook()\n"
        "3: removeBook()\n"
        "4: findBook()\n"
        "5: updateBook()\n"
        "6: quit\n";
    
    printf("%s", menu);
}


void getChoice(int *choice)
{
    printf("Enter your choice:\n");
    scanf("%d", choice);
}


void printBook(Book book)
{
    printf("BookID: %d\n", book.bookID);
    printf("Book title: %s\n", book.title);
    printf("Author name: %s\n", book.author);
    printf("Book price: %.2lf\n", book.price);
    printf("Quantity: %d\n", book.quantity);
}


Book getNewBook()
{
    Book book;
    
    // Prompt for book details
    printf("Enter bookID:\n");
    scanf("%d", &book.bookID);
    
    printf("Enter book title:\n");
    scanf(" %[^\n]", &book.title); // why??
    
    printf("Enter author name:\n");
    scanf(" %[^\n]", &book.author);
    
    printf("Enter price:\n");
    scanf("%lf", &book.price);
    
    printf("Enter quantity:\n");
    scanf("%d", &book.quantity);

    return book;
}


void shiftAndInsert(Book newBook, Book books[], int bookCount)
{
    int i;
    int insert = 0; // default index to insert book

    if (bookCount != 0) {
        // Find index to insert
        for (i = bookCount - 1; i >= 0; i--) {
            if (newBook.bookID > books[i].bookID) {
                insert = i + 1;
                break;
            }
        }
        
        // Shift each book after insertion point
        for (i = bookCount - 1; i >= insert; i--) {
            books[i + 1] = books[i];
        }
    }
    // Insert book into array at target index
    books[insert] = newBook;
}


void shiftAndReplace(Book books[], int bookCount, int targetIndex)
{
    int i;

    if (targetIndex != bookCount - 1) {
        for (i = targetIndex + 1; i < bookCount; i++)
            books[i - 1] = books[i];
    }
}


void getTargetDetails(char title[], char author[])
{
    // Prompt for details of target book
    printf("Enter the target book title:\n");
    scanf(" %[^\n]", title);
    
    printf("Enter the target author name:\n");
    scanf(" %[^\n]", author);
}


// Return index of matching book if found, -1 otherwise
int findMatch(Book books[], int bookCount, char title[], char author[])
{
    int i;

    for (i = 0; i < bookCount; i++) {
        if (matchString(books[i].title, title) && matchString(books[i].author, author))
            return i;
    }

    return -1;
}


// Perform case-insensitive string matching, return 1 if match is found, 0 otherwise
int matchString(char s1[], char s2[])
{
    int i;
    int length = strlen(s1);

    // Check if string have same length
    if (length != strlen(s2))
        return 0;

    for (i = 0; i < length; i++) {
        // Return if mismatch is found
        if (tolower(s1[i]) != tolower(s2[i]))
            return 0;
    }

    return 1;
}