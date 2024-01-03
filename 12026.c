#include <stdio.h>

char str[1001];
int dp[1001];

int main() {
    int n, index = 0;
    int INF = 1234567890;
    scanf("%d", &n);
    scanf("%s", &str);

    dp[0] = 0;

    for (int i = 1; i < 1001; i++) {
        dp[i] = INF;
    }
    
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (str[i] == 'B' && str[j] == 'O') {
                if (dp[j] > dp[i] + (j - i) * (j - i))
                    dp[j] = dp[i] + (j - i) * (j - i);
            }
            else if (str[i] == 'O' && str[j] == 'J') {
                if (dp[j] > dp[i] + (j - i) * (j - i))
                    dp[j] = dp[i] + (j - i) * (j - i);
            }
            else if (str[i] == 'J' && str[j] == 'B') {
                if (dp[j] > dp[i] + (j - i) * (j - i))
                    dp[j] = dp[i] + (j - i) * (j - i);
            }
            else
                continue;
        }
    }

    if (dp[n - 1] == INF)
        printf("-1\n");
    else
        printf("%d\n", dp[n - 1]);

    return 0;
}
