#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} node;

node *getnode() {
    node *a = (node *)malloc(sizeof(node));
    if (a == NULL) {
        printf("Memory Allocation Failed.\n");
        return NULL;
    }

    return a;
}

void printList(node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

node *InsertAtEnd(node* head, int x)
{
    node *temp = getnode();
    if (temp == NULL)
    {
        printf("Malloc Failed!");
        return head;

    }

    if (head == NULL)
    {
        temp->data = x;
        temp->prev = NULL;
        temp->next = NULL;
        return temp;
    }

    

    else
    {
        temp->data = x;
        temp->next = NULL;
        node *t = head;
        while (t->next != NULL)
        {
            t = t -> next;
        }

        t->next = temp ;
        temp->prev = t;
        temp->next = NULL;

        return head;
    }
}

int main()
{
    node *head = NULL;
    int choice, value;

    while (1)
    {
        printf("Menu:\n");
        printf("1. Insert at End\n");
        printf("2. Print List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = InsertAtEnd(head, value);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}