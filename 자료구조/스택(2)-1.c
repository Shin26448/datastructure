#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)


typedef struct STACK {
    char ch;
    int priority;
    struct STACK* next;
} STACK;

void push(STACK** head, char ch, int priority);
char pop(STACK** head);
int isEmpty(STACK* head);
int isOper(char ch);
int isLogic(char ch);
STACK* convert(char* str);
void print(STACK* head);

int main() {
    STACK* result;
    int n;
    char str[101];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        result = convert(str);
        print(result);
        printf("\n");
        while (!isEmpty(result)) {
            pop(&result);
        }
    }

    return 0;
}



void push(STACK** head, char ch, int priority) {
    STACK* newNode = (STACK*)malloc(sizeof(STACK));
    if (!newNode) {
        return;
    }
    newNode->ch = ch;
    newNode->priority = priority;
    newNode->next = *head;
    *head = newNode;
}

char pop(STACK** head) {
    if (*head == NULL) {
        return '\0';  
    }
    STACK* temp = *head;
    char ch = temp->ch;
    *head = temp->next;
    free(temp);
    return ch;
}

int isEmpty(STACK* head) {
    return head == NULL;
}

int isOper(char ch) {
    if (ch == '!') return 6;
    if (ch == '*' || ch == '/') return 5;
    if (ch == '+' || ch == '-') return 4;
    if (ch == '<' || ch == '>') return 3;
    if (ch == '&') return 2;
    if (ch == '|') return 1;
    return 0;
}

int isLogic(char ch) {
    return (ch == '&' || ch == '|');
}


STACK* convert(char* str) {
    STACK* result = NULL, * operStack = NULL;
    char* p;
    int type, top;

    for (p = str; *p; p++) {
        type = isOper(*p);

        // 알파벳일 경우, result에 push
        if ('A' <= *p && *p <= 'Z') {
            push(&result, *p, 0);
        }
        // 괄호를 제외한 연산자일 경우,
        else if (type) {
            if (*p == '+' || *p == '-') {
                // +, -가 식의 맨 앞에 나오거나, 다른 연산자 바로 뒤에 나온다면,
                if (p == str || isOper(*(p - 1))) {
                    type = 6; // 우선순위를 6으로 설정
                }
            }
            if (isEmpty(operStack)) {
                push(&operStack, *p, type);
            }
            else {
                top = operStack->priority;
                if (type == top) {
                    char insertOper = pop(&operStack);
                    push(&result, insertOper, 0);
                    if (isLogic(insertOper)) {
                        push(&result, insertOper, 0);
                    }
                }
                else if (type < top) {
                    while (!isEmpty(operStack) && operStack->ch != '(') {
                        char insertOper = pop(&operStack);
                        push(&result, insertOper, 0);
                        if (isLogic(insertOper)) {
                            push(&result, insertOper, 0);
                        }
                    }
                }
                push(&operStack, *p, type);
            }
        }
        else if (*p == '(') {
            push(&operStack, *p, type);
        }
        else if (*p == ')') {
            while (!isEmpty(operStack) && operStack->ch != '(') {
                char insertOper = pop(&operStack);
                push(&result, insertOper, 0);
                if (isLogic(insertOper)) {
                    push(&result, insertOper, 0);
                }
            }
            pop(&operStack);
        }
        if (*p == '&' || *p == '|') {
            p++;
        }
    }
    while (!isEmpty(operStack)) {
        char insertOper = pop(&operStack);
        push(&result, insertOper, 0);
        if (isLogic(insertOper)) {
            push(&result, insertOper, 0);
        }
    }

    return result;
}

// 스택 출력 함수
void print(STACK* head) {
    if (!head) return;
    print(head->next);
    printf("%c", head->ch);
}
