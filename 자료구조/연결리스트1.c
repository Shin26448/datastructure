#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

// �� ��忡 ����Ǵ� ����
typedef struct node {
    struct node* prev;
    char elem;
    struct node* next;
}node;

// ��� �����
node* getnode() {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

// ���� �̷���� ����Ʈ ����
typedef struct list {
    int numofData; // ����� ������ ����
    node* head; // ó�� ���
    node* tail; // ������ ���
} list;

// ����Ʈ �ʱ�ȭ (������� Ʋ �ϼ�)
list* initList() {
    list* L = (list*)malloc(sizeof(list));
    L->head = getnode();
    L->tail = getnode();

    L->tail->prev = L->head; // �������� prev�� ó������
    L->head->next = L->tail; // ó���� next�� ���������� ����

    L->numofData = 0;

    return L;
}

void add(list* L, int r, char e);
void delete(list* L, int r);
void get(list* L, int r);
void print(list* L);

int main() {
    int n, r;
    char adgp, e;
    list* L = initList(); // ����Ʈ ����

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &adgp);
        if (adgp == 'A') {
            scanf("%d %c", &r, &e);
            add(L, r, e);
        }
        else if (adgp == 'D') {
            scanf("%d", &r);
            delete(L, r);
        }
        else if (adgp == 'G') {
            scanf("%d", &r);
            get(L, r);
        }
        else if (adgp == 'P') {
            print(L);
        }
    }
    return 0;
}

// �߰�
void add(list* L, int r, char e) {
    node* newnode = getnode();
    newnode->elem = e;

    node* current = getnode();
    current = L->head; // ���

    if (r > L->numofData + 1) {
        printf("invalid position\n");
        return;
    }

    for (int i = 0; i < r - 1; i++) {
        current = current->next;
    } // current�� r-1��°�� ����Ŵ

    newnode->prev = current;
    newnode->next = current->next;

    (current->next)->prev = newnode;
    current->next = newnode;
    L->numofData++;
}


// ����
void delete(list* L, int r) {
    if (r < 1 || r > L->numofData) {
        printf("invalid position\n");
        return;
    }

    node* current = L->head->next; // ù ��° ������ ������ ����

    for (int i = 1; i < r; i++) {
        current = current->next;
    } // current�� r��°�� ����Ŵ

    (current->prev)->next = current->next;
    (current->next)->prev = current->prev;

    free(current);
    L->numofData--;
}

// ��ȸ
void get(list* L, int r) {
    if (r < 1 || r > L->numofData) {
        printf("invalid position\n");
        return;
    }

    node* current = L->head->next; // ù ��° ������ ������ ����

    for (int i = 1; i < r; i++) {
        current = current->next;
    } // current�� r��°�� ����Ŵ

    printf("%c\n", current->elem);
}

// ���
void print(list* L) {
    node* current = L->head->next; // ù ��° ������ ������ ����

    while (current != L->tail) {
        printf("%c ", current->elem);
        current = current->next;
    }
    printf("\n");
}
//�ٵ� �����Ҵ� ������ ��𿡼� ����....?
