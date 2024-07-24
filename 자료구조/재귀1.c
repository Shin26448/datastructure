#include <stdio.h>
#pragma warning(disable:4996)

int sum(int n) {
    //basecase
    if (n == 0) {
        return 0;
    }
    else {
        return n + sum(n - 1);
    }
}
int main() {
    int n, total = 0;

    scanf("%d", &n);
    total = sum(n);
    printf("%d\n", total);

    return 0;
}

