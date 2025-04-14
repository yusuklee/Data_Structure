#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;

typedef struct listNode
{
    int data;
    listPointer next;
    listPointer prev;
} node;

listPointer createNode(int data){
    listPointer newnode = malloc(sizeof(node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next= NULL;
    return newnode; //새로운 노드 생성하고 양방향은 null을가리킴 
}

listPointer appendNode(listPointer head, int data){
    listPointer newnode = createNode(data);
    if(head==NULL){
        return newnode;
    }
    listPointer temp = head;
    while(temp->next!=NULL){ //temp가 마지막노드일때 멈춤
        temp = temp->next;
    } 
    temp->next = newnode; //마지막노드와 생성된노드연결
    newnode->prev= temp;
    return head;
}

void printList(listPointer head){
    listPointer temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void printReverseList(listPointer head){
    if(head == NULL){
        printf("NULL\n");
        return;
    }
    listPointer temp = head;

    while(temp->next !=NULL){
        temp = temp->next; //맨마지막노드로 이동
    }
    while(temp!=NULL){
        printf("%d ->",temp->data); //그후 next가아닌 prev로 뒤로이동하면서 반대순서로 출력하기
        temp=temp->prev;
    }
    printf("NULL\n");
}

void freeList(listPointer head){
    listPointer temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
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

    printf("Reverse List: ");
    printReverseList(head);

    freeList(head);

    return 0;
}
