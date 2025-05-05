#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_QUEUE_SIZE 100
//너비 우선 탐색 구현
typedef struct 
{
    int num;
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
        printf("%d ", queue[i].num);
    }
    printf("\n\n");
}

void enqueue(element item){
    if((rear+1) == MAX_QUEUE_SIZE){
        printf("Queue is full!\n");
        return ;
    }

    queue[++rear] = item;

    //printQueue();
}

element dequeue(){
    if (front > rear){
        printf("Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    //printf("De");
    //printQueue();
    return queue[front++];
}

struct Node
{
    int vertex;
    struct Node* next;
};
struct Node* graph[MAX_VERTICES];

void addEdge(int src, int dest){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> vertex = dest;
    newNode -> next = graph[src];
    graph[src] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> vertex = src;
    newNode -> next = graph[dest];
    graph[dest] = newNode;
}

void BFS(int startVertex){
    bool visited[MAX_VERTICES] = {false};

    // 구현하세요
    element e;
    e.num = startVertex;
    visited[startVertex] = true;
    enqueue(e);

    printf("BFS Traversal starting from vertex: ");

    while (front <= rear) {
        element curr = dequeue();
        int v = curr.num;
        printf("%d ", v);

        struct Node* temp = graph[v]; //초기에는 0이랑만 연결된 애들 주루룩 나옴
        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                element next;//큐에 넣은다음 큐에서 뺴면서 뺸애랑만 인접애들을 전부 큐에 넣는구조.
                next.num = adjVertex;
                enqueue(next);
                visited[adjVertex] = true;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    // 구현하세요
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph[i] = NULL;
    }

    addEdge(0, 1);  
    addEdge(0, 2);
    addEdge(0, 3);  

    addEdge(3, 5);  
    addEdge(2, 4);  
    addEdge(1, 8);  
    addEdge(5, 7);  
    addEdge(4, 6);

    BFS(0);


    return 0;
}