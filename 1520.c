#include <stdio.h>

int N, M;
int board[500][500];
long long dp[500][500];

long long DFS(int y, int x) {
    if (y == M - 1 && x == N - 1)
        return 1;

    if (dp[y][x] != -1)
        return dp[y][x];

    dp[y][x] = 0;

    int height = board[y][x];

    if (y - 1 >= 0 && board[y - 1][x] < height)
        dp[y][x] += DFS(y - 1, x);

    if (y + 1 < M && board[y + 1][x] < height)
        dp[y][x] += DFS(y + 1, x);

    if (x - 1 >= 0 && board[y][x - 1] < height)
        dp[y][x] += DFS(y, x - 1);

    if (x + 1 < N && board[y][x + 1] < height)
        dp[y][x] += DFS(y, x + 1);

    return dp[y][x];
}

int main() {
    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &board[i][j]);

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;

    printf("%lld\n", DFS(0, 0));
    return 0;
}
