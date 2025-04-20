#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* link;
}node;


node* createNode(int data){
    node* newNode = malloc(sizeof(node));
    newNode->data=data;
    newNode->link=NULL;
    return newNode;
}

node* appendNode(node* head, int data){
    node* newNode= createNode(data);
    if(!head){
        head=newNode;
        return newNode;
    }
    node* temp = head;
    while (temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=newNode;
    return head;
    
}

int find(node* head, int data){
    node* temp = head;
    int position = 0;
    while (temp!=NULL)
    {
        if(temp->data==data)return position;
        temp=temp->link;
        position++;
    }
    return -1;
}

node * insertNode(node * head, int data, int position){
    node * newNode = createNode(data);

    if(position==0){
        newNode->link=head;
        return newNode;
    }
    node* temp=head;
    for(int i=0;i<position-1&&temp!=NULL;i++){ //position-1번 링크를 타면 temp는 position-1 인덱스를 가리킴
        temp=temp->link; //position 이전의 인덱스로 temp를 보내려하는것
    }
    if(!temp){
        printf("The position is larger than the size\n");
        free(newNode);
        return head;
    }
    newNode->link=temp->link;
    temp->link= newNode;
    return head;
}

node* deleteNode(node * head, int data){
    node* temp = head;
    node* prev = NULL;

    if(!head){
        printf("list is empty\n");
        return head;
    }
    if(head->data==data){
        head=head->link;
        free(temp);
        return head;
    }

    while (temp!=NULL&& temp->data!=data)
    {
        prev=temp;
        temp=temp->link;
    }
    if(!temp)return head;

    prev->link=temp->link;
    free(temp);
    return head;
}
void printList(node* head){
    node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void freeList(node* head){
    node* temp;

    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
}

int main(){
    node* head = NULL;

    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = appendNode(head, 4);

    printf("Linked List: ");
    printList(head);

    int searchData = 3;
    int position = find(head, searchData);
    if(position != -1){
        printf("Value %d found at index %d.\n", searchData, position);
    }else{
        printf("Value %d not found.\n", searchData);
    }

    head = insertNode(head, 5, 2);
    printf("Linked List after inserting 5 after value 2: ");
    printList(head);

    head = deleteNode(head, 2);
    printf("Linked List after deleting node with value 2: ");
    printList(head);

    head = deleteNode(head, 4);
    printf("Linked List after deleting node with valye 4: ");
    printList(head);

    head = deleteNode(head, 1);
    printf("Linked List after deleting node with value 1: ");
    printList(head);

    freeList(head);

    return 0;
}
