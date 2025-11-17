#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

// Check if full
int isFull() {
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
        return 1;
    return 0;
}

// Check if empty
int isEmpty() {
    if (front == -1)
        return 1;
    return 0;
}

// Insert item
void enQueue(int element) {
    if (isFull()) {
        printf("\nQueue is full!\n");
    } else {
        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        items[rear] = element;

        printf("\nInserted -> %d\n", element);
    }
}

// Delete item
int deQueue() {
    if (isEmpty()) {
        printf("\nQueue is empty!\n");
        return -1;
    }

    int element = items[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    printf("\nDeleted -> %d\n", element);
    return element;
}

// Display queue
void display() {
    if (isEmpty()) {
        printf("\nQueue is empty!\n");
        return;
    }

    printf("\nFront -> %d", front);
    printf("\nItems -> ");

    int i;
    for (i = front; i != rear; i = (i + 1) % SIZE)
        printf("%d ", items[i]);

    printf("%d ", items[i]); // last element

    printf("\nRear -> %d\n", rear);
}

int main() {
    int choice, value;

    while (1) {
        printf("\n------ CIRCULAR QUEUE MENU ------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enQueue(value);
                break;

            case 2:
                deQueue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting...\n");
                return 0;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
}
