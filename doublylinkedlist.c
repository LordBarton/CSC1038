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
Node *insert_end(Node *head, int data);
Node *newNode(void);
Node *input(int argc, char *argv[]);
void printlist(Node *head);
Node *insert_end(Node *head, int data);
Node *insert_beginning(Node *head, int data);
Node *insert_at(Node *head, int pos, int data);
Node *remove_head(Node *head);
Node *remove_tail(Node *head);
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

Node *insert_beginning(Node *head, int data)
{
    Node *new = newNode();
    new->value = data;
    new->next = head;

    if (head != NULL)
    {
        head->prev = new; // Set the previous pointer of the old head
    }

    return new;
}

Node *insert_end(Node *head, int data)
{
    if (head == NULL)
    {
        return insert_beginning(head, data);
    }

    Node *new = newNode();
    new->value = data;
    Node *current = head;
    
    // Traverse to the end of the list
    while (current->next)
    {
        current = current->next;
    }

    current->next = new;
    new->prev = current; // Set the previous pointer of the new last node

    return head;
}

Node *insert_at(Node *head, int pos, int data)
{
    if (pos == 1)
    {
        return insert_beginning(head, data);
    }

    Node *current = head;
    int count = 1;

    // Traverse to the position before where the node should be inserted
    while (count < pos - 1 && current != NULL)
    {
        current = current->next;
        count++;
    }

    if (current == NULL) // If position is out of bounds
    {
        printf("Position is out of bounds.\n");
        return head;
    }

    Node *temp = newNode();
    temp->value = data;
    temp->next = current->next;
    temp->prev = current;

    if (current->next != NULL)
    {
        current->next->prev = temp; // Set the previous pointer of the next node
    }
    current->next = temp;

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

Node *remove_tail(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *current = head;

    // Traverse to the last node
    while (current->next != NULL)
    {
        current = current->next;
    }

    if (current->prev != NULL)
    {
        current->prev->next = NULL; // Set the next pointer of the previous node to NULL
    }
    
    free(current);
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

void printlist(Node *head)
{
    Node *current = head;
    while (current)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}
