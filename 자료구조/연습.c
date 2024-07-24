#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


typedef struct Node {
    int num;  // ����� ����
    int idx;  // ����� �ε���
    struct Node* next;  // ���� ��带 ����Ű�� ������
} Node;

typedef struct {
    Node* head;  // �켱���� ť�� ù ��° ��带 ����Ű�� ������
} Priority;

void initPriorityQueue(Priority* p) {
    p->head = NULL;  // �켱���� ť �ʱ�ȭ: ��带 NULL�� ����
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

    Node* temp = p->head;
    p->head = p->head->next;
    temp->next = NULL;
    return temp;
}

int findQue(int n, int m, int queue[]) {
    Priority p;
    initPriorityQueue(&p);

    for (int i = 0; i < n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->num = queue[i];
        newNode->idx = i;

        enQue(&p, newNode);
    }

    Node* target = NULL;

    for (int i = 0; i < m + 1; i++) {
        target = deQue(&p);
        if (i != m && target != NULL) {
            free(target); // m��° ���������� �޸� ����
        }
    }

    int result = 0;  // �⺻������ �ʱ�ȭ
    if (target != NULL) {
        result = target->idx + 1;  // �ε����� 0���� �����ϹǷ� +1�� ����
        free(target); // ������ target �޸� ����
    }

    return result;
}

