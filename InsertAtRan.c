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

node *InsertAtRAN(node *head, int x, int p)
{
    if (p < 0) {
        printf("Error: Index out of Range\n");
        return head;
    }
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

    if (p == 0)
    {
        temp->data = x;
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        return temp;
    }

    node *current = head;
    int c = 0;

    while (c != p-1  && current != NULL) {
        current = current->next;
        c++;
    }

    if (current == NULL) {
        printf("Error: Index out of Range\n");
        free(temp);
        return head;
    }

    temp->next = current->next;
    current->next = temp;
    temp->prev = current->prev->next;
    current->next->prev = temp->next;
    

    return head;
}



int main() {
    node *head = NULL;
    int choice, ele, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at random position\n");
        printf("2. Display list\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &ele);
                printf("Enter position to insert at: ");
                scanf("%d", &pos);
                head = InsertAtRAN(head, ele, pos);
                break;
            case 2:
                printList(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}