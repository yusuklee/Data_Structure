#include <stdio.h>
#include <stdlib.h>


// TreeNode 구조체 정의
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// 노드 생성 함수
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("메모리 할당 오류\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 삽입 함수 (이진 탐색 트리 기준)
TreeNode* insert(TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// 탐색 함수
TreeNode* search(TreeNode* root, int target) {
    if (root == NULL || root->data == target) {
        return root;
    }
    if (target < root->data) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

// 중위 순회 (Inorder)
void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// 전위 순회 (Preorder)
void preorderTraversal(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// 후위 순회 (Postorder)
void postorderTraversal(TreeNode* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// 메모리 해제 함수
void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}


int main() {
    TreeNode* root = NULL;

    // 노드 삽입
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("중위 순회: ");
    inorderTraversal(root);
    printf("\n");

    printf("전위 순회: ");
    preorderTraversal(root);
    printf("\n");

    printf("후위 순회: ");
    postorderTraversal(root);
    printf("\n");

    // 탐색 테스트
    TreeNode* found = search(root, 40);
    if (found != NULL) {
        printf("찾은 값: %d\n", found->data);
    } else {
        printf("값을 찾을 수 없습니다.\n");
    }

    // 메모리 해제
    freeTree(root);

    return 0;
}