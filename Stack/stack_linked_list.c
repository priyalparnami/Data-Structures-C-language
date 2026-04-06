#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;
node *top = NULL;

void push(int val){
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL){
        printf("Memory not allocated\n");
        return;
    }
    temp->data = val;
    temp->next = top;
    top = temp;
    printf("%d pushed into stack\n", val);
}

void pop(){
    node *temp;
    if (top == NULL){
        printf("Stack is empty\n");
        return;
    }
    temp = top;
    top = top->next;
    printf("%d is deleted\n", temp->data);
    free(temp);
}

void display(){
    struct node *temp = top;
    if (top == NULL){
        printf("Stack is empty\n");
        return;
    }
    while (temp != NULL){
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice, val;
    while(1){
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}