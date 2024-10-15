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

node *InsertAtBeg(node *head, int x)
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

    temp->data = x;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    return temp;
}


int main() {
    node *head = NULL;
    int choice, value;

    while (1) {
        printf("1. Insert at Beginning\n");
        printf("2. Print List\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = InsertAtBeg(head, value);
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