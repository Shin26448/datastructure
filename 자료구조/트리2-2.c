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

int order(Node* s) {
    if (s == NULL)
        return 0;
    int sum = s->data;
    sum += order(s->left);
    sum += order(s->right);
    return sum;
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

    int n;
    scanf("%d", &n);

    if (n > 8)
        printf("-1");
    else {
        Node* find = findNode(root, n);
        int sum = order(find);
        printf("%d", sum);
    }

    return 0;
}

