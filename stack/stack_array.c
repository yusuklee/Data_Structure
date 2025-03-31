#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
#define START (-1)

typedef struct stack{
    int capacity;
    int top;
    int* array;
}*p;

p create(int size){
    p s= malloc(sizeof(struct stack));
    if(s==NULL){
        fprintf(stderr, "out of space\n");
        exit(1);
    }
    s->array = malloc(sizeof(s->array[0])*size);
    s->capacity=size;
    s->top=START;
    return s;
}

bool isempty(p s){
    return s->top<0;
}

bool isfull(p s){
    return s->top >=s->capacity-1;
}

void push(int x, p s){
    if(isfull(s)){
        fprintf(stderr, "full stack\n");
        return;
    }
    s->array[++s->top]=x;
}

void pop(p s){
    if(isempty(s)){
        fprintf(stderr, "empty stack\n");
        return;
    }
    s->top--;
}

int gettop(p s){
    if(!isempty(s)){
        return s->array[s->top];
    }
    fprintf(stderr, "Empty stack\n");
    return 0;
}

int main(){
    p s = create(MAX);

    push(1,s);
    push(2,s);
    push(3,s);
    printf("top: %d\n",gettop(s));
    pop(s);
    printf("top: %d",gettop(s));
    return 0;

}