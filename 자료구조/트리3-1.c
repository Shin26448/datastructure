#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}Node;

Node* initNode(int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;

}

Node* findNode(Node* s, int data) {
	//if (s == NULL)
		//return NULL;
	if (s->data == data)
		return s;

	Node* leftNode = findNode(s->left, data);
	if (leftNode != NULL)
		return leftNode; 

	Node*rightNode= findNode(s->right, data);
	return rightNode;
}

void linkNode(Node* s, int data, int left, int right) {
	Node* currentNode = findNode(s, data);
	if (left != 0)
		currentNode->left = initNode(left);
	if (right != 0)
		currentNode->right = initNode(right);

	
}

int main() {
	int n;
	int data, left, right;
	scanf("%d", &n);

	Node* root = NULL;
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &data, &left, &right);

		if (root == NULL) {
			root = initNode(data);
		}
		linkNode(root, data, left, right);
	}

	int s;
	char command[101];
	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		scanf("%s", command);
		Node* currentNode = root;

		printf(" %d", currentNode->data);

		for (int j = 0; j < strlen(command); j++) {
			if (command[j] == 'L') {
				currentNode = currentNode->left;
				printf(" %d", currentNode->data);
			}
			else if (command[j] == 'R') {
				currentNode = currentNode->right;
				printf(" %d", currentNode->data);
			}

		}

		printf("\n");
	}
	
	return 0;
}