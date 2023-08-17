#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void enqueue(struct Queue *q, int item) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        q->rear++;
        q->items[q->rear] = item;
        printf("Enqueued: %d\n", item);
    }
}

int dequeue(struct Queue *q) {
    if (q->front > q->rear) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } else {
        int dequeuedItem = q->items[q->front];
        q->front++;
        return dequeuedItem;
    }
}

void display(struct Queue q) {
    if (q.front > q.rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = q.front; i <= q.rear; i++) {
            printf("%d ", q.items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    q.front = 0;
    q.rear = -1;

    int choice, item;

    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2:
                item = dequeue(&q);
                if (item != -1) {
                    printf("Dequeued item: %d\n", item);
                }
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}

