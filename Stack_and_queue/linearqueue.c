#include<stdio.h>
#define MAX 100

void printQueue();

typedef struct{
    int key;
}element;

element queue[MAX];
int rear= -1;
int front=0;

void printQueue(){
    if(front>rear){printf("queue is empty!\n"); return;}
   printf("Queue:");
   for(int i=front;i<=rear;i++){
    printf("%d",queue[i].key);
   } 
   printf("\n\n");
}

void enqueue(element item){
    if(rear>=MAX-1){
        printf("queue is full\n");
        return;
    }
    rear++;
    queue[rear]=item;

    printf("enqueue key=%d\n",item.key);
    printQueue();
}

element dequeue(){
    if(front>rear){
        printf("there is no element to delete\n");
        element dummy;
        dummy.key=-1;
        return dummy;
    }

    element item = queue[front];
    front++;

    printf("after dequeue\n");
    printQueue();
    return item;
}

int main(){
    element input;
    input.key=1;
    enqueue(input);

    input.key=2;
    enqueue(input);

    input.key=3;
    enqueue(input);

    input.key=4;
    enqueue(input);

    element output;
    output=dequeue();
    output=dequeue();
    output=dequeue(); 
    output=dequeue();
    return 0;
    
}