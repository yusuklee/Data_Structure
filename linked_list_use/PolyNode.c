#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode *polyPointer;
typedef struct polyNode
{
    int coef;
    int expon;
    polyPointer link;
} polyNode;

polyPointer createTerm(int coef, int expon){
    polyPointer newTerm = (polyPointer)malloc(sizeof(polyNode));
    newTerm->coef = coef;
    newTerm->expon = expon;
    newTerm->link = NULL;
    return newTerm;
}

void attach(polyPointer ptr, int coef, int expon){
    polyPointer temp=createTerm(coef,expon);
    while (ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=temp;
    
}

polyPointer addPolynomials(polyPointer a, polyPointer b){
    polyPointer result, rear, temp;
    result = (polyPointer)malloc(sizeof(polyNode));
    result->link = NULL;
    rear = result;
    int sum;

    while(a&&b){
        if(a->expon > b->expon){ 
             attach(rear, a->coef, a->expon);
             rear=rear->link;
            a=a->link;
        }else if(a->expon == b->expon){
            sum = a->coef +b->coef;
            if(sum)attach(rear,sum,a->expon);
            a=a->link;
            b=b->link;
            rear=rear->link;
        }else{
            attach(rear,b->coef,b->expon);
            b=b->link;
            rear=rear->link;
        }
    }

    while (a)
    {
        attach(rear, a->coef, a->expon);
        rear=rear->link;
        a=a->link;
    }
    while (b)
    {
        attach(rear, b->coef,b->expon);
        rear=rear->link;
        b=b->link;
    }

    temp = result;
    result = result->link;
    free(temp);

    return result;
}


void pirintPolynomial(polyPointer poly){
    while(poly){
        printf("%dx^%d", poly->coef, poly->expon);
        if(poly->link != NULL){
            printf("+ ");
        }
        poly = poly->link;
    }
    printf("\n");
}

void freePolynomial(polyPointer poly){
    polyPointer temp;
    while(poly){
        temp = poly;
        poly = poly->link;
        free(temp);
    }
}

int main(){
    polyPointer a, b, result;

    a = createTerm(3, 4);
    attach(a, 5, 3);
    attach(a, 2, 2);

    printf("first polynomial: ");
    pirintPolynomial(a);

    b = createTerm(4, 3);
    attach(b, 2, 2);
    attach(b, 1, 1);

    printf("second polynomial: ");
    pirintPolynomial(b);

    result = addPolynomials(a, b);
    printf("\n sum: ");
    pirintPolynomial(result);

    freePolynomial(a);
    freePolynomial(b);
    freePolynomial(result);

    return 0;
}