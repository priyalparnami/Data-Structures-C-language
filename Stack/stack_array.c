#include <stdio.h>
#define SIZE 5
int stack[SIZE];
int top = -1;
void push(int val){
    if (top==SIZE-1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top]=val;
        printf("%d pushed into stack\n",val);
    }
}
void pop(){
    if (top==-1){
        printf("Stack Underflow\n");
    }
    else{
        int temp;
        temp=top;
        top--;
        printf("%d popped out of stack\n",stack[temp]);
    }
}
int main()
{
    int choice, value;
    while(1)
    {
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter value to push: ");
                scanf("%d",value);
                push(value);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                return 0;
            }
            default:
            {
                printf("Invalid choice\n");
            }
        }
    }
}