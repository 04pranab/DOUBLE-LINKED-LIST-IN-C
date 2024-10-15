#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} node;

node *getnode()
{
    node *a = (node *)malloc(sizeof(node));
    if (a == NULL)
    {
        printf("Memory Allocation Failed.\n");
        return NULL;
    }

    return a;
}

void printList(node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

node *erase(node *head)
{
    node *t=head;
    if (head == NULL)
    {
        free(t);
        return NULL;
    }

    else
    {
        while (head!=NULL)
        {
            t = head;
            head = head->next;
            free(t);
        }
    }
}

int main()
{
    node *head = getnode();

    head->data = 1;

    node *second = getnode();
    second->data = 2;
    head->next = second;
    second->prev = head;

    node *third = getnode();

    third->data = 3;
    second->next = third;
    third->prev = second;
    third->next = NULL;

    printf("Original List: ");
    printList(head);

    head = erase (head);

    printf("List after Erase: ");
    printList(head);
}