/*
LABSHEET 10
TASK 3

Author: Bartosz Kogut
Date: 18/11/2024

This program uses a singly linked list to store an array of numbers with its size given by the first argument. Following n arguments are the integers in the list,
next the program pops 2 last numbers in the lsit and pushes 2 last arguments to it.
Input: integers in CLI
Output: integers, updated list
*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct Number {
    int num;
    struct Number *next;
} Number;

// Function prototypes
Number* input(int argc, char *argv[]);
void pop(Number **first);
void push(Number *first, int value);
void displayList(Number *first);

int main(int argc, char *argv[])
{
    Number *start = NULL; // Pointer to the start of the list
    start = input(argc, argv);

    // Perform two pops
    pop(&start);
    pop(&start);

    // Perform two pushes
    int push1 = atoi(argv[argc - 2]);
    int push2 = atoi(argv[argc - 1]);
    push(start, push1);
    push(start, push2);

    // Display the final list
    displayList(start);

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
    int len = atoi(argv[1]);  // Number of elements in the list
    Number *current, *first;
    int i = 0;

    first = calloc(1, sizeof(Number));  // Allocate memory for the first node
    current = first;                   // Start with the first node
    current->num = atoi(argv[2]);      // Assign the first value

    // Create the rest of the list
    for (i = 1; i < len; i++) {
        current->next = calloc(1, sizeof(Number));  // Allocate memory for the next node
        current = current->next;                   // Move to the new node
        current->num = atoi(argv[i + 2]);          // Assign the value
    }

    current->next = NULL;  // Mark the end of the list
    return first;
}

// Function to pop the last element from the list
void pop(Number **first)
{
    if (*first == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Handle case with only one node
    if ((*first)->next == NULL) {
        free(*first);
        *first = NULL;
        return;
    }

    // Traverse to the second-to-last node
    Number *current = *first;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Free the last node and update the second-to-last node's next pointer
    free(current->next);
    current->next = NULL;
}

// Function to push a new element to the end of the list
void push(Number *first, int value)
{
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Traverse to the last node
    Number *current = first;
    while (current->next != NULL) {
        current = current->next;
    }

    // Allocate and assign the new node
    current->next = calloc(1, sizeof(Number));
    current->next->num = value;
    current->next->next = NULL;
}

// Function to print the list
void displayList(Number *first)
{
    for (Number *p = first; p != NULL; p = p->next) {
        printf("%d\n", p->num);
    }
}
