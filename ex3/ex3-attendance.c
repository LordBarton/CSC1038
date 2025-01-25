/*
LAB EXAM 3
TASK 1

Author: Bartosz Kogut
Date: 31/10/2024

Description: This program checks the attendance of each student from the command line. Next it evaluates the student's attendance mark.
Input: strings in CLI consisting of A's, L's or P's
Output: 1 if student failed or 0 if student passed attendance
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Node Node;

// Define struct

struct Node
{
    char value[20];
    Node *next;
};

// Function prototypes

Node *newnode(void);
Node *input(int argc, char *argv[]);
void printlist(Node *head);
int check_attendance(Node *current);

// Creates Node for linked list
Node *newnode()
{
    Node *new = calloc(1, sizeof(Node));    // Allocates memory for node
    return new;
}

int main(int argc, char *argv[])
{
    Node *head = input(argc, argv);
    printlist(head);
    return 0;
}

// Populate linked list with command line input
Node *input(int argc, char *argv[])
{
    Node *head = newnode(); // Allocate memory for new node
    strcpy(head->value, argv[1]); // Give the string as value
    Node *current = head; // Make head the current node

    for (int i = 2; i < argc; i++)
    {
        current->next = newnode(); // Allocate memory for next node
        current = current->next; // Make current point to next node
        strcpy(current->value, argv[i]); // Give string as value to next node
    }
    current->next = NULL; // Make last node point to null

    return head; // Return the head of the list
}

// This function returns either 1 or 0 based on the letters it finds in the attendance
int check_attendance(Node *current)
{
    int len = strlen(current->value);
    char *str = current->value;

    // Set initial count to 1
    int countL = 1;
    int countA = 1;

    // Check for consecutive A's or L's
    for (int i = 0; i < len; i++)
    {
        // If there's a consecutive A, increment count
        if (str[i] == 'A' && str[i + 1] == 'A')
        {
            countA++;
            // If count surpasses 4, return mark 1, fail
            if (countA >= 4)
            {
                return 1;
            }
        }
        if (str[i] == 'L' && str[i + 1] == 'L')
        {
            // If there's a consecutive A, increment count
            countL++;
            // If count is 4, increment A by one
            if (countL == 4)
            {
                countL = 1;
                countA++;
                if (countA >= 4)
                {
                    return 1;
                }
                return 1;
            }
        }

    }
    return 0;
}

// Print attendance mark for each student and print it
void printlist(Node *head)
{
    Node *current = head;

    while (current)
    {
        printf("%d\n", check_attendance(current));
        current = current->next;
    }
}
