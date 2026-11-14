#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

void initialize(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(const Queue *queue) {
    return queue->front == NULL;
}

int enqueue(Queue *queue, int value) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        return 0;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    return 1;
}

int dequeue(Queue *queue, int *value) {
    if (isEmpty(queue)) {
        return 0;
    }

    Node *removedNode = queue->front;
    *value = removedNode->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(removedNode);
    return 1;
}

void freeQueue(Queue *queue) {
    int value;

    while (dequeue(queue, &value)) {
        /* Remove and free each remaining node. */
    }
}

int main(void) {
    Queue queue;
    int value;

    initialize(&queue);

    if (enqueue(&queue, 10) && enqueue(&queue, 20)) {
        printf("Items added to the queue.\n");
    }

    if (dequeue(&queue, &value)) {
        printf("Removed: %d\n", value);
    } else {
        printf("The queue is empty.\n");
    }

    freeQueue(&queue);
    return 0;
}
