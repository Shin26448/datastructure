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
    int min = p->elem;//제일 작은 원소

    while (p != NULL) {
        int found = 0;

        NODE* q = B;
        while (q != NULL) {
            if (p->elem == q->elem) { // A의 요소가 B에 있는 경우
                found = 1;
                break;
            }
            q = q->next;
        }

        if (found == 0) { // A의 요소가 B에 없는 경우
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
    NODE* A = NULL; // A 리스트 초기화
    NODE* B = NULL; // B 리스트 초기화

    int counta, countb, e;
    int found = 0;

    scanf("%d", &counta);
    getchar();
    if (counta == 0)
        found = 1;
    else {
        for (int i = 0; i < counta; i++) {
            scanf("%d", &e);
            NODE* newNode = (NODE*)malloc(sizeof(NODE)); // 새 노드 생성
            newNode->elem = e;
            newNode->next = NULL; // 새 노드를 마지막에 추가하므로 next는 NULL
            if (A == NULL) { // 첫 번째 노드인 경우
                A = newNode; // A의 시작을 새 노드로 설정
            }
            else {
                NODE* temp = A;
                while (temp->next != NULL) {
                    temp = temp->next; // temp를 다음 노드로 이동
                }
                temp->next = newNode; // 이전 노드의 다음을 새 노드로 설정
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
            NODE* newNode = (NODE*)malloc(sizeof(NODE)); // 새 노드 생성
            newNode->elem = e;
            newNode->next = NULL; // 새 노드를 마지막에 추가하므로 next는 NULL
            if (B == NULL) { // 첫 번째 노드인 경우
                B = newNode; // B의 시작을 새 노드로 설정
            }
            else {
                NODE* temp = B;
                while (temp->next != NULL) {
                    temp = temp->next; // temp를 다음 노드로 이동
                }
                temp->next = newNode; // 이전 노드의 다음을 새 노드로 설정
            }
        }
    }

    if (found == 1) { // B가 공집합인 경우
        if (A == 0) // A도 공집합이면
            printf("0");
        else { // A가 공집합이 아닌 경우 A의 최솟값 출력
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
    else // B가 공집합이 아닌 경우
        subset(A, B);

    // 메모리 해제
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

