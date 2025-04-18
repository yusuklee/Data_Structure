#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node* link;
}*stack;

stack createStack(){
    stack s=malloc(sizeof(struct node));
    s->link=NULL;
    return s;
}

void push(stack s, int data){
    struct node* newNode= malloc(sizeof(struct node));
    if(!newNode)printf("새노드 안만들어짐.");
    newNode->link=s->link;
    s->link=newNode;
    newNode->data=data;
}

bool isEmpty(stack s){
    return s->link==NULL;
}

int pop(stack s){
    if(isEmpty(s)){
        printf("stack is empty\n");
        return NULL;
    }
    struct node* temp = s->link;
    s->link=temp->link;
    int data=temp->data;
    free(temp);
    return data;
}

int getTop(stack s){
    if(isEmpty(s))return NULL;

    return s->link->data;
}

void freeall(stack s){
    if(isEmpty(s))return;
    while (s->link!=NULL)
    {   struct node* temp = s->link;
        s->link=temp->link;
        free(temp);
    }
    
}

int main(){
    stack s = createStack();
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    printf("pop value:%d\n",pop(s));
    printf("stack top:%d\n", getTop(s));
    freeall(s);
    printf("is stack empty? : %s",isEmpty(s)? "yes": "no");
    return 0;
}