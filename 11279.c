#include <stdio.h>

void push(long long heap[], long long x, int index) {
    int temp;
    heap[index] = x;
    while (index != 1) {
        if (heap[index / 2] <= heap[index]) {
            temp = heap[index / 2];
            heap[index / 2] = heap[index];
            heap[index] = temp;
            index /= 2;
        }
        else {
            break;
        }
    }
}

void pull(long long heap[], int index) {
    int temp, i = 1;
    printf("%lld\n", heap[1]);
    heap[1] = heap[index + 1];
    heap[index + 1] = 0;

    while (i <= index) {
        if ((heap[i] < heap[i * 2]) || (heap[i] < heap[i * 2 + 1])) {
            if (heap[i * 2] >= heap[i * 2 + 1]) {
                temp = heap[i * 2];
                heap[i * 2] = heap[i];
                heap[i] = temp;
                i = i * 2;
            }
            else {
                temp = heap[i * 2 + 1];
                heap[i * 2 + 1] = heap[i];
                heap[i] = temp;
                i = i * 2 + 1;
            }
        }
        else {
            break;
        }
    }
}

int main() {
    long long heap[250000];
    long long x;
    int n, index = 0;

    scanf("%d", &n);

    for (int i = 0; i < n + 1; i++) {
        heap[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%lld", &x);
        if (x == 0) {
            if (index == 0) {
                printf("%lld\n", heap[0]);
            }
            else {   
                index--;
                pull(heap, index);
            }
            
        }
        else {
            index++;
            push(heap, x, index);
        }
    }

    return 0;
}
