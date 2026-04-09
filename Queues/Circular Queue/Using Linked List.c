#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

// Enqueue
void enqueue(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;

    if (front == NULL) {
        front = rear = newNode;
        newNode->next = front;
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("%d inserted\n", value);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
    }
    else if (front == rear) {
        printf("%d deleted\n", front->data);
        free(front);
        front = rear = NULL;
    }
    else {
        struct node* temp = front;
        printf("%d deleted\n", temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    }
    else {
        struct node* temp = front;
        printf("Queue elements: ");

        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);

        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue (Linked List) ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}