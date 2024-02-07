#include <stdio.h>

void swap(int* basket, int a, int b) {
	int temp = basket[a];
	basket[a] = basket[b];
	basket[b] = temp;
}

int main() {
	int basket[101];
	int N, M, a, b;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		basket[i] = i;
	}

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		swap(basket, a, b);
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", basket[i]);
	}
	printf("\n");

	return 0;
}
