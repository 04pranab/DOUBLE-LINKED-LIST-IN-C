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

node *delete(node *head, int x)
{
    node *t = head;
    if (head == NULL)
    {
        return NULL;
    }

    while (t != NULL)
    {
        if (t->data == x)
        {
            if (t == head)
            {
                head = head->next;
                if (head != NULL)
                {
                    head->prev = NULL;
                }
                free(t);
                return head;
            }
            else if (t->next == NULL)
            {
                t->prev->next = NULL;
                free(t);
                return head;
            }
            else
            {
                t->next->prev = t->prev;
                t->prev->next = t->next;

                free(t);
                return head;
            }
        }
        else
        {
            t = t->next;
        }
    }

    return head;
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

    head = delete (head, 2);

    printf("List after deleting 2: ");
    printList(head);

    head = delete (head, 1);

    printf("List after deleting 1: ");
    printList(head);

    head = delete (head, 3);

    printf("List after deleting 3: ");
    printList(head);


    return 0;
}
