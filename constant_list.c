#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

Node *newNode(void);
Node *constant_list(int *nums);
Node *insert_at(Node *head, int target, int data);
void printlist(Node *head);

Node *newNode(void)
{
    Node *new = calloc(1, sizeof(Node));

    return new;
}

int main(int argc, char *argv[])
{
    int nums[10] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
    int *pnums = nums;

    Node *head = constant_list(pnums);
    
    int target = atoi(argv[1]);
    int data = atoi(argv[2]);

    head = insert_at(head, target, data);
    printlist(head);
    
    return 0;
}

Node *constant_list(int *nums)
{
    Node *head = newNode();
    head->value = *nums;
    Node *current = head;
    *nums++;
    for (int i = 1; i < 10; i++)
    {
        current->next = newNode();
        current = current->next;
        current->value = *nums++;
    }
    current->next = NULL;

    return head;
}

Node *insert_at(Node *head, int target, int data)
{
    Node *current = head;

    while (current->value != target)
    {
        current = current->next;
    }

    Node *temp = current->next;
    Node *new = newNode();
    new->value = data;

    current->next = new;
    new->next = temp;

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
