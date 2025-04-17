#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    int isThreaded;  // 1이면 right가 중위 후속 노드를 가리키는 스레드 포인터로 작동
} TreeNode;

// 노드 생성
TreeNode* createNode(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->isThreaded = 1;  // 기본적으로 스레드 사용으로 초기화
    return node;
}

// 노드 삽입
TreeNode* insert(TreeNode* root, int data) {
    TreeNode* ptr = root;
    TreeNode* parent = NULL;

    while (ptr != NULL) {
        if (data == ptr->data) return root; 
        parent = ptr;
        if (data < ptr->data) {
            ptr = ptr->left;
        } else {
            if (ptr->isThreaded)
                ptr = NULL; 
            else
                ptr = ptr->right;
        }
    }

    TreeNode* newNode = createNode(data);

    if (parent == NULL) {
        
        root = newNode;
    } else if (data < parent->data) {
        parent->left = newNode;
        newNode->right = parent;     
        newNode->isThreaded = 1;
    } else {
        newNode->right = parent->right; 
        newNode->isThreaded = 1;
        parent->right = newNode;
        parent->isThreaded = 0;
    }

    return root;
}


TreeNode* leftMost(TreeNode* node) {
    if (node == NULL) return NULL;
    while (node->left != NULL)
        node = node->left;
    return node;
}


void inorderTraversal(TreeNode* root) {
    TreeNode* current = leftMost(root);

    while (current != NULL) {
        printf("%d ", current->data);

        if (current->isThreaded) {
            current = current->right; 
        } else {
            current = leftMost(current->right); 
        }
    }
}

int main() {
    TreeNode* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("중위 순회 (Threaded BST): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}