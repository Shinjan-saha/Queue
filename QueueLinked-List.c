
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front;
    struct Node *rear;
};

struct Queue *createQueue() {
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    if (!q) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue *q, int item) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    newNode->data = item;
    newNode->next = NULL;

    if (!q->rear) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("Enqueued: %d\n", item);
}

int dequeue(struct Queue *q) {
    if (!q->front) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int dequeuedItem = q->front->data;
    struct Node *temp = q->front;
    q->front = q->front->next;
    free(temp);

    return dequeuedItem;
}

void display(struct Queue *q) {
    if (!q->front) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        struct Node *current = q->front;
        while (current) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue *q = createQueue();

    int choice, item;

    while (1) {
        printf("\nSelect an option for Queue in Linked-List:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display queue\n");
        printf("4. Quit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(q, item);
                break;
            case 2:
                item = dequeue(q);
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
