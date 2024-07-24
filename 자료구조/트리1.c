#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

void initNode(Node* S) {
    S->left = NULL;
    S->right = NULL;
}

int main() {
    Node* f1 = (Node*)malloc(sizeof(Node));
    Node* f2 = (Node*)malloc(sizeof(Node));
    Node* f3 = (Node*)malloc(sizeof(Node));
    Node* f4 = (Node*)malloc(sizeof(Node));
    Node* f5 = (Node*)malloc(sizeof(Node));
    Node* f6 = (Node*)malloc(sizeof(Node));
    Node* f7 = (Node*)malloc(sizeof(Node));
    Node* f8 = (Node*)malloc(sizeof(Node));

    f1->data = 20;
    f2->data = 30;
    f3->data = 50;
    f4->data = 70;
    f5->data = 90;
    f6->data = 120;
    f7->data = 130;
    f8->data = 80;

    f6->left = f7;
    f6->right = f8;
    f3->right = f6;
    f2->left = f4;
    f2->right = f5;
    f1->left = f2;
    f1->right = f3;

    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("%d %d %d", f1->data, (f1->left)->data, (f1->right)->data);
    }
    else if (n == 2) {
        printf("%d %d %d", f2->data, (f2->left)->data, (f2->right)->data);

    }
    else if (n == 3) {
        printf("%d %d", f3->data, (f3->right)->data);

    }
    else if (n == 4) {
        printf("%d", f4->data);

    }
    else if (n == 5) {
        printf("%d", f5->data);

    }
    else if (n == 6) {
        printf("%d %d %d", f6->data, (f6->left)->data, (f6->right)->data);

    }
    else if (n == 7) {
        printf("%d", f7->data);

    }
    else if (n == 8) {
        printf("%d", f8->data);

    }
    else
        printf("-1");

    return 0;
}