#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 10

typedef struct ElementType {
    int key;
} ElementType;

typedef struct Queue
{
    int capacity;
    int front;
    int rear;
    int size;
    ElementType *data;
} Queue;

void initQueue(Queue *q, int capacity){
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->data = (ElementType *)malloc(capacity * sizeof(ElementType));
    if(q->data == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

int isFull(Queue *q) {
    return q->size == q->capacity;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

void enqueue(Queue *q, ElementType element){
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d\n", element.key);
        return;
    }
    q->data[q->rear] = element;
    q->rear = (q->rear + 1) % q->capacity; //다시 제자리로
    q->size++;

}

ElementType dequeue(Queue *q){
    
    if(isEmpty(q)){
        printf("Queue is empty. Cannot dequeue");
        ElementType dummy;
        dummy.key=-1;
        return dummy;
    }
    ElementType temp= q->data[q->front];
    q->data[q->front].key = 0;
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return temp;

}

void printQueue(Queue *q){
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    int i = q->front;
    do {
        printf("%d ", q->data[i].key);
        i = (i + 1) % q->capacity;
    }while (i != q->rear);
    printf("\n");
}

void freeQueue(Queue *q){
    if (q->data != NULL) { free(q->data); }
}

int main() {
    Queue q;
    initQueue(&q, INITIAL_CAPACITY);

    // full
    for (int i = 0; i < 12; i++) {
        ElementType element = {i + 1};
        enqueue(&q, element);
        printQueue(&q);
    }

    // empty
    initQueue(&q, INITIAL_CAPACITY);
    printQueue(&q);

    // enqueue
    for (int i = 0; i < 4; i++){
        ElementType element = {i+1};
        enqueue(&q, element);
        printQueue(&q);
    }


    // dequeue
    ElementType dequeueElement = dequeue(&q);

    printf("Dequeue %d\n", dequeueElement.key);

    printQueue(&q);

    // free
    freeQueue(&q);
    return 0;
}