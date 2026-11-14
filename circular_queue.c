#include <stdio.h>

#define CAPACITY 5

typedef struct {
    int items[CAPACITY];
    int front;
    int rear;
    int count;
} CircularQueue;

void initialize(CircularQueue *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

int isEmpty(const CircularQueue *queue) {
    return queue->count == 0;
}

int isFull(const CircularQueue *queue) {
    return queue->count == CAPACITY;
}

int enqueue(CircularQueue *queue, int value) {
    if (isFull(queue)) {
        return 0;
    }

    queue->rear = (queue->rear + 1) % CAPACITY;
    queue->items[queue->rear] = value;
    queue->count++;
    return 1;
}

int dequeue(CircularQueue *queue, int *value) {
    if (isEmpty(queue)) {
        return 0;
    }

    *value = queue->items[queue->front];
    queue->front = (queue->front + 1) % CAPACITY;
    queue->count--;
    return 1;
}

int main(void) {
    CircularQueue queue;
    int value;

    initialize(&queue);

    if (enqueue(&queue, 10)) {
        printf("Enqueued 10\n");
    }
    if (enqueue(&queue, 20)) {
        printf("Enqueued 20\n");
    }
    if (dequeue(&queue, &value)) {
        printf("Dequeued %d\n", value);
    }

    return 0;
}
