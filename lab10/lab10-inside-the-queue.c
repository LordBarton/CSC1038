/*
LABSHEET 10
TASK 4

Author: Bartosz Kogut
Date: 18/11/2024

This program uses a singly linked list to store an array of numbers. The first argument is a target number, and the second is the new number to insert into the list after the target.
Input: integers in CLI
Output: integers, updated list
*/

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct Node Node;

struct Node
{
    int data;
    Node *next;
};

// Function prototypes
Node *createnode(int data);
void insertNew(Node *head, int target, int new);
void printlist(Node *head);

int main(int argc, char *argv[])
{
    // Given list
    int list[] = {8,7,3,4,5,6,9,2,14,12};
    int n = sizeof(list) / sizeof(list[0]);
    
    // Get the target and new wanted value from CLI
    int target = atoi(argv[1]); 
    int new = atoi(argv[2]);
    
    // Create the list using the node struct
    Node *head = createnode(list[0]);
    Node *current = head;
    for (int i = 1; i < n; i++)
    {
        current->next = createnode(list[i]);
        current = current->next;
    }

    // Insert the new value after target
    insertNew(head, target, new);
    // print the final list
    printlist(head);

    // Free the allocated memory for the list
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

Node *createnode(int data)
{
    Node *newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}
// Function to push a new element to the end of the list
void insertNew(Node *head, int target, int newValue)
{
    // Look for the target in the list
    Node *current = head;

    while (current != NULL && current->data != target)
    {
        current = current->next;
    }

    // If target was found, insert the new value
    if (current != NULL)
    {
        Node *newNode = createnode(newValue);
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to print the list
void printlist(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
}
