#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
    struct node* back;
}node;

typedef node * p;

p create(int data){
    p newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->back = NULL;
    newnode->next = NULL;
    return newnode;
}

p append(p head, int data){
    p newnode = create(data);
    if(head==NULL)return newnode;
    p temp = head;
    while (temp->next!=NULL) temp = temp->next;
    temp->next = newnode;
    newnode->back = temp;
    return head;
}

void printlist(p head){
    p temp = head;
    while (temp!=NULL) {
        printf("%d->",temp->data);
        temp= temp->next;}
        printf("Null\n");
}

void printreverse(p head){
    p temp = head;
    while (temp->next!=NULL)
    {temp=temp->next;}

    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp= temp->back;
    }
    printf("Null\n");
}

void freeall(p head){
    p temp;
    while (head!=NULL)
    {
        temp = head;
        head= head->next;
        free(temp);
    }
}

int main(){
    p head = NULL;

    head = append(head,1);
    head = append(head,2);
    head = append(head,3);
    head = append(head,4);

    printf("Linked list:");
    printlist(head);

    printf("reverse list:");
    printreverse(head);

    freeall(head);
    return 0;
}