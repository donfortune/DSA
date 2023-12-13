#include <stdio.h>


#define N 5

int stack[N];
int top = -1;


void Push();
void Pop();
void Peek();
void Display();

void main() {
    int ch;

    do {
        printf("Enter choice: 1: Push 2: Pop 3: Peek 4: Display 0: Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                Push();
                break;
            case 2:
                Pop();
                break;
            case 3:
                Peek();
                break;
            case 4:
                Display();
                break;
            case 0:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (ch != 0);

    getchar();
}

void Push() {
    int item;
    if (top == N - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter element to push: ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
        printf("%d pushed to stack\n", item);
    }
}

void Pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d popped from stack\n", stack[top]);
        top--;
    }
}

void Peek() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void Display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
