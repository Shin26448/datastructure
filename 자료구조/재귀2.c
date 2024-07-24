#include <stdio.h>
#pragma warning(disable:4996)

void print(int n) {
    //basecase
    if (n == 0)
        return 0;
    print(n / 10);
    printf("%d\n", n % 10);
}
int main() {
    int n;

    scanf("%d", &n);
    print(n);