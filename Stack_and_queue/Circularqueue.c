#include<stdio.h>
#include<stdlib.h>
//원형큐에서 front와 rear가 같을때 꽉찬건지 비어있는것인지 구분이안간다 그래서 size도 추가한것.
//출력조건문을 front와 rear만으로 하면 스택이 꽉찼을떄 문제가된다.
#define CAPACITY 10 
//rear은 다음에 데이터를 넣을 위치를 가리키고 front는 다음에 삭제할 노드를 가리킴.
typedef struct ElementType{
    int key;
}ElementType;

typedef struct Queue
{
    int capacity;
    int front;
    int rear;
    int size;
    ElementType *data;
}*queue;

void initQueue(queue q, int capacity){
    q->capacity=capacity;
    q->front=0;
    q->rear=0;
    q->size=0;
    q->data=malloc(sizeof(ElementType)*capacity);
    if(q->data==NULL){
        printf("memory allocation failed\n");
        exit(1);
    }
}

int isFull(queue q){ //구조체를 함수인자로 박으면 안되기 떄문에 포인터로 인자를 박는거다
    return q->size==q->capacity;
}

int isEmpty(queue q){
    return q->size==0;
}

void enqueue(queue q, ElementType element){
    if(isFull(q)){
        printf("queue is full, cannot enqueue\n");
        return;
    }

    q->data[q->rear]=element;
    q->rear=(q->rear+1)%q->capacity;
    q->size++;
}

ElementType dequeue(queue q){
    if(isEmpty(q)){
        printf("queue is Empty. cannot dequeue\n");
        ElementType dummy;
        dummy.key=-1;
        return dummy;
    }
    ElementType temp=q->data[q->front];
    q->front=(q->front+1)%q->capacity;
    q->size--;
    return temp;
}

void printQueue(queue q){
    if(isEmpty(q)){
        printf("queue is empty\n");
        return;
    }
    
    int j=q->front;
    
    for(int i=0;i<q->size;i++){
        printf("%d->",q->data[j].key);
        j=(j+1)%q->capacity;

    }
    printf("NULL");
    printf("\n");
}

void freeQueue(queue q){
    if(q->data!=NULL)free(q->data);
}

int main(){
    queue q = malloc(sizeof(struct Queue));
    
    initQueue(q,CAPACITY);
    for(int i=0;i<12;i++){ 
        ElementType e = {i+1};
        enqueue(q,e);
        printQueue(q);
    }

    initQueue(q,CAPACITY);
    printQueue(q);

    for(int i=0;i<4;i++){
        ElementType element = {i+1};
        enqueue(q,element);
        printQueue(q);
    }

    ElementType dequeueElement= dequeue(q);

    printf("Dequeue:%d\n",dequeueElement.key);
    printQueue(q);
    freeQueue(q);
    return 0;

}