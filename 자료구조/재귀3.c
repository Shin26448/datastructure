#include <stdio.h>
#pragma warning(disable:4996)

void print(int n) {
    if (n == 0)
        return 0;
    printf("%d\n", n % 10);
    print(n / 10);

}
int main() {
    int n;

    scanf("%d", &n);
    print(n);

    return 0;
}


