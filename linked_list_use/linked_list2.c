#include <stdio.h>
#include <stdlib.h>
typedef struct polyNode {
    int coef;
    int expon;
    struct polyNode *link;
}polyNode;


typedef polyNode* p;

void attach(int coefficient, int exponent, p *rear){ 
    p temp = malloc(sizeof(polyNode));
    temp->coef = coefficient;
    temp->expon = exponent;  // ❗️ 이거 빠졌었음!
    temp->link = NULL;
    (*rear)->link = temp;
    *rear = temp;
}

p padd(p a, p b){
    p c, rear, temp;
    int sum;

    rear = malloc(sizeof(polyNode));
    rear->link = NULL;
    c= rear;

    while (a && b )
    {
        if(a->expon > b->expon){
            attach(a->coef, a->expon, &rear);
            a=a->link;
        } else if(a->expon == b->expon){
            sum = a->coef + b->coef;
            if(sum) attach(sum, a->expon, &rear);
            a = a->link;
            b = b->link;
        } else {
            attach(b->coef, b->expon, &rear);
            b = b->link;
        }
    }
 
    for(;a;a=a->link) attach(a->coef, a->expon, &rear);
    for(;b;b=b->link) attach(b->coef, b->expon, &rear);

    temp = c;
    c = c->link;
    free(temp);
    return c;
}

void printPoly(p poly){
    while (poly)
    {
        printf("%dx^%d",poly->coef,poly->expon);
        if(poly->link)printf("+");
        poly = poly->link;
    }
    printf("\n");
    
}

int main(){
    p a = NULL, b=NULL, rearA, rearB, result;

    a=malloc(sizeof(polyNode));
    a->link =NULL;
    rearA=a;
    attach(3,4,&rearA);
    attach(2,2,&rearA);
    attach(1,0,&rearA);
    a=a->link;

    b=malloc(sizeof(polyNode));
    b->link=NULL;
    rearB=b;
    attach(4,3,&rearB);
    attach(2,2,&rearB);

    attach(5,0,&rearB);
    b=b->link;


    result = padd(a,b);

    printf("A(x): ");
    printPoly(a);
    printf("B(x): ");
    printPoly(b);
    printf("A(x)+B(x): ");
    printPoly(result);
    return 0;
}


