#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node * link;
}node;

typedef node * p;

p create(int data){
    p newnode = malloc(sizeof(node));
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
}

p append(p head, int data){
    p newnode = create(data);
    if(head==NULL)return newnode; //아무것도 없는데 생성하면 head가 새로생성한 노드겟지

    p temp = head;
    while (temp->link!=NULL)
    {
        temp= temp->link;
    }
    temp->link = newnode;
    return head;
    
}

int find(p head, int data){
    p temp = head;
    int target = 0;
    while (temp!=NULL)
    {
        if(temp->data==data)return target;
        temp= temp->link;
        target++;
    }
    return -1;
}

p insert(p head, int data, int target){
    p newnode = create(data);
    if(target==0){
        newnode->link=head;
        return newnode;
    }
    p temp =head;
    int i=0;
    while (i<target-1 && temp!=NULL)
    {
        temp = temp->link;
        i++;
    }
    if(temp==NULL){
        printf("the target is out of range");
        free(newnode);
        return head;
    }
    newnode -> link = temp ->link;
    temp->link = newnode;
    return head;
    
}

p delete(p head, int data){
    if(head==NULL){
        printf("empty");
        return NULL;
    }
    if(head->data==data){
        p temp= head;
        head= head->link;
        free(temp);
        return head;
    }
    p temp = head;
    p prev = NULL;

    while (temp!=NULL&&temp->data!=data)
    {
        prev = temp;
        temp= temp->link;
    }
    if(temp==NULL){
        printf("value not found");
        return head;
    }
    prev ->link = temp->link;
    free(temp);
    return head;
    
}

void printnode(p head){
    p temp = head;
    while (temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->link;
    }
    printf("Null\n");
    
}

void freenode(p head){
    p temp;
    while(head!=NULL){
        temp=head;
        head=head->link;
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

