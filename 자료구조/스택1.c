#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct STACK {
    char* ar;
    int top;
    int size;
} STACK;

void push(STACK* s, char ch);
char pop(STACK* s);
void peek(STACK* s);
void duplicate(STACK* s);
void upRotate(STACK* s, int n);
void downRotate(STACK* s, int n);
void print(STACK* s);

int main() {
    int N, count, a;

    scanf("%d", &N);
    scanf("%d", &count);

    STACK* s = (STACK*)malloc(sizeof(STACK));

    s->ar = (char*)malloc(sizeof(char) * N);
    s->top = -1;
    s->size = N;

    char cal[6], ch;

    while (count > 0) {

        scanf("%s", cal);

        if (strcmp(cal, "PUSH") == 0) {
            scanf(" %c", &ch);
            push(s, ch);
        }
        else if (strcmp(cal, "POP") == 0) 
            pop(s);
        else if (strcmp(cal, "PEEK") == 0) 
            peek(s);
        else if (strcmp(cal, "DUP") == 0) 
            duplicate(s);
        else if (strcmp(cal, "UpR") == 0) {
            scanf(" %d", &a);
            upRotate(s, a);
        }
        else if (strcmp(cal, "DownR") == 0) {
            scanf(" %d", &a);
            downRotate(s, a);
        }
        else print(s);

        count--;
    }
    free(s->ar); // 동적 할당된 메모리 해제
    free(s);
    return 0;
}

void push(STACK* s, char ch) {
    if (s->top == s->size - 1) {
        printf("Stack FULL\n");
        return;
    }
    s->top++;
    s->ar[s->top] = ch;
}

char pop(STACK* s) {
    if (s->top < 0) {
        printf("Stack Empty\n");
        return '\0';
    }
    char popped = s->ar[s->top];
    s->top--;
    return popped;
}

void peek(STACK* s) {
    if (s->top < 0) {
        printf("Stack Empty\n");
        return;
    }
    printf("%c\n", s->ar[s->top]);
}

void duplicate(STACK* s) {
    if (s->top == s->size - 1) {
        printf("Stack FULL\n");
        return;
    }
    char ch = pop(s);
    if (s->top == s->size - 1) {
        printf("Stack FULL\n");
        push(s, ch);
        push(s, ch);
        return;
    }
    s->top++;
    s->ar[s->top] = ch;
    s->top++;
    s->ar[s->top] = ch;
}

void upRotate(STACK* s, int n) {
    if (s->top < n - 1) return;

    char temp = s->ar[s->top];
    for (int i = s->top; i >= s->top - n + 1; i--) {
        s->ar[i] = s->ar[i - 1];
    }
    s->ar[s->top - n + 1] = temp;
}

void downRotate(STACK* s, int n) {
    if (s->top < n - 1) return;

    char temp = s->ar[s->top - n + 1];
    for (int i = s->top - n + 1; i < s->top; i++) {
        s->ar[i] = s->ar[i + 1];
    }
    s->ar[s->top] = temp;
}

void print(STACK* s) {
    for (int i = s->top; i >= 0; i--) 
        printf("%c", s->ar[i]);
    printf("\n");
}

