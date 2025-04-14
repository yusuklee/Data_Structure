#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int coef;
    int exp;
    struct node* link;
}node;

typedef node* nodepointer;

nodepointer attach(int coef2, int exp2, nodepointer rear){
    nodepointer temp = malloc(sizeof(node));
    temp->coef =coef2;
    temp->exp = exp2;
    temp->link = NULL;
    rear->link = temp; //rear의 link가 새로운 노드를 가리킴.
    return temp; //맨뒤 노드를 가리키는 temp를 return
}

nodepointer padd(nodepointer a, nodepointer b){
    nodepointer c, rear, temp;
    int sum;

    rear = malloc(sizeof(node));
    rear->link = NULL;
    c= rear;

    while (a && b)
    {
        if(a->exp > b->exp){ //a의 지수가 더클때
            rear = attach(a->coef, a->exp, rear);
            a=a->link;
        }else if(a->exp == b->exp){
            sum = a->coef +b->coef;
            if(sum)rear=attach(sum,a->exp,rear);
            a=a->link;
            b=b->link;
        }else{
            rear=attach(b->coef,b->exp,rear);
            b=b->link;
        }
    }
    while (a)
    {
        rear = attach(a->coef, a->exp, rear);
        a=a->link;
    }
    while (b)
    {
        rear= attach(b->coef, b->exp,rear);
        b=b->link;
    }
    temp=c;
    c=c->link;
    free(temp);
    return c; //더미 노드를 제거하고 c는 맨앞을 가리킴
    
    
    
}

void printnodeList(nodepointer nodeList){
    while (nodeList) 
    {
        printf("%dx^%d",nodeList->coef, nodeList->exp);
        if(nodeList->link)printf("+");
        nodeList=nodeList->link;
    }
    printf("\n");
}

int main(){
    nodepointer a =NULL, b=NULL, rearA, rearB, result,temp;

    a=malloc(sizeof(node));
    a->link=NULL;
    rearA=a;
    rearA=attach(3,4,rearA);
    rearA=attach(2,2,rearA);
    rearA=attach(1,0,rearA);
    temp=a;
    a=a->link;
    free(temp);


    b=malloc(sizeof(node));
    b->link=NULL;
    rearB=b;
    rearB=attach(3,4,rearB);
    rearB=attach(2,2,rearB);
    rearB=attach(1,0,rearB);
    temp=b;
    b=b->link;
    free(temp);

    result = padd(a,b); //다더하고 만들어진 연결리스트 맨앞노드를 가리키는 포인터 result

    printf("A(x): ");
    printnodeList(a);
    printf("B(x): ");
    printnodeList(b);
    printf("A(x)+ B(x): ");
    printnodeList(result);


    return 0;

}


