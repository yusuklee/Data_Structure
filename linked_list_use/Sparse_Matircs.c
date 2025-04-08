#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef enum { head, entry } tagfield;

typedef struct entryNode { 
    int row;
    int col;
    int value;
} entryNode;

typedef struct matrixNode *matrixPointer;

typedef struct matrixNode { //matrix node 는 entrynode나 헤더노드가될수잇음
    matrixPointer down;
    matrixPointer right;
    tagfield tag; //matrixnode가 entry가되면
    union {
        matrixPointer next;  // header 노드들 연결용
        entryNode entry;     // 실제 값 노드
    } u;
} matrixNode;

matrixPointer hdnode[MAX_SIZE];

// 노드 생성
matrixPointer newNode() {
    matrixPointer temp = (matrixPointer)malloc(sizeof(matrixNode));
    if (!temp) {
        printf("메모리 할당 실패\n");
        exit(1);
    }
    return temp;
}

// 행렬 입력
matrixPointer mread() {
    int numRows, numCols, numTerms;
    int numHeads, currentRow = 0;
    int row, col, value;
    matrixPointer node, temp, last;

    printf("Enter the number of rows, columns, and number of nonzero terms:\n");
    scanf("%d %d %d", &numRows, &numCols, &numTerms);

    numHeads = (numRows > numCols) ? numRows : numCols;

    node = newNode();
    node->tag = entry;
    node->u.entry.row = numRows; //루트 노드 만든것 실제 entry node가 아닙니다.
    node->u.entry.col = numCols;

    if (numHeads == 0) {
        node->right = node;
        return node;
    }

    // 헤더 노드 생성
    for (int i = 0; i < numHeads; i++) {
        temp = newNode();
        temp->tag = head;
        temp->right = temp;
        temp->u.next = temp; //실제로 헤더 노드로 전직하고 next는 자신을 가리킴
        hdnode[i] = temp;
    }

    last = hdnode[0];  // 첫 번째 행의 헤더노드
    printf("Enter row, column and value for each term:\n");
    for (int i = 0; i < numTerms; i++) {
        scanf("%d %d %d", &row, &col, &value);

        // 행 바뀜 → 이전 행 마감
        if (row > currentRow) {
            last->right = hdnode[currentRow];  // 그 행의 끝을 닫음
            currentRow = row;
            last = hdnode[row];
        }

        temp = newNode();
        temp->tag = entry;
        temp->u.entry.row = row;
        temp->u.entry.col = col;
        temp->u.entry.value = value;

        // 행 리스트 연결
        last->right = temp;
        last = temp;

        // 열 리스트 연결
        hdnode[col]->u.next->down = temp;
        hdnode[col]->u.next = temp;
    }

    // 마지막 행 마감
    last->right = hdnode[currentRow];

    // 열 연결 마감
    for (int i = 0; i < numCols; i++) {
        hdnode[i]->u.next->down = hdnode[i];
    }

    // header node들 서로 연결
    for (int i = 0; i < numHeads - 1; i++) {
        hdnode[i]->u.next = hdnode[i + 1];
    }

    hdnode[numHeads - 1]->u.next = node;
    node->right = hdnode[0];

    return node;
}

// 행 우선 출력
void mwrite(matrixPointer node) {
    int numRows = node->u.entry.row;
    int numCols = node->u.entry.col;
    matrixPointer temp;
    matrixPointer head = node->right;

    printf("\nnumRows = %d, numCols = %d\n", numRows, numCols);
    printf("The matrix by row, column, and value:\n");

    for (int i = 0; i < numRows; i++) {
        for (temp = head->right; temp != head; temp = temp->right) {
            printf("%5d %5d %5d\n", temp->u.entry.row, temp->u.entry.col, temp->u.entry.value);
        }
        head = head->u.next;
    }
}

// 행렬 삭제
void merase(matrixPointer node) {
    matrixPointer x, y;
    matrixPointer head = node->right;

    for (int i = 0; i < node->u.entry.row; i++) {
        y = head->right;
        while (y != head) {
            x = y;
            y = y->right;
            free(x);
        }
        x = head;
        head = head->u.next;
        free(x);
    }

    y = head;
    while (y != node) {
        x = y;
        y = y->u.next;
        free(x);
    }

    free(node);
}

// 메인 함수
int main() {
    matrixPointer matrix = mread();
    mwrite(matrix);
    merase(matrix);
    matrix=NULL;
    return 0;
}
