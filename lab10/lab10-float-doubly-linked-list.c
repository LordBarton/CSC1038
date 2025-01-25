/*
LABSHEET 10
TASK 2

Author: Bartosz Kogut
Date: 16/11/2024

This program uses a doubly linked list to store numbers from the command line and print them out in reverse order 1 by 1.
Input: floats in CLI
Output: floating numbers
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Number Number;

// Define struct that'll be used for a linked list node
struct Number {
    float num;
    Number *next;   // Pointer to the next node
    Number *prev;
};

// Function prototype
Number* input(int argc, char *argv[]);
void output_reverse(Number *last);

int main(int argc, char *argv[])
{
    Number *last = NULL;   // Pointer to the start of the list
    last = input(argc, argv);

    output_reverse(last);

    while (last != NULL) {
        Number *temp = last;
        last = last->prev;
        free(temp);
    }

    return 0;
}

// Function to create the singly linked list
Number* input(int argc, char *argv[])
{
    Number *current = NULL, *prev = NULL, *first = NULL;    // Pointers to traverse the list

    // Get all the other numbers by iterating through the CLI arguments
    for (int i = 2; i < argc; i++)
    {
        current = calloc(1, sizeof(Number));  // Allocate memory for the next node

        current->num = atof(argv[i]);   // Assign next number to the current node
        current->prev = prev;

        if (prev != NULL) {
            prev->next = current;   // Link the previous node to the current node
        }

        prev = current;     // Update the previous node pointer
    }

    return current;   // Set the last node to NULL
}

void output_reverse(Number *last)
{
    for (Number *p = last; p != NULL; p = p->prev)
    {
        printf("%.2f\n", p->num);
    }
}
