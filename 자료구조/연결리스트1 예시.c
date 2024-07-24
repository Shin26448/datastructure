#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct node {
    struct node* prev;
    char elem;
    struct node* next;
}NODE;

NODE* getNode() {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->elem = NULL;

    return newNode;
}

typedef struct list {
    int numofData;
    NODE* head;
    NODE* trail;
} LIST;

LIST* initList() {
    LIST* L = (LIST*)malloc(sizeof(LIST));
    L->head = getNode();
    L->trail = getNode();
    L->head->next = L->trail;
    L->trail->prev = L->head;
    L->numofData = 0;
    return L;
}

void add(LIST* L, int r, char e) {
    NODE* newNode = getNode();
    newNode->elem = e;

    NODE* current = L->head;

    if (r > L->numofData + 1) {
        printf("invalid position\n");
        return;
    }

    for (int i = 0; i < r - 1; i++) {
        current = current->next;
    }
    newNode->prev = current;
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;

    L->numofData++;
}


void delete(LIST* L, int r) {
    NODE* current = L->head;

    if (r > L->numofData) {
        printf("invalid position\n");
        return;
    }

    for (int i = 0; i < r; i++) {
        current = current->next;
    }

    (current->prev)->next = current->next;
    (current->next)->prev = current->prev;

    L->numofData--;

}
void get(LIST* L, int r) {
    NODE* current = L->head;

    if (r > L->numofData) {
        printf("invalid position\n");
        return;
    }
    for (int i = 0; i < r; i++) {
        current = current->next;
    }
    printf("%c\n", current->elem);
}


void print(LIST* L) {
    NODE* current = L->head->next;

    while (current != L->trail) {
        printf("%c", current->elem);
        current = current->next;
    }
    printf("\n");
}


int main() {
    int n, r;
    char list, e;
    LIST* L = initList();

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        getchar();

        scanf("%c", &list);
        if (list == 'A') {
            scanf("%d %c", &r, &e);

            add(L, r, e);
        }
        else if (list == 'D') {
            scanf("%d", &r);

            delete(L, r);
        }
        else if (list == 'G') {
            scanf("%d", &r);

            get(L, r);
        }
        else if (list == 'P') {
            print(L);
        }
    }
    return 0;
}
