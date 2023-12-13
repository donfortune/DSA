#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

struct Node* top = NULL;


void push(int item);
void pop();
void peek();
void display();

int main() {
    int ch, item;

    do {
        printf("Enter choice: 1: Push 2: Pop 3: Peek 4: Display 0: Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 0:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (ch != 0);

    return 0;
}

void push(int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = item;
    newNode->link = top;
    top = newNode;

    printf("%d pushed to stack\n", item);
}

void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
    } else {
        struct Node* temp = top;
        printf("%d popped from stack\n", temp->data);
        top = temp->link;
        free(temp);
    }
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        struct Node* current = top;
        printf("Stack elements: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->link;
        }
        printf("\n");
    }
}
