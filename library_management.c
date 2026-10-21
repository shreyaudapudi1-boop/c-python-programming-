
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    char author[100];
    int available;
};

struct Book books[MAX_BOOKS];
int count = 0;

void addBook(void) {
    if (count >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    printf("Enter book ID: ");
    if (scanf("%d", &books[count].id) != 1) {
        printf("Invalid input.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (books[i].id == books[count].id) {
            printf("Book ID already exists!\n");
            return;
        }
    }

    printf("Enter book title: ");
    scanf(" %99[^\n]", books[count].title);

    printf("Enter author name: ");
    scanf(" %99[^\n]", books[count].author);

    books[count].available = 1;
    count++;

    printf("Book added successfully!\n");
}

void displayBooks(void) {
    if (count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\n--- Library Books ---\n");

    for (int i = 0; i < count; i++) {
        printf("\nID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n",
               books[i].id,
               books[i].title,
               books[i].author,
               books[i].available ? "Available" : "Borrowed");
    }
}

void searchBook(void) {
    int id;
    printf("Enter book ID to search: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("Found: %s by %s\n",
                   books[i].title, books[i].author);
            printf("Status: %s\n",
                   books[i].available ? "Available" : "Borrowed");
            return;
        }
    }

    printf("Book not found.\n");
}

void borrowBook(void) {
    int id;
    printf("Enter book ID to borrow: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            if (books[i].available) {
                books[i].available = 0;
                printf("Book borrowed successfully!\n");
            } else {
                printf("Book is already borrowed.\n");
            }
            return;
        }
    }

    printf("Book not found.\n");
}

int main(void) {
    int choice;

    do {
        printf("\n=== Library Management ===\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Borrow Book\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return 1;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: borrowBook(); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
