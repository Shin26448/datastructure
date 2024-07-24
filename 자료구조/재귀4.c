#include <stdio.h>
#pragma warning(disable:4996)

int max(int a[], int n) {
    if (n == 1)
        return a[0];

    int last = max(a, n - 1);

    if (a[n - 1] > last) {
        return a[n - 1];
    }
    else {
        return last;
    }
}

int main() {
    int n, a[20], answer;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    answer = max(a, n);

    printf("%d", answer);

    return 0;
}
