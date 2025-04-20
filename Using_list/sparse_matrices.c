#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef enum {head ,entry} tagfield;

typedef struct entryNode
{
    int row,col,value;
}entryNode;

typedef struct node
{
    struct node* down;
    struct node* right;
    tagfield tag;
    union 
    {
        struct node* next;
        entryNode entry;
    }u;
    
}node;

node* hdnode[MAX_SIZE];

node* newNode(){
    node* temp = malloc(sizeof(node));
    if(!temp)exit(1);
    return temp;
}

node * mread(){
    int numRows, numCols, numTerms;
    int numHeads, currentRow=0;
    int row, col, value;
    node * root;
    node* temp;
    node* last;

    printf("Enter the number of rows, columns, and number of nonzero terms:\n");
    scanf("%d %d %d", &numRows,&numCols,&numTerms);

    numHeads = (numRows>numCols)?numRows:numCols;
    root = newNode();
    root->tag = entry;
    root ->u.entry.row=numRows;
    root ->u.entry.col=numCols;

    if(numHeads==0){
        root->right=root;
        return root;
    }

    for(int i=0;i<numHeads;i++){
        temp = newNode();
        temp->tag=head;
        temp->right=temp;
        temp->u.next=temp; //next는 헤더 연결용
        hdnode[i]=temp;
    }

    last = hdnode[0];
    printf("Enter the row, column and value for each term:\n");
    for(int i=0;i<numTerms;i++){
        scanf("%d %d %d", &row, &col, &value);

        if(row > currentRow){
            last->right = hdnode[currentRow];
            currentRow = row;
            last = hdnode[row];
        }
        temp = newNode();
        temp->tag = entry;
        temp->u.entry.row = row;
        temp->u.entry.col = col;
        temp->u.entry.value = value;
        //행 연결
        last->right = temp;
        last = temp;
        //열연결
        hdnode[col]->u.next->down=temp;
        hdnode[col]->u.next=temp;
    }
    // 마지막 행 마감
    last->right = hdnode[currentRow];
    // 열 연결 마감
    for(int i=0;i<numCols;i++){
        hdnode[i]->u.next->down = hdnode[i];
    }

    // header node들 서로 연결
    for(int i=0;i<numHeads-1;i++){
        hdnode[i]->u.next=hdnode[i+1];
    }

    hdnode[numHeads-1]->u.next=root;
    root->right=hdnode[0];
    return root;

}

//행우선 출력
void write(node* root){
    int numRows = root->u.entry.row;
    int numCols = root->u.entry.col;
    node* temp;
    node* head = root->right;

    printf("\nnumRows = %d, numCols = %d\n", numRows, numCols);
    printf("The matrix by row, column, and value:\n");

    for(int i=0;i<numRows;i++){
        for(temp=head->right;temp!=head;temp=temp->right){
            printf("%5d %5d %5d\n",temp->u.entry.row,temp->u.entry.col, temp->u.entry.value);
        }
        head=head->u.next;
    }
}

void erase(node* root){
    node* x;
    node * y;
    node* head = root->right;

    for(int i=0;i<root->u.entry.row;i++){
        y=head->right;
        while (y!=head)
        {
            x=y;
            y=y->right;
            free(x);
        }
        x=head;
        head=head->u.next;
        free(x);
        
    }

    y=head; // 다지웟으면 이게 루트겟지만 다 못지웟으면 남은 헤드임
    while (y!=root)
    {
        x=y;
        y=y->u.next;
        free(x);

    }
    free(root);
    
}
// 메인 함수
int main() {
    node* matrix = mread();
    write(matrix);
    erase(matrix);
    matrix=NULL;
    return 0;
}

