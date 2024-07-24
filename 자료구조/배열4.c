#include <stdio.h>
#pragma warning(disable:4996)


int main() {
    int n, m, x[100][100];
    int num = 1;
    int i = 0, j = 0;

    scanf("%d %d", &n, &m);

    int nstart = 0;
    int mstart = 0;
    int nend = n - 1;
    int mend = m - 1;

    while (nstart <= nend && mstart <= mend) {
        for (j = mstart; j <= mend; j++) {
            x[nstart][j] = num++;
        }
        nstart++;

        for (i = nstart; i <= nend; i++) {
            x[i][mend] = num++;
        }
        mend--;

        if (nstart <= nend) {
            for (j = mend; j >= mstart; j--) {
                x[nend][j] = num++;
            }
            nend--;
        }

        if (mstart <= mend) {
            for (i = nend; i >= nstart; i--) {
                x[i][mstart] = num++;
            }
            mstart++;
        }
    }


    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf(" %d", x[i][j]);
        }
        printf("\n");
    }

    return 0;
}
