#############하향식##############
#include <stdio.h>

int dp[1500002];
int T[1500002];
int P[1500002];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }

    for (int i = N; i > 0; i--) {
        if (i + T[i] > N + 1) {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = max(dp[i + 1], dp[i + T[i]] + P[i]);
        }
    }

    printf("%d\n", dp[1]);
    return 0;
}

#############상향식##############
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
