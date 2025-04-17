#include<stdio.h>
#include<stdlib.h>

typedef struct listNode *listPointer;

typedef struct listNode
{
    int data;
    listPointer link;
}node;

listPointer createNode(int data){
    node *newNode = malloc(sizeof(node));
    newNode->data=data;
    newNode->link=NULL;
    return newNode;
}

listPointer appendNode(listPointer head, int data){ //노드생성후 연결한다음에 head를 리턴하는 함수
    node * newnode = createNode(data); //새로운 노드의 주소를 가리키는 포인터
    if(head==NULL){
        head=newnode; //노드가 아예없엇다면 new node가 head가 됨
        return newnode;
    }
    node * temp = head;
    while(temp->link !=NULL){
        temp = temp ->link;
    } //결과물은 맨마지막을 가리키는 포인터
    temp->link = newnode;
    return head;
}

int find(listPointer head, int data){
    listPointer temp = head;
    int position=0;
    while(temp!=NULL){
        if(temp->data == data){
            return position;
        }
        temp = temp->link;
        position++;
    }
    return -1;
}

listPointer insertNode(listPointer head, int data, int position){ //삽입위치에 잇는애를 앞으로 밀어내는 방식
    listPointer newnode= createNode(data);

    if(position==0){
        newnode->link = head;
        return newnode; //head가 newnode가 됨
    }
    listPointer temp = head;
    for(int i=0;i<position-1 && temp!=NULL;i++){ //계속 이동하다가 null로 갓으면 못찾은거고 현재 1번쨰 포지션에 있으니가 n번에있는 target에 간다고 치면 n-1번 링크를 타야겟지
        temp=temp->link;
    }
    if(temp==NULL){
        printf("The position is larger than the size.\n");
        free(newnode);
        return head;
    }
    newnode->link=temp->link;
    temp->link = newnode;
    return head;
    
}

listPointer deleteNode(listPointer head, int data){
    listPointer temp = head;
    listPointer prev = NULL;

    if(head==NULL){
        printf("the list is empty\n");
        return head;
    }
    if(head->data==data){
        head = head->link;
        free(temp);
        return head;
    }

    while(temp!=NULL&& temp->data !=data){
        prev=temp;
        temp = temp->link;
    } //temp가 삭제할 애를 가리킬때까지 계속이동 

    if(temp==NULL){
        printf("value %d cannot be find\n", data);
        return head;
    }

    prev->link =temp->link; //삭제할애의 링크를 이어받기
    free(temp); //temp가 가리키는 데이터 삭제

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
