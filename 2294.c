#include <stdio.h>

int coins[100];
int total[100001];

int main() {
    int n, k, coin;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    for (int j = 1; j <= k; j++) {
        total[j] = 999999;
    }

    for (int j = 1; j <= k; j++) {
        for (int i = 0; i < n; i++) {
            if (coins[i] <= j && total[j - coins[i]] + 1 < total[j]) {
                total[j] = total[j - coins[i]] + 1;
            }
        }
    }
    if (total[k] == 999999)
        printf("-1\n");
    else
        printf("%d\n", total[k]);
    
    return 0;
}
