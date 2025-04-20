#include <stdio.h>
#include <stdlib.h>
//링크 스택이랑 비슷한 느낌
typedef struct node
{
    int coef;
    int exp;
    struct node* link;
}node;

node* attach(int coef, int exp, node* head){
    node* temp = malloc(sizeof(node));
    temp->coef = coef;
    temp->exp = exp;
    temp->link = NULL;
    head->link = temp;
    return temp;
}

node * padd(node* a, node* b){
    node* c;
    node * last;
    node * temp;
    int sum;

    last = malloc(sizeof(node)); //아무것도 없는 헤더 노드 만들고 이제 추가할떄마다 뒤에 추가됨
    last->link = NULL;
    c=last;

    while (a&&b)
    {
        if(a->exp > b->exp){
            last= attach(a->coef,a->exp, last);
            a=a->link;
        }else if(a->exp==b->exp){
            sum=a->coef+b->coef;
            if(sum)last=attach(sum,a->exp,last);
            a=a->link;
            b=b->link;
        }else{
            last = attach(b->coef,b->exp,last);
            b=b->link;
        }
    }

    while (a)
    {
        last = attach(a->coef,a->exp, last);
        a= a->link;
    }

    while (b)
    {
        last = attach(b->coef,b->exp, last);
        b= b->link;
    }
    temp = c;
    c = c->link;
    free(temp);
    return c; // 시작의 노드 (아무것도없는 헤드는 사라짐)
    
    
}

void printnodeList(node* nodeList){
    while (nodeList) 
    {
        printf("%dx^%d",nodeList->coef, nodeList->exp);
        if(nodeList->link)printf("+");
        nodeList=nodeList->link;
    }
    printf("\n");
}

int main(){
    node* a=NULL;
    node* b=NULL;
    node* lastA; node* lastB;
    node* result;
    node* temp;

    a=malloc(sizeof(node));
    a->link=NULL;
    lastA=a;
    lastA=attach(3,4,lastA);
    lastA=attach(2,2,lastA);
    lastA=attach(1,0,lastA);
    temp=a;
    a=a->link;
    free(temp);


    b=malloc(sizeof(node));
    b->link=NULL;
    lastB=b;
    lastB=attach(3,4,lastB);
    lastB=attach(2,2,lastB);
    lastB=attach(1,0,lastB);
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


