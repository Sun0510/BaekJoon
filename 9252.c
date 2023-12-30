#include <stdio.h>
#include <string.h>

int dp[1001][1001];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char str1[1001] = "";
    char str2[1001] = "";
    char result[1000] = "";

    int len_str1 = 0;
    int len_str2 = 0;
    int index = 0;
    int i = 0, j = 0;

    scanf("%s", str1);
    scanf("%s", str2);

    len_str1 = strlen(str1);
    len_str2 = strlen(str2);

    for (i = 1; i < len_str2 + 1; i++) {
        for (j = 1; j < len_str1 + 1; j++) {
            if (str2[i - 1] == str1[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    i--;
    j--;
    index = dp[i][j] - 1;

    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i - 1][j])
            i--;
        else if (dp[i][j] == dp[i][j - 1])
            j--;
        else {
            i--;
            j--;
            result[index--] = str1[j];
        }
    }

    printf("%d\n", dp[len_str2][len_str1]);
    printf("%s\n", result);

    return 0;
}
