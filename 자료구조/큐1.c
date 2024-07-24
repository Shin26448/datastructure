#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct que {
    int front;
    int rear;
    int* Q; // 원형 배열
} Que;

int isEmpty(Que* q) {
    return q->front == q->rear;
}

int isFull(Que* q, int N) {
    return ((q->rear + 1) % N) == q->front;
}

void initQue(Que* q, int N) {
    q->Q = (int*)malloc(sizeof(int) * N);
    q->front = 0;
    q->rear = 0;
    for (int i = 0; i < N; i++) {
        q->Q[i] = 0; // 모든 배열 요소를 0으로 초기화
    }
}

void fullQueException(Que* q, int N) {
    printf("overflow");
    for (int i = 0; i < N; i++) {
        printf(" %d ", q->Q[i]);
    }
    printf("\n");
    exit(0); // 오버플로우 발생 시 프로그램 종료
}

void emptyQueException() {
    printf("underflow");
    exit(0); // 언더플로우 발생 시 프로그램 종료
}

void enQue(Que* q, int N, int e) {
    if (isFull(q, N)) {
        fullQueException(q, N);
        return;
    }
    q->rear = (q->rear + 1) % N;
    q->Q[q->rear] = e;
}

int deQue(Que* q, int N) {
    if (isEmpty(q)) {
        emptyQueException();
        return -1; 
    }
    q->front = (q->front + 1) % N;
    int value = q->Q[q->front];
    q->Q[q->front] = 0; // 삭제 후 0으로 치환
    return value;
}

void printQue(Que* q, int N) {
    for (int i = 0; i < N; i++) {
        printf(" %d ", q->Q[i]);
    }
    printf("\n");
}

int main() {
    int N, qcount;
    char order;
    Que q;

    scanf("%d", &qcount);
    scanf("%d", &N);
    initQue(&q, qcount);

    for (int i = 0; i < N; i++) {
        scanf(" %c", &order);
        if (order == 'I') {
            int e;
            scanf("%d", &e);
            enQue(&q, qcount, e);
        }
        else if (order == 'D') {
            deQue(&q, qcount);
        }
        else if (order == 'P') {
            printQue(&q, qcount);
        }
    }

    free(q.Q); // 동적 할당 해제

    return 0;
}
