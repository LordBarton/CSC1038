#include<stdlib.h>
#include<stdio.h>

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

Node *newnode(void);
Node *input(int argc, char *argv[]);
Node *bubblesort(Node *head, int n);
Node *mostfreq(Node *head);
void printlist(Node *head);

Node *newnode()
{
    Node *new = calloc(1, sizeof(Node));
    return new;
}

int main(int argc, char *argv[])
{
    Node *head = input(argc, argv);
    int n = argc - 1;
    head = bubblesort(head, n);
    printlist(head);

    return 0;
}

Node *input(int argc, char *argv[])
{
    Node *head = newnode();
    head->value = atoi(argv[1]);
    Node *current = head;

    for (int i = 2; i < argc; i++)
    {
        current->next = newnode();
        current = current->next;
        current->value = atoi(argv[i]);
    }
    current->next = NULL;

    return head;
}

Node *bubblesort(Node *head, int n) {
    if (!head || !head->next) {
        // If the list is empty or has only one node, it's already sorted
        return head;
    }

    for (int i = 0; i < n; i++) {
        Node *current = head;
        Node *prev = NULL;
        Node *next = NULL;

        // Traverse the list and perform swapping
        while (current->next) {
            next = current->next;
            if (current->value > next->value) {
                // Swap current and next
                if (prev) {
                    prev->next = next;
                } else {
                    head = next; // Update head if swapping involves the first node
                }
                current->next = next->next;
                next->next = current;

                // Update `prev` to the new position
                prev = next;
            } else {
                // Move forward without swapping
                prev = current;
                current = current->next;
            }
        }
    }

    return head;
}


Node *mostfreq(Node *head)
{
    Node *current = head;
    while (current)
    {

    }
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
