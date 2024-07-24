#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
    int data;
    struct node* parent;
    struct node* left;
    struct node* right;
} Node;

void initNode(Node* S, int data) {
    S->data = data;
    S->parent = NULL;
    S->left = NULL;
    S->right = NULL;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    initNode(newNode, data);
    return newNode;
}

void printNode(Node* node) {
    if (node == NULL) {
        printf("-1\n");
        return;
    }
    
    printf("%d ", node->data);
    if (node->left != NULL) {
        printf("%d ", node->left->data);
    }
    
    if (node->right != NULL) {
        printf("%d ", node->right->data);
    }
    
}


int main() {
    Node* f1 = createNode(20);
    Node* f2 = createNode(30);
    Node* f3 = createNode(50);
    Node* f4 = createNode(70);
    Node* f5 = createNode(90);
    Node* f6 = createNode(120);
    Node* f7 = createNode(130);
    Node* f8 = createNode(80);

    f1->left = f2;
    f1->right = f3;
    f2->parent = f1;
    f3->parent = f1;

    f2->left = f4;
    f2->right = f5;
    f4->parent = f2;
    f5->parent = f2;

    f3->right = f6;
    f6->parent = f3;

    f6->left = f7;
    f6->right = f8;
    f7->parent = f6;
    f8->parent = f6;

    int n;
    scanf("%d", &n);

    if (n == 1)
        printNode(f1);
    else if (n == 2)
        printNode(f2);
    else if (n == 3)
        printNode(f3); 
    else if (n == 4)
        printNode(f4);
    else if (n == 5)
        printNode(f5);
    else if (n == 6)
        printNode(f6);
    else if (n == 7)
        printNode(f7);
    else if (n == 8)
        printNode(f8);
    
    else {
        printf("-1\n");
    }

    free(f1);
    free(f2);
    free(f3);
    free(f4);
    free(f5);
    free(f6);
    free(f7);
    free(f8);

    return 0;
}
