#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


typedef struct Node {
    int num;  // 요소의 숫자
    int idx;  // 요소의 인덱스
    struct Node* next;  // 다음 노드를 가리키는 포인터
} Node;

typedef struct {
    Node* head;  // 우선순위 큐의 첫 번째 노드를 가리키는 포인터
} Priority;

void initPriorityQueue(Priority* p) {
    p->head = NULL;  // 우선순위 큐 초기화: 헤드를 NULL로 설정
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
            free(target); // m번째 이전까지만 메모리 해제
        }
    }

    int result = 0;  // 기본값으로 초기화
    if (target != NULL) {
        result = target->idx + 1;  // 인덱스는 0부터 시작하므로 +1을 해줌
        free(target); // 마지막 target 메모리 해제
    }

    return result;
}

