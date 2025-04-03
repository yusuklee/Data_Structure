#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c){
    stack[++top]=c;
}
char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int isEmpty(){
    return top==-1;
}

int priority(char op){
    if(op=='(') return 0;
    if(op=='+'||op=='-') return 1;
    if(op == '*'|| op=='/')return 2;
    return -1;
}

void infix_to_postfix(char* infix, char* postfix){
    int i=0, j=0;
    char token;

    while ((token=infix[i++])!='\0')
    {
        if(isdigit(token)||isalpha(token)){
            postfix[j++]=token;
        }else if(token=='(') push(token);
        else if(token==')'){
            while (peek()!='(')
            {
                postfix[j++]=pop();
            }if(peek()=='(')
            {pop();}
        }else{
            while (!isEmpty()&&priority(peek())>priority(token))
            {
                postfix[j++]=pop();
            }push(token);
            
        }
    }
    while (!isEmpty())
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    
}

int main(){
    char infix[MAX], postfix[MAX];

    printf("enter the middle fix: ");
    scanf("%s",infix);

    infix_to_postfix(infix,postfix);

    printf("postfix:%s\n",postfix);

    return 0;
}