#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

// 각 노드에 저장되는 정보
typedef struct node {
    struct node* prev;
    char elem;
    struct node* next;
}node;

// 노드 만들기
node* getnode() {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

// 노드로 이루어진 리스트 정보
typedef struct list {
    int numofData; // 저장된 데이터 개수
    node* head; // 처음 노드
    node* tail; // 마지막 노드
} list;

// 리스트 초기화 (여기까지 틀 완성)
list* initList() {
    list* L = (list*)malloc(sizeof(list));
    L->head = getnode();
    L->tail = getnode();

    L->tail->prev = L->head; // 마지막의 prev를 처음으로
    L->head->next = L->tail; // 처음의 next를 마지막으로 연결

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
    list* L = initList(); // 리스트 생성

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

// 추가
void add(list* L, int r, char e) {
    node* newnode = getnode();
    newnode->elem = e;

    node* current = getnode();
    current = L->head; // 헤더

    if (r > L->numofData + 1) {
        printf("invalid position\n");
        return;
    }

    for (int i = 0; i < r - 1; i++) {
        current = current->next;
    } // current가 r-1번째를 가리킴

    newnode->prev = current;
    newnode->next = current->next;

    (current->next)->prev = newnode;
    current->next = newnode;
    L->numofData++;
}


// 삭제
void delete(list* L, int r) {
    if (r < 1 || r > L->numofData) {
        printf("invalid position\n");
        return;
    }

    node* current = L->head->next; // 첫 번째 데이터 노드부터 시작

    for (int i = 1; i < r; i++) {
        current = current->next;
    } // current가 r번째를 가리킴

    (current->prev)->next = current->next;
    (current->next)->prev = current->prev;

    free(current);
    L->numofData--;
}

// 조회
void get(list* L, int r) {
    if (r < 1 || r > L->numofData) {
        printf("invalid position\n");
        return;
    }

    node* current = L->head->next; // 첫 번째 데이터 노드부터 시작

    for (int i = 1; i < r; i++) {
        current = current->next;
    } // current가 r번째를 가리킴

    printf("%c\n", current->elem);
}

// 출력
void print(list* L) {
    node* current = L->head->next; // 첫 번째 데이터 노드부터 시작

    while (current != L->tail) {
        printf("%c ", current->elem);
        current = current->next;
    }
    printf("\n");
}
//근데 동적할당 해제는 어디에서 하지....?
