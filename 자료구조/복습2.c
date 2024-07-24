#include <stdio.h>
#pragma warning(disable:4996)

void ABC(int k[]) {
    int tmp;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (k[j + 1] > k[j]) {
                tmp = k[j + 1];
                k[j + 1] = k[j];
                k[j] = tmp;
            }
        }
    }
}

int main() {
    int k[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d", &k[i]);
    }

    ABC(k);

    for (int i = 0; i < 10; i++) {
        printf(" %d", k[i]);
    }

    return 0;
}
