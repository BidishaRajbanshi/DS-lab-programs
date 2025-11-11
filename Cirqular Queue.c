#include <stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;
// Function to check if the queue is full
int isFull() {
    return (front == (rear + 1) % SIZE);
}
// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}
// Enqueue operation
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = value;
    printf("Inserted %d\n", value);
}
// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    if (front == rear) {
        front = rear = -1; // Queue becomes empty
    } else {
        front = (front + 1) % SIZE;
    }
}
// Display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}
int main() {
    int value, choice;
    while (1) {
        printf("\n\n**** MENU ****\n");
        printf("1. Enqueue\n2. dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
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
                exit(0);
            default:
                printf("\nWrong Selection!! Try again!!");
        }
    }
}
