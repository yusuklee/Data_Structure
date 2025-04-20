#include <stdio.h>
#define MAX 100 //선형큐에서는 rear = -1  원형큐에서는 rear =0으로 둠 
typedef struct node
{
    int data;
}node;

node queue[MAX];
int rear = -1; 
int front = 0;

void printQueue(){
    if(front>rear)return;
    printf("Queue:");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i].data);
    }
    printf("\n");
}

void enqueue(node item){ //선형 큐 에서는 rear을 하나 증가시키고 거기다가 박는다
    if(rear==MAX-1)return;
    rear++;
    queue[rear]=item;

    printf("enqueue data=%d\n",queue[rear].data);
    printQueue();
}

node dequeue(){
    if(front>rear){
        printf("there is no node to delete\n");
        node dummy;
        dummy.data=-1;
        return dummy;
    }
    node item = queue[front++];
    printf("after delete\n");
    printQueue();
    return item;
}

int main(){
    node input;
    input.data=1;
    enqueue(input);

    input.data=2;
    enqueue(input);

    input.data=3;
    enqueue(input);

    input.data=4;
    enqueue(input);

    node output;
    output=dequeue();
    output=dequeue();
    output=dequeue(); 
    output=dequeue();
    return 0;
    
}