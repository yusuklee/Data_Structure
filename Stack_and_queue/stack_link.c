#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node* link;
}*stack;

stack createStack(){
    stack s = malloc(sizeof(struct node));
    s->link = NULL;
    return s;
}

void push(stack s, int data){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->link = s->link;
    s->link = newNode;
    newNode->data= data;
}
bool isEmpty(stack s){
    return s->link==NULL;
}

int pop(stack s){
    if(isEmpty(s))return NULL;
    struct node* firstCell = s->link;
    s->link = firstCell->link;
    int data = firstCell->data;
    free(firstCell);
    return data;
}

int getTop(stack s){
    if(isEmpty(s))return NULL;
    int data = s->link->data;
    return data;
}

void freeAll(stack s){
    if(isEmpty(s))return;
    while (s->link!=NULL)
    {
        struct node* temp=s->link;
        s->link = s->link->link;
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
    freeAll(s);
    printf("is stack empty? : %s",isEmpty(s)? "yes": "no");
    return 0;
}