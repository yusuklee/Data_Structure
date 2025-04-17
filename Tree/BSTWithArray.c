#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int bst[MAX_SIZE];
int size = 0;

void initBST() {
    for (int i = 0; i < MAX_SIZE; i++) {
        bst[i] = -1;
    }
    size = 0;
}

// 노드 삽입 (index 1부터 시작)
void insert(int data) {
    if (size >= MAX_SIZE - 1) {
        printf("트리가 가득 찼습니다. 삽입 불가\n");
        return;
    }

    int index = 1;
    while (index < MAX_SIZE) {
        if (bst[index] == -1) {
            bst[index] = data;
            size++;
            return;
        } else if (data < bst[index]) {
            index = 2 * index; // 왼쪽 자식
        } else if (data > bst[index]) {
            index = 2 * index + 1; // 오른쪽 자식
        } else {
            // 중복 데이터는 무시
            return;
        }
    }

    printf("삽입 실패: 인덱스 범위를 초과했습니다.\n");
}

// 탐색 함수
int search(int data) {
    int index = 1;
    while (index < MAX_SIZE && bst[index] != -1) {
        if (bst[index] == data) {
            return index;
        } else if (data < bst[index]) {
            index = 2 * index;
        } else {
            index = 2 * index + 1;
        }
    }
    return -1;
}

// 중위 순회 함수
void inorderTraversal(int index) {
    if (index >= MAX_SIZE || bst[index] == -1) return;
    inorderTraversal(2 * index);       
    printf("%d ", bst[index]);         
    inorderTraversal(2 * index + 1);
}

int main() {
    initBST();

    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);

    printf("중위 순회 (정렬된 값): ");
    inorderTraversal(1);
    printf("\n");

    int val = 40;
    int result = search(val);
    if (result != -1) {
        printf("값 %d 은(는) 인덱스 %d 에 있습니다.\n", val, result);
    } else {
        printf("값 %d 을(를) 찾을 수 없습니다.\n", val);
    }

    printf("현재 노드 수: %d / %d\n", size, MAX_SIZE - 1);

    return 0;
}