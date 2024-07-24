#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct node {
    int elem;
    struct node* next;
} NODE;

void subset(NODE* A, NODE* B) {
    if (A == NULL || B == NULL) {
        printf("0");
        return;
    }

    int allcount = 0;
    NODE* p = A;
    int min = p->elem;//���� ���� ����

    while (p != NULL) {
        int found = 0;

        NODE* q = B;
        while (q != NULL) {
            if (p->elem == q->elem) { // A�� ��Ұ� B�� �ִ� ���
                found = 1;
                break;
            }
            q = q->next;
        }

        if (found == 0) { // A�� ��Ұ� B�� ���� ���
            if (min > p->elem) {
                min = p->elem;
            }
            allcount = 1;
        }

        p = p->next;
    }

    if (allcount == 0)
        printf("0");
    else
        printf("%d", min);
}

int main() {
    NODE* A = NULL; // A ����Ʈ �ʱ�ȭ
    NODE* B = NULL; // B ����Ʈ �ʱ�ȭ

    int counta, countb, e;
    int found = 0;

    scanf("%d", &counta);
    getchar();
    if (counta == 0)
        found = 1;
    else {
        for (int i = 0; i < counta; i++) {
            scanf("%d", &e);
            NODE* newNode = (NODE*)malloc(sizeof(NODE)); // �� ��� ����
            newNode->elem = e;
            newNode->next = NULL; // �� ��带 �������� �߰��ϹǷ� next�� NULL
            if (A == NULL) { // ù ��° ����� ���
                A = newNode; // A�� ������ �� ���� ����
            }
            else {
                NODE* temp = A;
                while (temp->next != NULL) {
                    temp = temp->next; // temp�� ���� ���� �̵�
                }
                temp->next = newNode; // ���� ����� ������ �� ���� ����
            }
        }
    }

    scanf("%d", &countb);
    getchar();
    if (countb == 0)
        found = 1;
    else {
        for (int i = 0; i < countb; i++) {
            scanf("%d", &e);
            NODE* newNode = (NODE*)malloc(sizeof(NODE)); // �� ��� ����
            newNode->elem = e;
            newNode->next = NULL; // �� ��带 �������� �߰��ϹǷ� next�� NULL
            if (B == NULL) { // ù ��° ����� ���
                B = newNode; // B�� ������ �� ���� ����
            }
            else {
                NODE* temp = B;
                while (temp->next != NULL) {
                    temp = temp->next; // temp�� ���� ���� �̵�
                }
                temp->next = newNode; // ���� ����� ������ �� ���� ����
            }
        }
    }

    if (found == 1) { // B�� �������� ���
        if (A == 0) // A�� �������̸�
            printf("0");
        else { // A�� �������� �ƴ� ��� A�� �ּڰ� ���
            NODE* p = A;
            int min = p->elem;
            while (p != NULL) {
                if (p->elem < min) {
                    min = p->elem;
                }
                p = p->next;
            }
            printf("%d", min);
        }
    }
    else // B�� �������� �ƴ� ���
        subset(A, B);

    // �޸� ����
    NODE* temp;
    while (A != NULL) {
        temp = A;
        A = A->next;
        free(temp);
    }
    while (B != NULL) {
        temp = B;
        B = B->next;
        free(temp);
    }

    return 0;
}

