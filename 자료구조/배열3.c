#include <stdio.h>
#pragma warning(disable:4996)

int main() {
    int n, x[100][100], num = 1;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        if (i == 0) { // ù��° ��
            for (int j = 0; j < n; j++) {
                x[i][j] = num;
                num++;
            }
        }

        else if (i % 2==1&&i!=0) { // Ȧ���� ��
            num += n-1;
            for (int j = 0; j < n; j++) {
                x[i][j] = num;
                num--;
            }
            
        }
        else if(i%2==0 && i != 0){ // ¦���� ��
            num += n+1;
            for (int j = 0; j < n; j++) {
                x[i][j] = num;
                num++;
            }

        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf(" %d", x[i][j]); 
        }
        printf("\n");
    }

    return 0; 
}
