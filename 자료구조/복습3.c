#include <stdio.h>
#pragma warning (disable:4996)
int swap(int* x, int* y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int N, arr[50], a, b;
    int* p = arr;
    scanf("%d", &N);
    for (p = arr; p < arr + N; p++) {
        scanf("%d", p);
    }
    scanf("%d %d", &a, &b);
    swap(&arr[a], &arr[b]);
    for (p = arr; p < arr + N; p++) {
        printf("%d ", *p);
    }
    return 0;
}