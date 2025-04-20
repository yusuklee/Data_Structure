#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}node;

node* createNode(int data){
    node* newNode = malloc(sizeof(node));
    if(!newNode){
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;

}

node* appendNode(node* head, int data){
    node* newNode = createNode(data);
    if(!head){
        return newNode;
    }
    node* temp = head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    return head;
    
}

void printList(node * head){
    node* temp= head;
    while (temp!=NULL)
    {
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
    
}

void printReverseList(node* head){
    if(!head){
        printf("the list is empty\n");
        return;
    }
    node* temp =head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    while (temp!=NULL)
    {
        printf("%d-> ",temp->data);
        temp=temp->prev;
    }
    printf("NULL\n");
}
void freeList(node* head){
    node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
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

    printf("Reverse List: ");
    printReverseList(head);

    freeList(head);

    return 0;
}
