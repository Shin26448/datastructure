#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct node {
	char data;
	struct node* left;
	struct node* right;
}Node;

Node* initNode(char data) {
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;

}

Node* findNode(Node* s, char data) {
	if (s == NULL)
		return NULL;
	if (s->data == data)
		return s;

	Node* leftNode = findNode(s->left, data);
	if (leftNode != NULL)
		return leftNode;
	else {
		Node* rightNode = findNode(s->right, data);
		return rightNode;
	}
}

void linkNode(Node* s, char data, char left, char right) {
	Node* currentNode = findNode(s, data);
	if (left != '.')
		currentNode->left = initNode(left);
	if (right != '.')
		currentNode->right = initNode(right);
}

void preorder(Node* s) {
	if (s == NULL)
		return;
	printf("%c", s->data);
	preorder(s->left);
	preorder(s->right);
}

void inorder(Node* s) {
	if (s == NULL)
		return;
	inorder(s->left);
	printf("%c", s->data);
	inorder(s->right);
}

void postorder(Node* s) {
	if (s == NULL)
		return;
	postorder(s->left);
	postorder(s->right);
	printf("%c", s->data);
}

int main() {
	int n;
	char data, left, right;
	scanf("%d", &n);
	getchar();

	Node* root = NULL;

	for (int i = 0; i < n; i++) {
		scanf("%c %c %c", &data, &left, &right);
		getchar();

		if (root == NULL) {
			root = initNode(data);
		}
		linkNode(root, data, left, right);
	}

	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");

	postorder(root);

	return 0;
}