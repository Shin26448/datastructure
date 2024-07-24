#include <stdio.h>
#pragma warning(disable:4996)

int sum(int n) {
    int all = 0;
    for (int i = 1; i <= n; i++) {
        all += i;
    }
    return all;
}

int main() {
    int n, total = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        total += sum(i);
    }

    printf("%d", total); 
    return 0;
}
