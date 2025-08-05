#include <stdio.h>
#include <stdlib.h>

int paper[128][128];
int white, blue;

void cutting(int x, int y, int size) {
    int check, white_parts, blue_parts, half;
    check = 1;
    white_parts = blue_parts = 0;
    if (size == 1) {
        if (paper[y][x] == 0)
            white++;
        else
            blue++;
        return;
    }

    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (paper[i][j] == 0) {
                check = 0;
                white_parts++;
            }
            else
                blue_parts++;
        }
    }

    if (white_parts == size * size) {
        white++;
        return;
    }
    else if (blue_parts == size * size) {
        blue++;
        return;
    }
    half = size / 2;

    if (check == 0) {
        cutting(x, y, half);
        cutting(x + half, y, half);
        cutting(x, y + half, half);
        cutting(x + half, y + half, half);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &paper[i][j]);
        }
    }
    cutting(0, 0, N);

    printf("%d\n%d\n", white, blue);

    return 0;
}
