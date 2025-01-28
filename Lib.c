#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h" // Include the cJSON library (available online)

#define MAX_BOOKS 10
#define FILE_NAME "library.json"

struct Book {
    char title[100];
    int author;
    float price;
};
int loadBooksFromFile(struct Book library[], int *numBook) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        return 0;
    }

    char buffer[4096];
    fread(buffer, 1, sizeof(buffer), file);
    fclose(file);

    cJSON *json = cJSON_Parse(buffer);
    if (!json) {
        printf("Error parsing JSON file.\n");
        return 0;
    }

    int count = cJSON_GetArraySize(json);
    for (int i = 0; i < count && i < MAX_BOOKS; i++) {
        cJSON *item = cJSON_GetArrayItem(json, i);
        strcpy(library[i].title, cJSON_GetObjectItem(item, "title")->valuestring);
        library[i].author = cJSON_GetObjectItem(item, "author")->valueint;
        library[i].price = cJSON_GetObjectItem(item, "price")->valuedouble;
    }

    *numBook = count;
    cJSON_Delete(json);
    return 1;
}

void saveBooksToFile(struct Book library[], int numBook) {
    cJSON *json = cJSON_CreateArray();

    for (int i = 0; i < numBook; i++) {
        cJSON *book = cJSON_CreateObject();
        cJSON_AddStringToObject(book, "title", library[i].title);
        cJSON_AddNumberToObject(book, "author", library[i].author);
        cJSON_AddNumberToObject(book, "price", library[i].price);
        cJSON_AddItemToArray(json, book);
    }

    char *jsonString = cJSON_Print(json);
    FILE *file = fopen(FILE_NAME, "w");
    if (file) {
        fwrite(jsonString, 1, strlen(jsonString), file);
        fclose(file);
    }

    free(jsonString);
    cJSON_Delete(json);
}

void addBook(struct Book library[], int *numBook) {
    if (*numBook < MAX_BOOKS) {
        printf("Enter book title: ");
        scanf(" %[^\n]", library[*numBook].title);

        printf("Enter author ID: ");
        if (scanf("%d", &library[*numBook].author) != 1) {
            while (getchar() != '\n');
            printf("Invalid author ID. Book not added.\n");
            return;
        }

        printf("Enter price: ");
        if (scanf("%f", &library[*numBook].price) != 1) {
            while (getchar() != '\n');
            printf("Invalid price. Book not added.\n");
            return;
        }

        (*numBook)++;
        saveBooksToFile(library, *numBook);
        printf("Book added successfully!\n");
    } else {
        printf("Maximum number of books reached.\n");
    }
}

void displayAllBooks(struct Book library[], int numBook) {
    if (numBook > 0) {
        printf("Book Information:\n");
        for (int i = 0; i < numBook; ++i) {
            printf("Title: %s\nAuthor ID: %d\nPrice: %.2f\n", library[i].title, library[i].author, library[i].price);
            printf("_\n");
        }
    } else {
        printf("No books in the library.\n");
    }
}

void displayBooksOfAuthor(struct Book library[], int numBook, int searchAuthor) {
    int found = 0;
    printf("Books by Author ID %d:\n", searchAuthor);
    for (int i = 0; i < numBook; ++i) {
        if (library[i].author == searchAuthor) {
            printf("Title: %s\nPrice: %.2f\n", library[i].title, library[i].price);
            printf("_\n");
            found = 1;
        }
    }
    if (!found) {
        printf("No books found for Author ID %d.\n", searchAuthor);
    }
}

void displayTotalBooks(int numBook) {
    printf("Total number of books in the library: %d\n", numBook);
}

int main() {
    struct Book library[MAX_BOOKS];
    int numBook = 0;
    int choice, searchAuthor;
    

    if (loadBooksFromFile(library, &numBook)) {
        printf("Loaded %d books from the database.\n", numBook);
        
    }

    do {
        printf("\n1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Display Books of Specific Author\n");
        printf("4. Display Total Number of Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a valid option.\n");
            continue;
        }

        switch (choice) {
            case 1:
                addBook(library, &numBook);
                break;
            case 2:
                displayAllBooks(library, numBook);
                break;
            case 3:
                if (numBook > 0) {
                    printf("Enter Author ID to display books: ");
                    if (scanf("%d", &searchAuthor) != 1) {
                        while (getchar() != '\n');
                        printf("Invalid input. Please enter a valid Author ID.\n");
                        continue;
                    }
                    displayBooksOfAuthor(library, numBook, searchAuthor);
                } else {
                    printf("No books are found to display. Add books first.\n");
                }
                break;
            case 4:
                displayTotalBooks(numBook);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
