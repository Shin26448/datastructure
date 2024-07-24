#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct node {
    int num;
    int idx;
    struct node* next;
} Node;

typedef struct priority{
    Node* head;
} Priority;

void initPriority(Priority* p) {
    p->head = NULL;
}

void enQue(Priority* p, Node* newNode) {
    newNode->next = NULL;

    if (p->head == NULL || p->head->num < newNode->num) {
        newNode->next = p->head; 
        p->head = newNode;
    }
    else {
        Node* current = p->head;
        while (current->next != NULL && current->next->num >= newNode->num) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

Node* deQue(Priority* p) {
    if (p->head == NULL) {
        return NULL;
    }

    Node* tmp = p->head;
    p->head = p->head->next;
    tmp->next = NULL;
    return tmp;
}

int findQue(int n, int m, int queue[]) {
    int result;

    Priority p;
    initPriority(&p);

    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->num = queue[i];
        newNode->idx = i+1;

        enQue(&p, newNode);
    }

    Node* target = NULL;

    for (int i = 0; i <= m; i++) {
        target = deQue(&p);
        if (i != m && target != NULL)
            free(target);
    }

    if (target != NULL) {
        result = target->idx;
        free(target);
    }

    return result;
}

int main() {
    int Qnum;
    scanf("%d", &Qnum);

    for (int i = 0; i < Qnum; i++) {
        int n, m;
        scanf("%d %d", &n, &m);

        int queue[100];
        for (int j = 0; j < n; j++) {
            scanf("%d", &queue[j]);
        }

        int result = findQue(n, m, queue);
        printf("%d\n", result);
    }

    return 0;
}

