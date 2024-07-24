#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int num;
    struct Stack* next;
} STACK;

void input(char* str);
void push(STACK** head, int n);
int pop(STACK** head);
int calculate(char* str);
int isOper(char ch);

int main() {
    
    int n, result;
    char str[101];
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        input(str);
        result = calculate(str);
        printf("%d\n", result);
    }

    return 0;
}

void input(char* str) {
    scanf(" %s", str);
}

void push(STACK** head, int n) {
    STACK* new = (STACK*)malloc(sizeof(STACK));
    if (!new) {
        return;
    }

    new->num = n;
    new->next = *head;
    *head = new;
}

// ½ºÅÃ top ¹ÝÈ¯, »èÁ¦ ÇÔ¼ö
int pop(STACK** head) {
    if (*head == NULL) {
        return 0;
    }

    STACK* del = *head;
    int retNum = del->num;
    *head = (*head)->next;
    free(del);
    del = NULL;

    return retNum;
}

int calculate(char* str) {
    STACK* head = NULL;
    int retNum, insert;
    char* p;

    for (p = str; *p; p++) {
        // ¼ýÀÚ¸é Á¤¼ö·Î º¯È¯ ÈÄ ½ºÅÃ¿¡ push
        if ('0' <= *p && *p <= '9') {
            insert = *p - '0';
            push(&head, insert);
        }
        else if (isOper(*p)) {
            insert = pop(&head);
            int num1 = pop(&head);
            switch (*p) {
            case '+': // µ¡¼À
                push(&head, num1 + insert);
                break;
            case '-': // »¬¼À
                push(&head, num1 - insert);
                break;
            case '*': // °ö¼À
                push(&head, num1 * insert);
                break;
            case '/': // ³ª´°¼À(¸ò)
                push(&head, num1 / insert);
                break;
            }
        }
    }
   
    retNum = pop(&head);
    return retNum;
}

int isOper(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

