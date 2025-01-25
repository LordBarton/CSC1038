#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure for Doubly Linked List
typedef struct Node Node;

struct Node
{
    int value;      // Value stored in the node
    Node *next;     // Pointer to the next node
    Node *prev;     // Pointer to the previous node
};

// Function prototypes
Node *newNode(void);
Node *input(int argc, char *argv[]);
void print(Node *head);
Node *remove_head(Node *head);
Node *remove_at(Node *head, int pos);

int main(int argc, char *argv[])
{
    // Build the linked list from command-line arguments
    Node *head = input(argc, argv);
   
    head = remove_at(head, 3);
    printlist(head);

    return 0;
}

// Function to create a new node
Node *newNode(void)
{
    Node *new = calloc(1, sizeof(Node)); // Allocate memory for a new node
    return new;
}

Node *input(int argc, char *argv[])
{
    if (argc < 2)
    {
        return NULL;
    }
    Node *head = newNode();
    head->value = atoi(argv[1]);
    Node *current = head;

    for (int i = 2; i < argc; ++i)
    {
        current->next = newNode();
        current->next->prev = current; // Set the previous pointer
        current = current->next;
        current->value = atoi(argv[i]);
    }

    current->next = NULL;
    return head;
}

Node *remove_head(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL; // Set the previous pointer of the new head to NULL
    }

    free(temp);
    return head;
}

Node *remove_at(Node *head, int pos)
{
    if (head == NULL)
    {
        return head;
    }

    if (pos == 1)
    {
        return remove_head(head);
    }

    Node *current = head;
    int count = 1;

    // Traverse to the position before the node to be removed
    while (current != NULL && count < pos)
    {
        current = current->next;
        count++;
    }

    if (current == NULL) // Position out of bounds
    {
        printf("Position is out of bounds.\n");
        return head;
    }

    if (current->prev != NULL)
    {
        current->prev->next = current->next; // Adjust the previous node's next pointer
    }

    if (current->next != NULL)
    {
        current->next->prev = current->prev; // Adjust the next node's prev pointer
    }

    free(current); // Free the node to be removed
    return head;
}

Node *makelist(Node *head)
{
    Node *current = head;
    for (int i = 0; i < argc - 1; i++)
    {
        int count = 0:
        while (is_prime(current->value) == 0)
        {
            current = current->next;
            count++;
        }
        if (count == argc)
        current = remove_at(head)
        
    }
}
void print(Node *head)
{
    Node *current = head;
    int sum = 0;
    int count = 0;
    while (current)
    {
        count++;
        sum += current->value;
        printf("%d/n", current->value);
        current = current->next;
    }
    printf("%.2f/n", average(sum, count));
}

int is_prime(int num)
{
    if (num == 2 || num % 2 != 0)
    {
        return 1;
    }
    return 0;
}

float average(int sum, int n)
{
    return sum / n;
}