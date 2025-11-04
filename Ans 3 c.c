#include <stdio.h>
#define MAX 100

int Queue[MAX];

// Initialize the queue
void initialize() {
    Queue[0] = 2;
    Queue[1] = 1;
}

void enqueue(int value) {
    int front = Queue[0];
    int rear  = Queue[1];

    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    rear++;
    Queue[rear] = value;
    Queue[1] = rear;

    printf("%d inserted into queue.\n", value);
}

void dequeue() {
    int front = Queue[0];
    int rear  = Queue[1];

    if (front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("%d removed from queue.\n", Queue[front]);
    Queue[0]++;  // increment front index
}

void display() {
    int front = Queue[0];
    int rear  = Queue[1];

    if (front > rear) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", Queue[i]);
    printf("\n");
}

int main() {
    initialize();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    return 0;
}
