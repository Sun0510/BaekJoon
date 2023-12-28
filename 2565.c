#include <stdio.h>

int numbers[501];
int count[501];

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, st_num, dt_num, max_count = 0;
    int len = 0;
    int temp_max = 0;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &st_num, &dt_num);
        numbers[st_num] = dt_num;

        temp_max = max(st_num, dt_num);
        if (len < temp_max)
            len = temp_max;
    }

    for (int i = 0; i <= len; i++) {
        count[i] = 1;
    }

    for (int i = 2; i <= len; i++) {
        if (numbers[i] == 0)
            continue;
        for (int j = 1; j < i; j++) {
            if (numbers[j] > 0 && numbers[i] > numbers[j]) {
                count[i] = max(count[i], count[j] + 1);
            }
        }
    }

    for (int i = 1; i <= len; i++) {
        max_count = max(max_count, count[i]);
    }
    
    printf("%d\n", n - max_count);
    
    return 0;
}
