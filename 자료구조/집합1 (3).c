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

void subset(LIST* A, LIST* B) {
    NODE* p = A->head;
    NODE* q = B->head;
    NODE* prevP = NULL;
    NODE* prevQ = NULL;

    int min;

    while (p != NULL && q != NULL) {
        if (p->elem < q->elem) {//A��<B��
            min=p->elem;//�� ��ġ�� ���� �ּڰ� Ȯ��
            break;
        }
        else if (p->elem > q->elem) {//A��>B��
            prevQ = q;
            q = q->next;//�Ѿ
        }
        else {//A==B
            if (prevP == NULL) {//���� ���� B�� ���Ƽ� ���ŵ��� ��
                A->head = p->next;
                free(p);
                p = A->head;//���� ����
            }
            else {
                prevP->next = p->next;//���� ���� B�� �޶� ���ŵ��� �ʾ��� ��
                free(p);
                p = prevP->next;
            }

            if (prevQ == NULL) {
                B->head = q->next;
                free(q);
                q = B->head;
            }
            else {
                prevQ->next = q->next;
                free(q);
                q = prevQ->next;
            }
        }
    }

    if (p != NULL) {//B ���ں��� A�� �� ���� ��, �ٷ� ù��°�� �ִ� ���Ұ� �ּڰ�
        min = p->elem;
    }

    printf("%d", min);
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

    subset(A, B);

    while (A->head != NULL) {
        NODE* temp = A->head;
        A->head = A->head->next;
        free(temp);
    }

    return 0;
}