#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)


typedef struct node {
    int elem;
    struct node* next;
} NODE;

typedef struct list {
    NODE* head;
    int numofData;
} LIST;

NODE* getNode() {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->next = NULL;
    return newNode;
}

LIST* initList() {
    LIST* L = (LIST*)malloc(sizeof(LIST));
    L->head = NULL;
    L->numofData = 0;
    return L;
}

void addNode(LIST* L, int e) {
    NODE* newNode = getNode();
    newNode->elem = e;

    if (L->head == NULL) {
        L->head = newNode;
    }
    else {
        NODE* cur = L->head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = newNode;
    }
    L->numofData++;
}

void union1(LIST* A, LIST* B) {

    LIST* result = initList();

    NODE* p = A->head;
    NODE* q = B->head;

    while (p != NULL && q != NULL) {
        if (p->elem < q->elem) {
            addNode(result, p->elem);
            p = p->next;
        }
        else if (p->elem > q->elem) {
            addNode(result, q->elem);
            q = q->next;
        }
        else {
            addNode(result, p->elem);
            p = p->next;
            q = q->next;
        }
    }

    while (p != NULL && q == NULL) {
        addNode(result, p->elem);
        p = p->next;
    }

    while (p == NULL && q != NULL) {
        addNode(result, q->elem);
        q = q->next;
    }

    NODE* r = result->head;
    if (r == NULL)
        printf(" 0");

    while (r != NULL) {
        printf(" %d", r->elem);
        r = r->next;
    }
}

void intersect(LIST* A, LIST* B) {
    NODE* p = A->head;
    NODE* q = B->head;
    int count = 0;

    while (p != NULL && q != NULL) {
        if (p->elem < q->elem) {
            p = p->next;
        }
        else if (p->elem > q->elem) {
            q = q->next;
        }
        else { 
            printf(" %d", p->elem); 
            count++;
            p = p->next;
            q = q->next;
        }
    }

    if (count == 0)
        printf(" 0");

}

int main() {
    LIST* A = initList();
    LIST* B = initList();

    int count, e;

    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &e);
        addNode(A, e);
    }

    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &e);
        addNode(B, e);
    }

    union1(A, B);
    printf("\n");
    intersect(A, B);


    return 0;
}



