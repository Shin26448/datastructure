#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)


// ��� ����ü ����
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// �� ����ü ����
typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

// �� �ʱ�ȭ
void initDeque(Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// ��� ����
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// ���߰�
void add_front(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (deque->front == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    }
    else {
        newNode->next = deque->front;
        deque->front->prev = newNode;
        deque->front = newNode;
    }
}

// ���߰�
void add_rear(Deque* deque, int data) {
    Node* newNode = createNode(data);
    if (deque->rear == NULL) {
        deque->front = newNode;
        deque->rear = newNode;
    }
    else {
        newNode->prev = deque->rear;
        deque->rear->next = newNode;
        deque->rear = newNode;
    }
}

// �ջ���
int delete_front(Deque* deque) {
    if (deque->front == NULL) {
        printf("underflow\n");
        exit(0);
    }
    Node* temp = deque->front;
    int data = temp->data;
    deque->front = deque->front->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    }
    else {
        deque->front->prev = NULL;
    }
    free(temp);
    return data;
}

// �޻���
int delete_rear(Deque* deque) {
    if (deque->rear == NULL) {
        printf("underflow\n");
        exit(0);
    }
    Node* temp = deque->rear;
    int data = temp->data;
    deque->rear = deque->rear->prev;
    if (deque->rear == NULL) {
        deque->front = NULL;
    }
    else {
        deque->rear->next = NULL;
    }
    free(temp);
    return data;
}

// ���� ��� ���� ���
void print(Deque* deque) {
    Node* temp = deque->front;
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    char com[3];
    int value;
    Deque deque;

    initDeque(&deque);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", com);
        if (com[0] == 'A' && com[1] == 'F') {
            scanf("%d", &value);
            add_front(&deque, value);
        }
        else if (com[0] == 'A' && com[1] == 'R') {
            scanf("%d", &value);
            add_rear(&deque, value);
        }
        else if (com[0] == 'D' && com[1] == 'F') {
            delete_front(&deque);
        }
        else if (com[0] == 'D' && com[1] == 'R') {
            delete_rear(&deque);
        }
        else if (com[0] == 'P') {
            print(&deque);
        }
    }

    return 0;
}
