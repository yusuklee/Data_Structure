#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LEVEL 6

typedef struct Node{
	int key;
	int value;
	struct Node** forward;
} Node;

typedef struct SkipList{
	int level;
	Node* header;
} SkipList;

Node* createNode(int key, int value, int level){
	Node* newNode=malloc(sizeof(Node));
	newNode->key=key;
	newNode->value=value;
	newNode->forward = (Node**)malloc(sizeof(Node*) * (level + 1));
	for(int i = 0; i <= level; i++) {
		newNode->forward[i] = NULL;
	}
	return newNode;
}

SkipList* createSkipList(){
	SkipList* skipList = (SkipList*)malloc(sizeof(SkipList));
	skipList->level = 0;
	skipList->header = createNode(INT_MIN, 0, MAX_LEVEL);
	return skipList;
}

int randomLevel(){
	int level = 0;
	while(rand() < RAND_MAX / 2 && level < MAX_LEVEL){
		level++;
	}
	return level;
}

void insert(SkipList* skipList, int key, int value){
	Node* current = skipList->header;
	Node* update[MAX_LEVEL + 1];
	for (int i = 0; i <= MAX_LEVEL; i++){
		update[i] = NULL;
	}

	for (int i = skipList->level; i >= 0; i--){
		while(current->forward[i] != NULL && current->forward[i]->key < key){
			current = current->forward[i];
		}
		update[i] = current;
	}
	current = current->forward[0];

	if (current == NULL || current->key != key){
		int newLevel = randomLevel();
		if(newLevel > skipList->level){
			for(int i = skipList->level + 1; i <= newLevel; i++){
				update[i] = skipList->header;
			}
			skipList->level = newLevel;
		}
		Node* newNode = createNode(key, value, newLevel);
		for(int i = 0; i <= newLevel; i++){
			newNode->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = newNode;
		}
	}
}

void delete(SkipList* skipList, int key){
	Node* current = skipList->header;
	Node* new[MAX_LEVEL + 1];
	for (int i = 0; i <= MAX_LEVEL; i++) {
		new[i] = NULL;
	}

	for (int i = skipList->level; i >= 0; i--){
		while (current->forward[i] != NULL && current->forward[i]->key < key){
			current = current->forward[i];
		}
		new[i] = current;
	}
	current = current->forward[0];

	if (current != NULL && current->key == key){
		for (int i = 0; i <= skipList->level; i++){
			if (new[i]->forward[i] != current){
				break;
			}
			new[i]->forward[i] = current->forward[i];
		}
		free(current->forward);
		free(current);
		while (skipList->level > 0 && skipList->header->forward[skipList->level] == NULL){
			skipList->level--;
		}
	}
}

Node* search(SkipList* skipList, int key){
	Node* current = skipList->header;
	for (int i = skipList->level; i >= 0; i--){
		while (current->forward[i] != NULL && current->forward[i]->key < key){
			current = current->forward[i];
		}
	}
	current = current->forward[0];

	if(current != NULL && current->key == key){
		return current;
	}
	else{
		return NULL;
	}
}

void display(SkipList* skipList){
	printf("Skip List: \n");
	for(int i = skipList->level; i >= 0; i--){
		Node* node = skipList->header->forward[i];
		printf("Level %d: ", i);
		while(node != NULL) {
			printf("(%d, %d) ", node->key, node->value);
			node = node->forward[i];
		}
		printf("\n");
	}
}

int main(){
	SkipList* skipList = createSkipList();

	insert(skipList, 3, 30);
	insert(skipList, 6, 60);
	insert(skipList, 9, 90);
	insert(skipList, 2, 20);

	printf("Skip List after insertions: \n");
	display(skipList);

	delete(skipList, 6);
	printf("\nSkip List after deleting key 6: \n");
	display(skipList);
	
	return 0;
}
