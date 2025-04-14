#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* llink;
    struct node* rlink;
}node;

void insert(node* selectNode, node* newnode){
    newnode->llink=selectNode;
    newnode->rlink=selectNode->rlink;
    if(selectNode->rlink!=NULL){
        selectNode->rlink->llink=newnode;
    }
    selectNode->rlink = newnode;
}

void deleteNode(node* start, node* deleted){
    if(start==deleted){
        printf("you cant delete the start\n");
        return;
    }
    deleted->llink->rlink=deleted->rlink;
    if(deleted->rlink!=NULL){
        deleted->rlink->llink=deleted->llink;
    }
    free(deleted);
}

void printList(node* start){
    node* current=start;
    while(current!=NULL){
        node* next = current->rlink;
        printf("%d",current->data);
        current=next;
    }
}
void freeList(node * start){
    node * current = start;
    while (current!=NULL)
    {
        node* next = current->rlink;
        free(current);
        current=next;
    }
}

int main(){
    node* start = malloc(sizeof(node));
    start->data=0;
    start->llink=NULL;
    start->rlink=NULL;

    node* node1=malloc(sizeof(node));
    node1->data=1;
    node1->llink=node1->rlink=NULL;
    insert(start,node1);

    node* node2=malloc(sizeof(node));
    node2->data=2;
    node2->llink=node2->rlink=NULL;
    insert(node1,node2);

    node* node3=malloc(sizeof(node));
    node3->data=3;
    node3->llink=node3->rlink=NULL;
    insert(node2,node3);

    printf("List after insertion: ");
    printList(start);

    deleteNode(start,node2);

    printf("List after deletion of node with data2: ");
    printList(start);

    freeList(start);
    return 0;

}