#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
typedef struct Node Node;

struct Node
{
    int value;  // Value stored in the node
    Node *next;  // Pointer to the next node
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
    head = insert_end(head, 69);
    head = insert_at(head, 2, 7);
    head = remove_head(head);
    head = insert_beginning(head, 420);
    head = remove_tail(head);
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
    while (current->next)
    {
        current = current->next;
    }
    current->next = new;

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
    temp->next = current-> next;
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
    free(temp);

    return head;
}

Node *remove_tail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        free(head);
        return NULL;
    }

    Node *current = head;
    while (current->next && current->next->next)
    {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;

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
    while (current != NULL && count < pos - 1)
    {
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL)
    {
        return head;
    }

    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);

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
