#include <stdio.h>

#define CAPACITY 100

typedef struct {
    int items[CAPACITY];
    int front;
    int rear;
    int count;
} Deque;

void initialize(Deque *deque) {
    deque->front = 0;
    deque->rear = -1;
    deque->count = 0;
}

int isEmpty(const Deque *deque) {
    return deque->count == 0;
}

int isFull(const Deque *deque) {
    return deque->count == CAPACITY;
}

int insertFront(Deque *deque, int value) {
    if (isFull(deque)) {
        return 0;
    }

    deque->front = (deque->front - 1 + CAPACITY) % CAPACITY;
    deque->items[deque->front] = value;

    if (deque->count == 0) {
        deque->rear = deque->front;
    }

    deque->count++;
    return 1;
}

int insertRear(Deque *deque, int value) {
    if (isFull(deque)) {
        return 0;
    }

    deque->rear = (deque->rear + 1) % CAPACITY;
    deque->items[deque->rear] = value;

    if (deque->count == 0) {
        deque->front = deque->rear;
    }

    deque->count++;
    return 1;
}

int deleteFront(Deque *deque, int *value) {
    if (isEmpty(deque)) {
        return 0;
    }

    *value = deque->items[deque->front];
    deque->front = (deque->front + 1) % CAPACITY;
    deque->count--;

    if (deque->count == 0) {
        deque->front = 0;
        deque->rear = -1;
    }

    return 1;
}

int deleteRear(Deque *deque, int *value) {
    if (isEmpty(deque)) {
        return 0;
    }

    *value = deque->items[deque->rear];
    deque->rear = (deque->rear - 1 + CAPACITY) % CAPACITY;
    deque->count--;

    if (deque->count == 0) {
        deque->front = 0;
        deque->rear = -1;
    }

    return 1;
}

int main(void) {
    Deque deque;
    int value;

    initialize(&deque);

    insertFront(&deque, 20);
    insertFront(&deque, 10);
    insertRear(&deque, 30);

    if (deleteFront(&deque, &value)) {
        printf("Removed from front: %d\n", value);
    }

    if (deleteRear(&deque, &value)) {
        printf("Removed from rear: %d\n", value);
    }

    return 0;
}
