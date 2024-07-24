#include <stdio.h>
#pragma warning(disable:4996)


int main() {
    int n, m, x[100][100], num = 1;
    int i = 0, j = 0;

    scanf("%d %d", &n, &m);

    for (j = 0; j < m; j++) {
        int mcount = j;
        int ncount = 0;
        while (ncount < n && mcount >= 0) {
            x[ncount][mcount] = num;
            num++;
            ncount++;
            mcount--;
        }
    }

    for (i = 1; i < n; i++) {
        int mcount = m - 1;
        int ncount = i;
        while (ncount < n && mcount >= 0) {
            x[ncount][mcount] = num;
            num++;
            ncount++;
            mcount--;
        }
    }


    // 출력부분
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf(" %d", x[i][j]);
        }
        printf("\n");
    }

    return 0;
}
