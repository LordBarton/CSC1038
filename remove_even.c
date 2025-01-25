/*
Author: Bartosz Kogut
Date: 18/12/2024

Description: This program accepts a list of positive integers, removes all even numbers, pushes odd numbers to the bottom of the list, and prints them one by one, followed by their sum.
Input: List of positive integers from the command line
Output: Output the odd elements line by line, then the sum of them
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Type definitions
typedef struct Node Node;

// Structure definitions
struct Node
{
    int value;
    Node *next, *prev;
};

// Function prototypes

// Function that returns a new node
Node *getNodes(int *length, char *argv[]);

// Function to create a linked list
Node *newNode(void);

// Function that deletes all the even nodes from the linked list
Node *deleteEven(Node *head);

// Function that prints all nodes in the linked list with their sum
void printNodes(int *length, Node *head);

// Main function
int main(int argc, char *argv[])
{
    int length = argc - 1; // Initialize the length variable

    Node *head = getNodes(&length, argv); // Create a linked list from the given numbers
    head = deleteEven(head); // Delete all the even numbers from the linked list
    printNodes(&length, head); // Print all the elements of the linked list with their sum (excluding even numbers)
    return 0; // Return 0 for success
}

// Function to create a linked list
Node *getNodes(int *length, char *argv[])
{
    Node *head, *current, *prev; // Initialize the head and current to be the first node
    head = newNode(); // Make head a new node
    current = head; // Assign the current value to head
    current->prev = NULL; // Set the previous linked list to NULL
    for (int i = 0; i < *length; ++i) // Iterate through the values
    {
        prev = current; // Make the previous equal to the current
        current->next = newNode(); // Create a new linked list

        current->value = atoi(argv[i + 1]); // Fill out the first node

        current = current->next; // Move to the next node
        current->prev = prev; // Set the previous linked list to the prev
    }
    current->next = NULL; // End the linked list
    return head; // Return the head
}

// Function that returns a new node
Node *newNode()
{
    Node *new = (Node *)calloc(1, sizeof(Node)); // Allocate memory dynamically
    if (!new) // If there's an error allocating memory
    {
        printf("Error Allocating Memory!\n"); // Print an error message
        exit(0); // Exit the program
    }
    return new; // Return the new node
}

// Function that deletes all the even nodes from the linked list
Node *deleteEven(Node *head)
{
    Node *current, *prev, *tmp; // Initialize the node pointers
    current = head; // Make the current value equal to head
    while (current->next) // Iterate through the list
    {
        if (current->value % 2 == 0) // If the current value is even
        {
            if (current == head) // If the current value equals the head
            {
                head = current->next; // Make the linked list
                head->prev = NULL; // Set the prev to NULL
                current = head; // Make current equal to head
            }
            else if (current->next == NULL) // Otherwise, if the next is NULL
            {
                current->prev->next = NULL; // Do nothing
                current = NULL; // Make the current value NULL
            }
            else // Otherwise
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                tmp = current->prev; // Make temp equal to prev
                free(current); // Free the current dynamically allocated memory
                current = tmp; // Make the current equal to tmp
            }
        }
        else
        {
            current = current->next; // Otherwise, make the current equal to the next value
        }
    }
    return head; // Return the head value
}

// Function that prints all nodes in the linked list with their sum
void printNodes(int *length, Node *head)
{
    Node *current; // Make the current node
    current = head; // Make current equal to head
    int sum = current->value; // Initialize the sum variable
    while (current->next) // Iterate through the linked list
    {
        printf("%d\n", current->value); // Print the current value of our linked list
        current = current->next; // Go to the next value on a new line
        sum += current->value; // Add the values together
    }
    printf("%d\n", sum); // Print the total sum of the linked list without the even values
}
