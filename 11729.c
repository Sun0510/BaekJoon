#include <stdio.h>
#include <math.h>

void hanoi(int n, int from, int to) {
    if (n == 0) return;

    int remain = 6 - from - to;

    hanoi(n - 1, from, remain);
    printf("%d %d\n", from, to);
    hanoi(n - 1, remain, to);
}

int main() {
    int n;
    scanf("%d", &n);

    int k = pow(2, n) - 1;
    printf("%d\n", k);
    hanoi(n, 1, 3);

    return 0;
}
