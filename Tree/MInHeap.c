#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
//배열로 바꿨습니다.
typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

void initHeap(MinHeap* h) {
    h->size = 0;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(MinHeap* h, int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (h->data[index] < h->data[parent]) {
        swap(&h->data[index], &h->data[parent]);
        heapify(h, parent);
    }
}

void insert(MinHeap* h, int value) {
    if (h->size >= MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    h->data[h->size] = value;
    heapify(h, h->size);
    h->size++;
}

void inorderTraversal(int* data, int index, int size) {
    if (index >= size) return;
    inorderTraversal(data, 2 * index + 1, size);  // left
    printf("%d ", data[index]);                  // root
    inorderTraversal(data, 2 * index + 2, size);  // right
}

int main() {
    MinHeap heap;
    initHeap(&heap);

    insert(&heap, 5);
    insert(&heap, 3);
    insert(&heap, 8);
    insert(&heap, 1);
    insert(&heap, 7);

    printf("inorder Traversal: ");
    inorderTraversal(heap.data, 0, heap.size);
    printf("\n");

    printf("Min: %d\n", heap.data[0]);

    return 0;
}