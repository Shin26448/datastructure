#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

//노드 정보
typedef struct node {
    int coef;
    int exp;
    struct node* next;
}NODE;

typedef struct list {
    NODE* head;
    NODE* trail;
    int numofData;
}LIST;

NODE* getNode() {
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->next = NULL;

    return newNode;
}

LIST* initList() {
    LIST* L = (LIST*)malloc(sizeof(LIST));
    L->head = getNode(); 
    L->trail = L->head;
    L->numofData = 0;

    return L;
}

void appendTerm(LIST* k, int c, int e) {
    NODE* t = getNode(); 
    t->coef = c;
    t->exp = e;

    k->trail->next = t;
    k->trail = t;

    k->numofData++;
}

LIST* addPoly(LIST* x, LIST* y) {
    LIST* result = initList();
    NODE* i = x->head->next;
    NODE* j = y->head->next;

    while (i != NULL && j != NULL) {
        if (i->exp > j->exp) {
            appendTerm(result, i->coef, i->exp);
            i = i->next;
        }

        else if (i->exp < j->exp) {
            appendTerm(result, j->coef, j->exp);
            j = j->next;
        }

        else {
            int sum = i->coef + j->coef;
            if (sum != 0)
                appendTerm(result, sum, i->exp);
            i = i->next;
            j = j->next;
        }
    }

    while (i != NULL) {
        appendTerm(result, i->coef, i->exp);
        i = i->next;
    }
    while (j != NULL) {
        appendTerm(result, j->coef, j->exp);
        j = j->next;
    }

    return result;
}

int main() {
    LIST* x = initList();
    LIST* y = initList();
    LIST* result = initList(); 

    int count, c, e;

    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%d %d", &c, &e);

        appendTerm(x, c, e);
    }

    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%d %d", &c, &e);

        appendTerm(y, c, e);
    }

    result = addPoly(x, y);

    NODE* current = result->head->next;

    while (current != NULL) {
        printf(" %d %d", current->coef, current->exp);
        current = current->next;
    }

    return 0;
}
