#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
    }
    else {
        if (front == -1) {   // First element
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % MAX;
        }
        queue[rear] = value;
        printf("%d inserted\n", value);
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
    }
    else {
        printf("%d deleted\n", queue[front]);

        if (front == rear) {   // Only one element
            front = rear = -1;
        }
        else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue elements: ");

        if (rear >= front) {
            for (i = front; i <= rear; i++)
                printf("%d ", queue[i]);
        }
        else {
            for (i = front; i < MAX; i++)
                printf("%d ", queue[i]);
            for (i = 0; i <= rear; i++)
                printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue ---\n");
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