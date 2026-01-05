#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node* NODE;
NODE push(NODE top);
NODE pop(NODE top);
void displayStack(NODE top);
NODE enqueue(NODE front, NODE *rear);
NODE dequeue(NODE front, NODE *rear);
void displayQueue(NODE front);
int main() {
    NODE stackTop = NULL;
    NODE queueFront = NULL, queueRear = NULL;
    int choice;
    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                stackTop = push(stackTop);
                break;
            case 2:
                stackTop = pop(stackTop);
                break;
            case 3:
                displayStack(stackTop);
                break;
            case 4:
                queueFront = enqueue(queueFront, &queueRear);
                break;
            case 5:
                queueFront = dequeue(queueFront, &queueRear);
                break;
            case 6:
                displayQueue(queueFront);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
NODE push(NODE top) {
    int item;
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return top;
    }
    printf("Enter item to push: ");
    scanf("%d", &item);
    newNode->data = item;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto stack\n", item);
    return top;
}
NODE pop(NODE top) {
    if (top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return top;
    }
    NODE temp = top;
    printf("Popped item: %d\n", temp->data);
    top = top->next;
    free(temp);
    return top;
}
void displayStack(NODE top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    NODE temp = top;
    printf("Stack (Top -> Bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
NODE enqueue(NODE front, NODE *rear) {
    int item;
    NODE newNode = (NODE)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return front;
    }
    printf("Enter item to enqueue: ");
    scanf("%d", &item);
    newNode->data = item;
    newNode->next = NULL;
    if (front == NULL) {
        front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    printf("%d enqueued into queue\n", item);
    return front;
}
NODE dequeue(NODE front, NODE *rear) {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return front;
    }
    NODE temp = front;
    printf("Dequeued item: %d\n", temp->data);
    front = front->next;
    if (front == NULL) {
        *rear = NULL;  // queue becomes empty
    }
    free(temp);
    return front;
}
void displayQueue(NODE front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    NODE temp = front;
    printf("Queue (Front -> Rear): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}