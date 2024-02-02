#include <stdio.h>

int arr[1000000];

int main() {
    int N;
    int min = 1000001, max = -10000001;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    printf("%d %d", min, max);

    return 0;
}
