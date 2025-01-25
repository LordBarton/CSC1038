#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

Node *newnode(void);
Node *input(int length, char *argv[]);
void printlist(Node *head);
Node *pop(Node *head);
Node *push(Node *head, int argc, int num);

int main(int argc, char *argv[])
{
    int length = atoi(argv[1]);
    Node *head = input(length, argv);

    head = pop(head);
    head = pop(head);

    int first = atoi(argv[argc - 2]);
    int second = atoi(argv[argc - 1]);
    head = push(head, argc, first);
    head = push(head, argc, second);

    printlist(head);

    return 0;
}

Node *newnode(void)
{
    Node *new = calloc(1, sizeof(Node));
    return new;
}

Node *input(int length, char *argv[])
{
    Node *head = newnode();
    head->value = atoi(argv[2]);
    Node *current = head;

    for (int i = 0; i < length - 1; i++)
    {
        current->next = newnode();
        current = current->next;
        current->value = atoi(argv[i + 3]);
    }
    current->next = NULL;
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

Node *pop(Node *head)
{
    Node *current = head;
    while (current->next->next)
    {
        current = current->next;
    }

    Node *temp = current->next;
    current->next = NULL;
    free(temp);

    return head;
}

Node *push(Node *head, int argc, int num)
{
    Node *current = head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = newnode();
    current->next->value = num;
    current->next->next = NULL;

    return head;
}
