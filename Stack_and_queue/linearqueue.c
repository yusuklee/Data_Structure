#include <stdio.h>

#define MAX_QUEUE_SIZE 100

void printQueue();

typedef struct 
{
    int key;
} element;

element queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = 0;

void printQueue(){
    if(front > rear){
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++){
        printf("%d ", queue[i].key);
    }

    printf("\n\n");
}

void enqueue(element item){
    if (rear >= MAX_QUEUE_SIZE - 1){
        printf("Queue overflow!\n");
        return;
    }

    rear++;
    queue[rear] = item;
    

    printf("Enqueue: key = %d\n", item.key);
    printQueue();
}

element dequeue(){
    
    if (front >rear){
        printf("Queue underflow!\n");
        element dummy;
        dummy.key=-1;
        return dummy;
    }
    element item = queue[front];
    front++;

    printf("Dequeue\n");
    printQueue();

    return item;
}

int main(){
    element input;
    input.key = 1;
    enqueue(input);

    input.key = 2;
    enqueue(input);

    input.key = 3;
    enqueue(input);

    input.key = 4;
    enqueue(input);

    element output;
    output = dequeue();
    printf("Dequeue: %d\n", output.key);
    output = dequeue();
    printf("Dequeue: %d\n", output.key);
    output = dequeue();
    printf("Dequeue: %d\n", output.key);
    output = dequeue();
    printf("Dequeue: %d\n", output.key);
    
    return 0;

}
