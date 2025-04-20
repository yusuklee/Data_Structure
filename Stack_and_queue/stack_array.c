#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define START -1

typedef struct Stack
{
    int capacity;
    int top;
    int * array;
}*stack;

stack create(int size){
    stack s = malloc(sizeof(struct Stack));
    if(!s)exit(1);
    s->array=malloc(sizeof(int)*size);
    s->capacity=size;
    s->top=START;
    return s;
}

bool isEmpty(stack s){
    return s->top==-1;
}

bool isFull(stack s){
    return s->top == s->capacity-1;
}

void push(int data, stack s){
    if(isFull(s))return;
    s->array[++s->top]=data;
}

void pop(stack s){
    if(isEmpty(s))return;
    s->top--;
    
}

int gettop(stack s){
    if(!isEmpty(s)){
        return s->array[s->top];
    }
    printf("empty\n");
    return 0;
}

int main(){
    stack s = create(MAX);

    push(1,s);
    push(2,s);
    push(3,s);
    printf("top: %d\n",gettop(s));
    pop(s);
    printf("top: %d",gettop(s));
    return 0;

}