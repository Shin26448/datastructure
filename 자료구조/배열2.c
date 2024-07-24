#include <stdio.h>
#pragma warning(disable:4996)

int main() {
    int n, num, x[100], len, from, to;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        x[i] = num;
    }

    scanf("%d", &len);
    scanf("%d", &from); 

    for (int j = 0; j < len-1; j++) { 
        scanf("%d", &to); 

 

        int tmp = x[from];
        x[from] = x[to];
        x[to] = tmp;

    }
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }

    return 0;
}
