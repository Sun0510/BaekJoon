#include <stdio.h>

int dp[1500500];
int T[1500500];
int P[1500500];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }

    for (int i = 1; i <= N; i++) {
        dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
        dp[i + 1] = max(dp[i], dp[i + 1]);
    }

    printf("%d\n", dp[N + 1]);
    return 0;
}
