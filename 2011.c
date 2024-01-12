#include <stdio.h>
#include <string.h>

#define MOD 1000000

int dp[5001];
char code[5001];

int fun(int n, int size) {
    if (n >= size)
        return 1;

    int ret = dp[n];
    if (ret != -1) 
        return ret;

    if (code[n] == '0')
        return 0;

    ret = fun(n + 1, size);
    if (n + 1 < size && (code[n] == '1' || (code[n] == '2' && code[n + 1] <= '6'))) {
        ret = (ret + fun(n + 2, size)) % MOD;
    }

    dp[n] = ret;
    return ret;
}

int main() {
    scanf("%s", code);
    memset(dp, -1, sizeof(dp));

    int size = strlen(code);
    printf("%d\n", fun(0, size));

    return 0;
}
