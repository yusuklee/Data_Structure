#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50 /* 최대 행렬 크기 */

typedef enum {head, entry} tagfield;

typedef struct entryNode{
	int row;
    int col;
    int value;
} EntryNode;

typedef struct matrixNode *matrixPointer;

typedef struct matrixNode{
    matrixPointer down;
    matrixPointer right;
    tagfield tag; 
    union {
        matrixPointer next;  
        EntryNode entry;     
    } u;
} MatrixNode;

matrixPointer hdnode[MAX_SIZE];

matrixPointer getNode(){
	matrixPointer temp;
	temp = (matrixPointer)malloc(sizeof(MatrixNode));
	if(!temp){
		fprintf(stderr, "메모리 할당 오류\n");
		exit(EXIT_FAILURE);
	}
	return temp;
}

/* 희소 행렬에 항목을 추가하는 함수 */
void create(int row, int col, int value){
	matrixPointer newNode, temp, last;
    newNode=getNode(); //엔트리 노드 생성
    newNode->u.entry.value=value;
    newNode->tag=entry;
    newNode->u.entry.row = row;
    newNode->u.entry.col = col;
    newNode->right = NULL;
    newNode->down = NULL;

	if(!hdnode[row]){
        hdnode[row]=getNode(); //헤더노드가 없으면 생성
        hdnode[row]->right=newNode;
        hdnode[row]->tag=head;
        hdnode[row]->u.next=hdnode[row];
    }
    if(col==row){
        hdnode[row]->down=newNode;
    }else{
        if(!hdnode[col]){
            hdnode[col]=getNode(); 
            hdnode[col]->down=newNode;
            hdnode[col]->tag=head;
            hdnode[col]->u.next=hdnode[col];
            
        }
    }

    if(newNode->right!=NULL){
    temp = hdnode[row];
    while (temp->right && temp->right->u.entry.col < col) {
        temp = temp->right;
    }
    newNode->right=temp->right;
    temp->right = newNode;
}
    if(newNode->down!=NULL){
	last=hdnode[col];
    while (last->down && last->down->u.entry.row < row) {
        last = last->down;
    }
    newNode->down = last->down;
    last->down = newNode;
}
	
}

void display(int maxRow, int maxCol){
	int i, j;
	matrixPointer temp;

	for(i = 0; i < maxRow; i++){
		temp = hdnode[i]->right;
		for(j = 0; j < maxCol; j++){
			if(temp && temp->u.entry.col == j){
				printf("%d ", temp->u.entry.value);
				temp = temp->right;
			}else{
				printf("0 ");
			}
		}
		printf("\n");
	}
}

int main(){
	int maxRow, maxCol;
	int row, col, value;

	printf("Enter the Sparse Matrices max row and col: ");
	scanf("%d %d", &maxRow, &maxCol);
	
	printf("Enter (row, col, value): \n");
	while(1){
		printf("row: ");
		scanf("%d", &row);
		if(row == -1){
			break;
		}
		printf("col: ");
		scanf("%d", &col);
		printf("value: ");
		scanf("%d", &value);

		if(row >= maxRow || col >= maxCol){
			printf("out of range.\n");
			continue;
		}
		create(row, col, value);
	}
/* 헤더 끼리 연결하는 부분 구현하였는데 필요없는것 같아서 주석으로 뺴놨습니다.
int maxHead;
if(maxCol>maxRow){maxHead=maxCol;}else{maxHead=maxRow;};
matrixPointer firstHead;
for(int k=0;k<maxHead;k++){
	if(hdnode[k]){
		firstHead=hdnode[k];
		break;
	}
}
for(int i=0;i<maxHead;i++){
	if(hdnode[i]){
		for(int j=i+1;j<maxHead;j++){
			if(hdnode[j]){
				hdnode[i]->u.next=hdnode[j];
				hdnode[j]->u.next=firstHead;
				break;
			}
		}
	}
}*/
	printf("\nSparse Matrices\n");
	display(maxRow, maxCol);

	return 0;
}
