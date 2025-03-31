#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int element;
    struct node* next;
}*stack;

void fatalError(const char *msg){
    fprintf(stderr, "%s\n",msg);
    exit(1);
}

stack create(){
    stack s = malloc(sizeof(struct node));
    if(s==NULL){
        fatalError("out of space\n");
    }
    s->next=NULL;
    return s;
}

void freeall(stack s){
    if(s==NULL) fatalError("no stack exist");

    while (s->next!=NULL)
    {
        struct node* temp = s->next;
        s->next = s->next->next;
        free(temp);
    }
}

bool isempty(stack s){
    return s->next==NULL;
}

void push(int x, stack s){
    struct node* temp = malloc(sizeof(struct node));
    if(temp==NULL){
        fatalError("out of space");
    }
    temp->element=x;
    temp->next=s->next;
    s->next=temp;
}

void pop(stack s){
    if(isempty(s))fatalError("empty");

    struct node* firstcell = s->next;
    s->next = s->next->next;
    free(firstcell);
}

int top(stack s){
    if(!isempty(s)) return s->next->element;

    fatalError("empty");
    return 0;
}

int main(){
    stack s = create();

    push(10,s);
    push(20,s);
    push(30,s);
    printf("top:%d\n",top(s));

    pop(s);
    printf("top:%d\n",top(s));

    freeall(s);
    printf("is stack empty%s:",isempty(s)? "Yes":"No");

    return 0;
}