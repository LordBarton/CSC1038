/*
LAB EXAM 3
TASK 2
Author: Bartosz Kogut
Date: 18/12/2024

Description: This program accepts a list of positive integers, removes all prime numbers, pushes non prime numbers to the bottom of the list, and prints them one by one, followed by their average.
Input: List of positive integers from the command line
Output: Output the non-prime elements line by line, then the average
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

// Define node struct
struct Node
{
    int value;
    Node *next;
};

// Function prototypes
Node *newnode(void);
Node *input(int argc, char *argv[]);
void print(Node *head);
int is_prime(int num);
float average(float sum, float n);

// Creates node space for linked list
Node *newnode(void)
{
    Node *new = calloc(1, sizeof(Node)); // Allocate memory for node
    return new;
}

int main(int argc, char *argv[])
{
    Node *head = input(argc, argv);
    print(head);

    return 0;
}

// Get all the numbers from command line
Node *input(int argc, char *argv[], int n)
{
    Node *head = newnode(); // create head node
    int i = 1;
    // If a number is a prime, skip it
    while (i < argc && is_prime(atoi(argv[i])) == 1)
    {
        i++;
    }
    printf("%d", n);
    // Give the head value the first encountered non-prime number
    head->value = atoi(argv[i]); // Give head node value
    Node *current = head; // Make current node be the head
    for (int j = i + 1; j < argc; j++)
    {
        // Only add a number to the linked list if it's a non-prime
        if (is_prime(atoi(argv[j])) == 0)
        {
            current->next = newnode(); // Create node for next node
            current = current->next; // Make current point to next node
            current->value = atoi(argv[j]); // Give value to new node
        }
    }
    current->next = NULL; // Make last node point to null

    return head; // Return head of the list
}

void print(Node *head)
{
    float count = 0;
    float sum = 0;
    Node *current = head;

    while (current)
    {
        count++; // Collect count and sum for the average function
        sum += current->value;
        printf("%d\n", current->value);
        current = current->next; // Point to next node in the list
    }

    printf("%.2f\n", average(sum, count));
}

// This function checks if a number is a prime
int is_prime(int num)
{
    if (num == 2 || num == 3 || (num % 2 != 0 && num % 3 != 0))
    {
        return 1; // If its a prime, return 1
    }

    // Otherwise return 0
    return 0;
}

// Calculate average of non-primes in the linked list
float average(float sum, float n)
{
    float result = sum / n;
    return result;
}
