#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

Node *newnode(void);
Node *input(int argc, char *argv[]);
void print(Node *head);

Node *newnode(void)
{
    Node *new = calloc(1, sizeof(Node));
    return new;
}

int main(int argc, char *argv[])
{
    Node *head = input(argc, argv);
    print(head);

    return 0;
}

Node *input(int argc, char *argv[])
{
    Node *head = newnode();
    int i = 0;
    while (atoi(argv[i]) % 2 == 0 && i < argc)
    {
        i++;
    }
    head->value = atoi(argv[i]);
    Node *current = head;
    for (int j = i + 1; j < argc; j++)
    {
        while (atoi(argv[j]) % 2 == 0)
        {
            j++;
        }
            current->next = newnode();
            current = current->next;
            current->value = atoi(argv[j]);
    }
    current->next = NULL;

    return head;
}

void print(Node *head)
{
    Node *current = head;

    while (current)
    {
        printf("%d", current->value);
        current = current->next;
    }
}
