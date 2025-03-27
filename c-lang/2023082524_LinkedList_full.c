#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;

typedef struct listNode
{
    int data;
    listPointer link;
} node;

listPointer createNode(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

listPointer appendNode(listPointer head, int data){
    node* newnode = createNode(data);
    if (head == NULL) {
        head = newnode;
        return newnode;
    }

    node* temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newnode;
    return head;
}

int find(listPointer head, int data){
    listPointer temp = head;
    int position = 0;
    while(temp != NULL){
        if(temp->data == data){
            return position;
        }
        temp = temp->link;
        position++;
    }
    return -1;
}

listPointer insertNode(listPointer head, int data, int position){
    listPointer newNode = createNode(data);

    if (position == 0) {
        newNode->link = head;
        return newNode;
    }
    listPointer temp = head;
    int i = 0;
    while (i < position - 1 && temp != NULL) {
        temp = temp->link;
        i++;
    }

    if (temp == NULL) {
        printf("The position is larger than the size.\n");
        free(newNode);
        return head;
    }

    newNode->link = temp->link;
    temp->link = newNode;

    return head;
}

listPointer deleteNode(listPointer head, int data){
    listPointer temp = head;
    listPointer prev = NULL;

    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }
    if (head->data == data) {
        temp = head;
        head = head->link;
        free(temp);
        return head;
    }

    
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->link;
    }

    if (temp == NULL) {
        printf("value %d cannot find.\n", data);
        return head;
    }

    prev->link = temp->link;
    free(temp);

    return head;
}

void printList(listPointer head){
    listPointer temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void freeList(listPointer head){
    listPointer temp;

    while (head != NULL) {
        temp = head;
        head = head->link;
        free(temp);
    }
}



int main(){
    listPointer head = NULL;

    head = appendNode(head, 1);
    head = appendNode(head, 2);
    head = appendNode(head, 3);
    head = appendNode(head, 4);

    printf("Linked List: ");
    printList(head);

    int searchData = 3;
    int position = find(head, searchData);
    if(position != -1){
        printf("Value %d found at position %d.\n", searchData, position);
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