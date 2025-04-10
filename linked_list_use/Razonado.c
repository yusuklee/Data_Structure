#include<stdio.h>
#include<stdlib.h>

//이중 연결 리스트의 노드 구조체
typedef struct node{
    int data;
    struct node* llink;
    struct node* rlink;
}Node;

void dinsert(Node* node, Node* newnode){
    newnode->llink = node;
    newnode->rlink = node->rlink;
    if(node->rlink!=NULL){
        node->rlink->llink = newnode;
    }
    node->rlink = newnode;
}

void ddelete(Node* head, Node* deleted){
    if(head==deleted){
        printf("Deletion of head node not permitted.\n");
        return;
    }
    deleted->llink->rlink=deleted->rlink;
    if(deleted->rlink!=NULL){
        deleted->rlink->llink = deleted->llink;
    }
    free(deleted);
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->rlink;
    }
    printf("\n");
}

void freeList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* next = current->rlink;
        free(current);
        current = next;
    }
}

int main(void){
    Node* head = malloc(sizeof(Node));
    head->data=0;
    head->llink=NULL;
    head->rlink = NULL;

    Node* node1 = malloc(sizeof(Node));
    node1->data=1;
    node1->llink= node1->rlink=NULL;
    dinsert(head,node1);

    Node* node2 = malloc(sizeof(Node));
    node2->data = 2;
    node2->llink=node2->rlink=NULL;
    dinsert(node1,node2);

    Node *node3 = (Node *)malloc(sizeof(Node));
    node3->data = 3;
    node3->llink = node3->rlink = NULL;
    dinsert(node2, node3); 

    printf("List after insertion: ");
    printList(head);

    ddelete(head,node2);

    printf("list after deletion of node with data2: ");
    printList(head);

    freeList(head);
    return 0;

}