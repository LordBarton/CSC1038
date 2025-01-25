/*
LAB EXAM 2
TASK 3

Author: Bartosz Kogut
Date: 28/11/2024

This program defines and prints a book struct for n books (n given in 1st CLI argument) with their title, author and year of publication.
Then it prints out the books and their details in reverse order as given, with a section for books published after a certain year given in last CLI argument.
Input: number of books, book struct members in CLI, year
Output: details of all books
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// The book struct and its members
typedef struct
{
    char title[100];
    char author[100];
    int year;
} book;

// Prototype functions
void input(int argc, char *argv[], book *pbook, int capacity);
void out(book *b, int capacity, int after_year);
void bubblesort(book *b, int n);

int main(int argc, char *argv[])
{
    book *pbook;

    int num_books = atoi(argv[1]);
    int after_year = atoi(argv[argc - 1]);

    int capacity = num_books;
    pbook = calloc(capacity, sizeof(book));

    // Take book library details and print them out
    input(argc, argv, pbook, capacity);
    out(pbook, capacity, after_year);

    // Free up memory
    free(pbook);

    return 0;
}

// Function to populate the array of book structs
void input(int argc, char *argv[], book *pbook, int capacity)
{
    int count = 0;
    for (int i = 0; i < capacity; i++)
    {
        strcpy(pbook[i].title, argv[count + 2]);
        strcpy(pbook[i].author, argv[count + 3]);
        pbook[i].year = atoi(argv[count + 4]);
        count += 3;
    }
}

// Print out book details
void out(book *b, int capacity, int after_year)
{
    printf("Library Catalog:\n");
    int other_books = 0;
    int n = capacity - 1;
    for (int i = n; i >= 0; i--) // Print in reverse order
    {
        // This shows us if there are any other books we need to print out later
        if (b[i].year >= after_year)
        {
            other_books = 1;
        }
        printf("Title: %s, Author: %s, Year: %d\n", b[i].title, b[i].author, b[i].year);
    }

    // If we found books published after year given in last argument, we print them too
    if (other_books == 1)
    {
        printf("\nBooks published after %d:\n", after_year);
        for (int i = n; i >= 0; i--)
        {
            if (b[i].year >= after_year)
            {
                printf("Title: %s, Author: %s, Year: %d\n", b[i].title, b[i].author, b[i].year);
            }
        }
    }

    // Otherwise we print a message saying there are no extra books
    else
    {
        if (other_books == 0)
        {
            printf("\nBooks published after %d:\n", after_year);
            printf("No books found published after %d.\n", after_year);
        }
    }
}
