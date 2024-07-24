#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


typedef struct node {
    struct node* left;
    int id;
    int data;
    struct node* right;
} Node;

Node* getinitNode(int id, int data) {
    Node* s = (Node*)malloc(sizeof(Node));
    s->left = NULL;
    s->id = id;
    s->data = data;
    s->right = NULL;

    return s;
}

Node* findNode(Node* s, int n) {
    if (s == NULL)
        return NULL;
    if (s->id == n)
        return s;
    Node* find = findNode(s->left, n);
    if (find == NULL)
        find = findNode(s->right, n);
}

void preorder(Node* s) {
    if (s == NULL)
        return;
    printf("%d ", s->data);
    preorder(s->left);
    preorder(s->right);
}

void inorder(Node* s) {
    if (s == NULL)
        return;
    inorder(s->left);
    printf("%d ", s->data);
    inorder(s->right);
}

void postorder(Node* s) {
    if (s == NULL)
        return;
    postorder(s->left);
    postorder(s->right);
    printf("%d ", s->data);
}

int main() {
    Node* root = getinitNode(1, 20);
    root->left = getinitNode(2, 30);
    root->right = getinitNode(3, 50);
    root->left->left = getinitNode(4, 70);
    root->left->right = getinitNode(5, 90);
    root->right->right = getinitNode(6, 120);
    root->right->right->left = getinitNode(7, 130);
    root->right->right->right = getinitNode(8, 80);

    int method;
    scanf("%d", &method);
    int n;
    scanf("%d", &n);

    Node* find = findNode(root, n);

    if (find == NULL)
        printf("-1");
    else if (method == 1)
        preorder(find);
    else if (method == 2)
        inorder(find);
    else if (method == 3)
        postorder(find);
    else
        printf("-1");

    return 0;
}
