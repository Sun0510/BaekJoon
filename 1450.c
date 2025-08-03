#include <stdio.h>
#include <stdlib.h>

long long things[30];
long long data1[40000];
long long data2[40000];
int idx1, idx2;

void sub_set_sum(long long* data, int* idx, long long C, int start, int end, long long sum) {
    if (start >= end) {
        data[(*idx)++] = sum;
        return;
    }
        
    sub_set_sum(data, idx, C, start + 1, end, sum);
    sub_set_sum(data, idx, C, start + 1, end, things[start] + sum);
}

int main() {
    long long C, cnt;
    int N, i, j;

    scanf("%d %lld", &N, &C);

    cnt = 0;

    for (i = 0; i < N; i++) {
        scanf("%lld", &things[i]);
    }

    sub_set_sum(data1, &idx1, C, 0, N / 2, 0);
    sub_set_sum(data2, &idx2, C, N / 2, N, 0);

    for (i = 0; i < idx1; i++) {
        for (j = 0; j < idx2; j++) {
            if (data1[i] + data2[j] <= C)
                cnt++;
        }
    }

    printf("%lld\n", cnt);

    return 0;
}
