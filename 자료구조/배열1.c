#include <stdio.h>
#pragma warning (disable:4996)


int main() {
    int n, num, x[100], renum, a, b, re[100];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        x[i] = num;
    }

    scanf("%d", &renum);

    for (int i = 0; i < renum; i++) {
        scanf("%d %d", &a, &b);

        int k = 0;
        for (int j = a; j <= b; j++) {
            re[j] = x[b - k];
            k++;
        }

        for (int j = 0; j < a; j++) {
            re[j] = x[j];
        }
        for (int j = b + 1; j < n; j++) {
            re[j] = x[j];
        }

        
        for (int j = 0; j < n; j++) {
            x[j] = re[j];
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", re[i]);
    }

    return 0;
}
