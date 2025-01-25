/*
LAB EXAM 2
TASK 2

Author: Bartosz Kogut
Date: 28/11/2024

This program finds the most frequent element (degree) in singly linked list of integers from the command line and prints it out.
I decided to first make the nodes for each integer, populate the linked list and sort the array with bubble sort to make it easier to iterate over the same numbers and count their frequency, comparing it with each new element.
Input: integers in CLI
Output: number of occurences of the most frequent integer
*/


#include<stdio.h>
#include<stdlib.h>

typedef struct Number Number;

// Define struct that'll be used for a linked list node
struct Number {
    int num;
    Number *next;   // Pointer to the next node
};

// Function prototype
Number* input(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    Number *start = NULL;   // Pointer to the start of the list
    start = input(argc, argv);

    // Iterate through the list using a pointer p and print the numbers
    for (Number *p = start; p != NULL; p = p->next)
    {
        printf("%d\n", p->num);
    }

    // Free the allocated memory for the list
    Number *current = start;
    while (current != NULL) {
        Number *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

// Function to create the singly linked list
Number* input(int argc, char *argv[])
{
    Number *current, *first;    // Pointers to traverse the list
    int i = 0;

    first = calloc(1, sizeof(Number));  // Allocate memory for the first node

    current = first;    // Set current pointer to the first node
    current->num = atoi(argv[1]);   // Get first number

    // Get all the other numbers by iterating through the CLI arguments
    while (i < argc - 2)
    {
        current->next = calloc(1, sizeof(Number));  // Allocate memory for the next node
        current = current->next;    // Set the next node as the current one
        i++;
        current->num = atoi(argv[i + 1]);   // Assign next number to the current node
    }

    current->next = NULL;   // Set the last node to NULL

    return first;
}
