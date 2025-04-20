#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define CAPACITY 10
 //원형큐는 넣고 rear증가 선형큐는 rear증가후 넣기 원형큐는 성격이급해서 박고본다
typedef struct Queue
{
    int capacity;
    int front;
    int rear;
    int currentSize;
    int * data;
}*queue;

void initQueue(queue q, int capacity){
    q->capacity = capacity;
    q->front = 0; q->rear =0; q->currentSize=0; //선형큐는 rear가 -1 원형큐는 rear 0부터 시작
    q->data = malloc(sizeof(int)*capacity);
    if(!q->data){
        printf("memory allocation failed\n");
        exit(1);
    }
}

bool isFull(queue q){
    return q->currentSize == q->capacity;
}

bool isEmpty(queue q){
    return q->currentSize==0;
}

void enqueue(queue q, int data){
    if(isFull(q))return;

    q->data[q->rear] = data;
    q->rear = (q->rear+1)% q->capacity;
    q->currentSize++;
}

int dequeue(queue q){
    if(isEmpty(q))return -1;
    int temp = q->data[q->front];
    q->front = (q->front+1)%q->capacity;
    q->currentSize--;
    return temp;
}

void printQueue(queue q){
    if(isEmpty(q))return;

    int j= q->front;
    for(int i=0;i<q->currentSize;i++){
        printf("%d-> ",q->data[j]);
        j=(j+1)%q->capacity;
    }
    printf("NULL\n");
}
void freeQueue(queue q){
    if(q->data!=NULL)free(q->data);
}

int main(){
    queue q = malloc(sizeof(struct Queue));
    
    initQueue(q,CAPACITY);
    for(int i=0;i<12;i++){ 
        int e = {i+1};
        enqueue(q,e);
        printQueue(q);
    }

    initQueue(q,CAPACITY);
    printQueue(q);

    for(int i=0;i<4;i++){
        int element = {i+1};
        enqueue(q,element);
        printQueue(q);
    }

    int data= dequeue(q);

    printf("Dequeue:%d\n",data);
    printQueue(q);
    freeQueue(q);
    return 0;

}