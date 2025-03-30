#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

typedef node* p;

p create(int data){
    p newnode = malloc(sizeof(node));
    newnode -> data = data;
    newnode ->next = NULL;
    return newnode;
}

p append(p head, int data){
    p newnode = create(data);
    if(head==NULL)return newnode;
    p temp = head;
    while ((temp->next !=NULL))
    {
        temp = temp -> next;
    }
    temp->next = newnode;
    return head;
}

int find(p head, int data){
    p temp = head;
    int position = 1;
    while (temp!=NULL)
    {   if(temp -> data ==data) return position;
        temp = temp -> next;
        position++;
    }
    if(temp==NULL) return -1;
}

p insert(p head, int data, int position){
    p newnode = create(data);
    if(position == 0){
        newnode->next=head;
        return newnode;
    }
    p temp = head;
    int count = 1;
    while (temp!=NULL && count<position)
    {
        temp = temp->next;
        count++;
    }
    newnode->next= temp->next;
    temp->next = newnode;
    return head;
}

p delete(p head, int data){
    if(head==NULL)return NULL;
    p temp = head;
    p prev = NULL;
    if(head->data==data){
        head = head->next;
        free(temp);
        return head;
    }
    while (temp!=NULL && temp->data!=data)
    {   prev= temp;
        temp = temp->next;
    }
    if(temp==NULL) return head;
    prev->next = temp->next;
    free(temp);
    return head;
}

void printnode(p head){
    p temp = head;
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("Null\n");
    
}

void freenode(p head){
    p temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
}

int main(){
    p head = NULL;

    head=append(head,1);
    head=append(head,2);
    head=append(head,3);
    head=append(head,5);

    printf("Linked List: ");
    printnode(head);

    int searchData = 3;
    int position = find(head, searchData);
    if (position != -1) {
        printf("Value %d found at position %d.\n", searchData, position);
    } else {
        printf("Value %d not found.\n", searchData);
    }

    head = insert(head, 5, 2);
    printf("Linked List after inserting 5 at position 2: ");
    printnode(head);

    head = delete(head, 2);
    printf("Linked List after deleting node with value 2: ");
    printnode(head);

    head = delete(head, 4);
    printf("Linked List after deleting node with value 4: ");
    printnode(head);

    head = delete(head, 1);
    printf("Linked List after deleting node with value 1: ");
    printnode(head);

    freenode(head);
    return 0;

}